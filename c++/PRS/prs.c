/* 分页虚拟内存置换模拟器  */
/* author: zjz         */
/* created: 2025-05-16 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

/* ---------- 参数区 ---------- */
#define PAGE_SIZE          1024 
#define LOGIC_PAGE_NUM     10
#define MAX_FRAMES         9       
#define MAX_SEQ_LEN        50
#define DLEN               10
/* ---------------------------- */

typedef struct {
    uint8_t frame;              /* 物理帧号 */
    bool    valid;              /* 有效位 */
    bool    dirty;              /* 脏位 */                
    bool    referenced;         /* 引用位 */
    int     lastUseIdx;         /* 最近使用索引 */
} PageTableEntry;

typedef struct {
    uint8_t data[PAGE_SIZE];
} Frame;

typedef enum { ALG_FIFO, ALG_LRU, ALG_CLOCK, ALG_OPT } AlgTag;

typedef struct {            
    AlgTag alg;
    int    pageFaults;
    double eat_ns;
} Stat;

/* ----------- 全局 ----------- */
PageTableEntry pageTable[LOGIC_PAGE_NUM];              /* 页表 */
Frame          frames[MAX_FRAMES];                     /* 物理帧数组 */  
int            frameCount;                             /* 分配给进程的物理帧数 */
int            freeFrameTop = 0;                       /* 简单空闲栈 */
int            backfd;                                 /* back.bin 文件描述符 */
int            refSeq[MAX_SEQ_LEN];                    /* 引用串 */
int            refLen;                                 /* 引用串长度 */
int            fifoQueue[MAX_FRAMES];                  /* 存储逻辑页号 */ 
int            fifoFront = 0;                          /* FIFO 队首指针 */
int            fifoRear = 0;                           /* FIFO 队尾指针 */
int            fifoPageCount = 0;                      /* FIFO 队列中当前实际的页面数量 */
int            clockHand = 0;                          /* CLOCK */
double         mem_access_time = 100;                  /* 内存访问时间 */
double         pagefault_time = 20.0 * 1e6;            /* 页错误处理时间 */
bool           zero_backfd[LOGIC_PAGE_NUM][PAGE_SIZE]; /* 记录 back.bin 中每页中修改 */

/* ---------- 生成引用串 ---------- */
void generatePageSequence() {
    printf("生成的页面引用序列 (长度 %d): ", refLen);
    for(int i = 0;i < refLen; i ++ ) { 
        refSeq[i] = rand() % LOGIC_PAGE_NUM; 
        printf("%d ", refSeq[i]);
    }
    printf("\n\n");
}

/* ---------- 预设引用串测试 ---------- */
void testPageSequence() {
    printf("使用预设的页面引用序列进行测试...\n");
    /* 测试序列 */ 
    int test_seq[] = {0, 1, 2, 3, 0, 1, 4, 0, 1, 2, 3, 4};
    // int test_seq[] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
    frameCount = 3; /* 预设长度 */ 
    refLen = sizeof(test_seq) / sizeof(int); /* 自动获取长度 */ 
    memcpy(refSeq, test_seq, sizeof(test_seq));
    printf("预设分配给进程的物理帧数：%d", frameCount);
    printf("页面引用序列 (长度 %d): ", refLen);
    for(int i = 0; i < refLen; i++) {
        printf("%d ", refSeq[i]);
    }
    printf("\n\n");
}

/* ---------- 获取一个空闲物理帧 ---------- */
int getFreeFrame() {
    if (freeFrameTop < frameCount) return freeFrameTop ++ ;
    return -1;
}

/* ---------- 先进先出置换算法 FIFO ---------- */
int selectVictim_FIFO() {
    int victim = fifoQueue[fifoFront];
    fifoQueue[fifoFront] = -1;
    fifoFront = (fifoFront + 1) % frameCount;
    fifoPageCount -- ;
    return victim;
}

/* ---------- 最近最久未使用算法 LRU ---------- */
int selectVictim_LRU() {
    int minIdx = -1, victim = -1;
    for(int p = 0; p < LOGIC_PAGE_NUM; p ++ )
        if(pageTable[p].valid) {
            if(minIdx == -1 || pageTable[p].lastUseIdx < minIdx) {
                minIdx = pageTable[p].lastUseIdx; victim = p;
            }
        }
    return victim;
}

/* ---------- 置换算法 Clock ---------- */
int selectVictim_CLOCK() {
    while(true) {
        for(int p = 0; p < LOGIC_PAGE_NUM; p ++ ) {
            if(pageTable[p].valid && pageTable[p].frame == clockHand) {
                if(pageTable[p].referenced) {
                    pageTable[p].referenced = false;
                } else {
                    int victim = p; clockHand = (clockHand + 1) % frameCount; 
                    return victim;
                }
                break;
            }
        }
        clockHand = (clockHand + 1) % frameCount;
    }
}

/* ---------- OPT 算法的辅助函数 ---------- */
int nextUseIdx(int currentPos,int page) {
    for(int i = currentPos + 1; i < refLen; i ++ )
        if(refSeq[i] == page) return i;
    return MAX_SEQ_LEN + 1; /* ∞ */
}

/* ---------- 最佳置换算法 OPT ---------- */
int selectVictim_OPT(int curPos) {
    int farthest = -1, victim = -1;
    for(int p = 0; p < LOGIC_PAGE_NUM; p ++ )
        if(pageTable[p].valid) {
            int idx = nextUseIdx(curPos, p);
            if(idx > farthest){
                farthest = idx; victim = p;
            }
        }
    return victim;
}

/* 可视化当前物理帧状态 */
void printCurrentFrames() {
    printf("当前物理帧状态: [ ");
    for (int i = 0; i < frameCount; i ++ ) {
        bool frameOccupied = false;
        for (int p = 0; p < LOGIC_PAGE_NUM; p ++ ) {
            if (pageTable[p].valid && pageTable[p].frame == i) {
                printf("%d:P%d ", i, p);
                frameOccupied = true;
                break;
            }
        }
        if (!frameOccupied) {
            printf("%d:Empty ", i);
        }
    }
    printf("]\n");
}

/* ---------- 清空环境 ---------- */
void reset() {
    uint8_t tmp[PAGE_SIZE];
    memset(tmp, 0xFF, PAGE_SIZE);
    lseek(backfd, 0, SEEK_SET); 
    for (int i = 0; i < LOGIC_PAGE_NUM; i++) {
        write(backfd, tmp, PAGE_SIZE);
    }
    for (int i = 0; i < LOGIC_PAGE_NUM; ++i) {
        pageTable[i] = (PageTableEntry){0, false, false, false, 0};
    }
    freeFrameTop = clockHand = 0;
    fifoFront = fifoRear = fifoPageCount = 0; 
    for (int i = 0; i < frameCount; i++) {
        fifoQueue[i] = -1; 
    }
    memset(zero_backfd, false, sizeof(zero_backfd));
}

/* ---------- 备份读写 ---------- */
void readPage(int page,int frame) {
    lseek(backfd, page * PAGE_SIZE, SEEK_SET);
    read(backfd, frames[frame].data, PAGE_SIZE);
}
void writePage(int page) {
    lseek(backfd, page * PAGE_SIZE, SEEK_SET);
    write(backfd, frames[pageTable[page].frame].data, PAGE_SIZE);

    for (int k = 0; k < PAGE_SIZE; k++) {
        if (frames[pageTable[page].frame].data[k] == 0x00) {
            zero_backfd[page][k] = true;
        } else {
            zero_backfd[page][k] = false;
        }
    }
}

/* ---------- 缺页处理 ---------- */
void pageFault(int logicalPage, AlgTag alg, int curPos, int offset) {
    printf("! 缺页: 逻辑页 P%d\n", logicalPage);

    int frame = getFreeFrame();
    int victimPage = -1;
    
    /* 无空闲帧 */
    if(frame == -1) {
        /* 选择牺牲页 */
        switch(alg) {
            case ALG_FIFO:  victimPage = selectVictim_FIFO();      break;
            case ALG_LRU:   victimPage = selectVictim_LRU();       break;
            case ALG_CLOCK: victimPage = selectVictim_CLOCK();     break;
            case ALG_OPT:   victimPage = selectVictim_OPT(curPos); break;
        }
        frame = pageTable[victimPage].frame;
        printf("  -> 无空闲帧，选择牺牲页 P%d (原在物理地址 F%d)", victimPage, frame * PAGE_SIZE + offset);
        if(pageTable[victimPage].dirty) {
            writePage(victimPage);
            printf("，该页为脏页，已写回 back.bin");
        }
        pageTable[victimPage] = (PageTableEntry){0, false, false, false, 0};
        printf("\n");
    } else { /* 有空闲帧 */
        printf("  -> 分配空闲物理地址 F%d\n", frame * PAGE_SIZE + offset);
    }

    /* 装入新页 */
    printf("  -> 调入逻辑页 P%d 到物理地址 F%d\n", logicalPage, frame * PAGE_SIZE + offset);
    readPage(logicalPage, frame);
    pageTable[logicalPage] = (PageTableEntry){(uint8_t)frame, true, false, false, curPos};
    
    if (alg == ALG_FIFO) {
        fifoQueue[fifoRear] = logicalPage;
        fifoRear = (fifoRear + 1) % frameCount;
        fifoPageCount ++ ;
    }

    printCurrentFrames();
}

/* ---------- translate ---------- */
void translate(int laddr, bool isWrite, AlgTag alg, int curPos, Stat* st) {
    int offset = laddr & (PAGE_SIZE - 1);  /* 帧号：逻辑地址的低10位 */
    int page = laddr >> DLEN;              /* 页号：逻辑地址右移10位 */

    printf("\n---> [%d] 访问逻辑地址 0x%X (页 P%d, 偏移 0x%X), 操作: %s\n",
        curPos, laddr, page, offset, isWrite ? "写" : "读");

    if (page < 0 || page >= LOGIC_PAGE_NUM) {
        printf("!!! 错误: 逻辑页号 P%d 超出范围 (0-%d).\n", page, LOGIC_PAGE_NUM - 1);
        return ;
    }

    if(!pageTable[page].valid) {  /* 缺页 */   
        st->pageFaults ++ ;
        pageFault(page, alg, curPos, offset);
    } else {                      /* 命中 */
        printf("  * 命中! 逻辑页 P%d 在物理地址 F%d.\n", page, pageTable[page].frame * PAGE_SIZE + offset);
        printCurrentFrames();
    }
    pageTable[page].referenced = true;
    pageTable[page].lastUseIdx = curPos;

    if(isWrite) {
        if(!pageTable[page].dirty){
            printf("  -> 对页 P%d 进行写操作，设置脏位.\n", page);
        }
        pageTable[page].dirty = true;
        if (offset < PAGE_SIZE) {
            frames[pageTable[page].frame].data[offset] = 0x00; /* 模拟写操作 */ 
            printf("     内存中 F%d[字节偏移 %d] 被修改为 0x00.\n", pageTable[page].frame, offset);
        } else {
            printf("!!! 错误: 页内偏移 0x%X 超出范围.\n", offset);
            return;
        }
    }
}

void check_backfd() {
    printf("\n=========================================================\n");
    printf("验证 back.bin 修改\n");
    printf("=========================================================\n");
    
    int correct_pages = 0; /* 记录完全正确的页面数 */ 
    int checked_pages = 0; /* 记录总共检查的页面数 */ 

    for (int p = 0; p < LOGIC_PAGE_NUM; p ++ ) {
        uint8_t buffer[PAGE_SIZE];
        off_t offset = (off_t)p * PAGE_SIZE;
        bool ac = true; // 标记当前页面是否所有字节都符合预期

        checked_pages ++ ;
        lseek(backfd, offset, SEEK_SET);
        ssize_t bytes_read = read(backfd, buffer, PAGE_SIZE);

        for (int k = 0; k < PAGE_SIZE; k ++ ) {
            uint8_t cur_val = buffer[k];
            bool zero = zero_backfd[p][k];
            uint8_t exp_val = zero ? 0x00 : 0xFF;

            if (cur_val != exp_val) {
                ac = false;
                printf("  错误: 逻辑页 P%d, 字节偏移 %d: 期望值 0x%02X, 实际值 0x%02X\n",
                    p, k, exp_val, cur_val);
            } else if(cur_val == exp_val && exp_val == 0x00) {
                printf("  正确写回: 逻辑页 P%d, 字节偏移 %d: 期望值 0x%02X, 实际值 0x%02X\n",
                    p, k, exp_val, cur_val);
            }
        }
        if (ac) {
            printf("逻辑页 P%d: 所有字节检查通过.\n", p);
            correct_pages ++ ;
        } else {
            printf("逻辑页 P%d: 存在字节与期望值不符.\n",p);
        }
    }
    printf("---------------------------------------------------------\n");
    printf("自动检查完成: %d / %d 页符合记录.\n", correct_pages, checked_pages);
    printf("=========================================================\n\n");
}

/* ---------- 主流程 ---------- */
int main() {
    srand((unsigned)time(NULL));
    /* 初始化后备存储 */
    backfd = open("back.bin", O_RDWR | O_CREAT, 0644);
    uint8_t tmp[PAGE_SIZE];
    memset(tmp, 0xFF, PAGE_SIZE);
    for(int i = 0; i < LOGIC_PAGE_NUM; i ++ ) {
        write(backfd, tmp, PAGE_SIZE);
    }

    /* 用户输入 */
    // printf("分配给进程的物理帧数(1~9)：");  scanf("%d",&frameCount);
    // printf("生成引用串长度(20~50)：");     scanf("%d",&refLen);
    // getchar();
    printf("选择算法(F/L/C/O 或多选如 F,L,O)：");
    char line[32]; fgets(line, 32, stdin);
    
    /* 引用串生成 */
    // generatePageSequence();
    testPageSequence();

    /* 逐算法仿真 */
    const char* names[] = {"FIFO", "LRU", "CLOCK", "OPT"};
    Stat results[4]; int resCnt = 0;

    for(char* p = strtok(line, ","); p; p = strtok(NULL,",")) {
        AlgTag alg;
        if(*p == 'F'|| *p == 'f')       alg = ALG_FIFO;
        else if(*p == 'L' || *p == 'l') alg = ALG_LRU;
        else if(*p == 'C' || *p == 'c') alg = ALG_CLOCK;
        else if(*p == 'O' || *p == 'o') alg = ALG_OPT;
        else continue;

        printf("=========================================================\n");
        printf("开始模拟算法: %s\n", names[alg]);
        printf("分配物理帧数: %d\n", frameCount);
        printf("页面引用序列 (长度 %d): ", refLen);
        for(int i = 0; i < refLen; i++) {
            printf("%d ", refSeq[i]);
        }
        printf("\n");
        printf("=========================================================\n");

        /* 清空环境 */
        reset();

        Stat st = {alg, 0, 0};
        for(int i = 0; i< refLen; i ++ ) {
            
            /* 随机读写 */
            bool isWrite = rand() % 2;

            /* 随机产生页偏移 */
            int page_num = refSeq[i];                    
            int random_offset = rand() % PAGE_SIZE;       
            int logical_address = page_num * PAGE_SIZE + random_offset;

            translate(logical_address, isWrite, alg, i, &st);
        }
        
        check_backfd();

        double pr = st.pageFaults * 1.0 / refLen;   
        st.eat_ns = (1 - pr) * mem_access_time + pr * pagefault_time; /* EAT = (1 - p) * m_t + p * pf_t */
        results[resCnt ++ ] = st;
    }

    /* 打印结果 */
    printf("\n算法  缺页次数  缺页率  EAT(ns)\n");
    for(int i = 0; i < resCnt; i ++ ) {
        printf("%-5s %-8d %.2f    %.0f\n",
            names[results[i].alg],
            results[i].pageFaults,
            results[i].pageFaults * 1.0 / refLen,
            results[i].eat_ns);
    }
    close(backfd);
    return 0;
}