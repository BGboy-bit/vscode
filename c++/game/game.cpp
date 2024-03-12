/**************/
/*****剑来*****/
/*************/

//作者：zjz
//开始制作日期：2023.4.20
//结束制作日期：

/*******************************/
/*随时把代码备份至game1,game2！！！*/
/******************************/



//补丁：1.0 去掉#include<bits/stdc++.h>改为c库头         (vitual studio不兼容#include<bits/stdc++.h>)    2023.4.20
//补丁：1.1 将fflush(stdin)改为rewind(stdin)                      (vitual studio不兼容fflush(stdin))    2023.4.40
//补丁：1.2 将vscode编码方式改为GB2312                               (UTF-8不兼容中文字体，会出现中文乱码)    2024.4.20


//更新日志：

//task:将所有函数放在开头并分类
//task:继续完善FirstRound()
//task:完成经验系统的制作
//task:完成人物属性随机生成算法//task:在开始界面添加继续修仙，并将mid菜单的”返回人间“改为”返回主菜单“；
//task:编写自己的头文件，将各个板块再细分出去
//task:完成SecondRound()与ThirdRound()的制作
//task:完成背包系统，武器系统，怪物爆率系统的制作
//task:完成技能树系统制作


#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct Character {   
    int HP,MP;//血量 蓝量
    int ATK,DEF;//攻击力 防御力
    char Name[100];
    int Class;
    int Level;
    char weapon[100];//武器系统尽情期待
};

Character Player,CntPlayer;

const int MAXMAP = 3,MAXBoss = 3;
const char* Master = "zjz";
bool f = 1;//记录第一次输出是否为直接退出
bool g = 1;//记录是否有记录过人物的数值
bool h = 1;//记录是否有记录过怪物的数值
bool ris[MAXMAP + 1];//记录关卡是否已经通关
int cnt[MAXMAP + 1];//记录来这关的次数
char s[MAXMAP + 1][100] = {{},{"走出泥瓶巷"}, {"磨砺身心"}, {"拯救苍生"}};

struct Boss {
    int HP,ATK;
    char Name[100];
    char Talent[100];
    int exp;
};

Boss boss[MAXBoss + 1] = {{},{10,1,"蔡金简",""},{20,3,"搬山猿",""},{40,7,"离真",""}};
Boss Cntboss;

void EnterQuit() {//输入回车退出并且清空屏幕
    char c;
    rewind(stdin);//清空缓冲区内容
    scanf("%c",&c);
    system("cls");//清空控制台内容
}

int Query() {
    system("cls");//清空控制台内容
    printf("*------------------>剑来<----------------------*\n\n");
    printf("是否要跳过剧情？\n");
    printf("1.跳!我的时间很宝贵的懂不懂啊!\n");
    printf("2.不跳,这剧情写的这么好我必须得好好品味一下(剑来真的很好看的!我写的纯瞎扯淡).\n");
    printf("请做出你的选择：");
    rewind(stdin);//清空缓冲区内容
    int x;
    scanf("%d",&x);
    system("cls");//清空控制台内容
    if(x == 2) return 1;
    else return 0;
}

void ShowIntrChar() {//介绍人物
    system("cls");//清空控制台内容
    printf("*------------------>剑来<----------------------*\n\n");
    printf("【道士】\n");
    printf("天下多数人属于此列,优点是会仙术,可以使用法器,且境界提升快,缺点是提不起刀剑,且血很薄.\n\n");
    printf("【纯粹武夫】\n");
    printf("成为武夫很累,需千锤百炼,所以很肉,皮很厚,纯粹两字更难得,但无法使用仙术与兵器,“拿拳头说话,拳头硬的道理才大”.\n\n");
    printf("【剑修】\n");
    printf("帅。但对天赋的要求很高,没有本命飞剑就很难在剑修这条路上走远.\n\n");
    printf("按下回车退出");
    EnterQuit();
}

void ShowCharacter(int x) {
    if(x == 0)  {
        printf("%s\n血量: %d  蓝量: %d  攻击力: %d  防御力: %d\n\n",Player.Name,Player.HP,Player.MP,Player.ATK,Player.DEF);
        if(g) {
            CntPlayer = Player;
            g = 0;
        }
    }
    else {
        printf("%s\n血量: %d  攻击力: %d\n\n",boss[x].Name,boss[x].HP,boss[x].ATK);
        if(h) {
            Cntboss = boss[x];
            h = 0;
        }
    }
}

void PrintLevel() {//打印境界
    if(Player.Class >= 2) {
        switch(Player.Level) {
            case 1: printf("境界:【铜皮境】\n"); break;
            case 2: printf("境界:【草根境】\n"); break;
            case 3: printf("境界:【柳筋境】\n"); break;
            case 4: printf("境界:【骨气境】\n"); break;
            case 5: printf("境界:【筑庐境】\n"); break;
            case 6: printf("境界:【洞府境】\n"); break;
            case 7: printf("境界:【观海境】\n"); break;
            case 8: printf("境界:【龙门境】\n"); break;
            case 9: printf("境界:【金丹境】\n"); break;
            case 10: printf("境界:【元婴境】\n"); break;
            case 11: printf("境界: 【玉璞境】\n"); break;
            case 12: printf("境界: 【仙人境】\n"); break;
            case 13: printf("境界: 【飞升境】\n"); break;
            case 14: printf("境界: 【合道天地】\n"); break;
            case 15: printf("境界: 【? ? ?】\n"); break;
        }
    }
    else {
        switch(Player.Level) {
            case 1: printf("境界:【泥胚境】\n"); break;
            case 2: printf("境界:【木胎境】\n"); break;
            case 3: printf("境界:【水银境】\n"); break;
            case 4: printf("境界:【英魂境】\n"); break;
            case 5: printf("境界:【雄魄境】\n"); break;
            case 6: printf("境界:【武胆境】\n"); break;
            case 7: printf("境界:【金身境】\n"); break;
            case 8: printf("境界:【羽化境】\n"); break;
            case 9: printf("境界:【山巅境】\n"); break;
            case 10: printf("境界:【止境·气盛境】\n"); break;
            case 11: printf("境界:【止境·归真境】\n"); break;
            case 12: printf("境界:【止境·神到境】\n"); break;
            case 13: printf("境界: 【武神境】\n"); break;
        }
    }
}

void Warrior() {//纯粹武夫
    system("cls");//清空控制台内容
    printf("*------------------>剑来<----------------------*\n\n");
    Player.Class = 1;
    Player.HP = 10;
    Player.MP = 0;
    Player.ATK = 5;
    Player.DEF = 8;
    Player.Level = 1;
    printf("您的属性已生成!\n");
    printf("角色: 纯粹武夫  HP:%d  MP:%d  ATK:%d DEF:%d\n",Player.HP,Player.MP,Player.ATK,Player.DEF);
    printf("按下回车继续");
    EnterQuit();
}

void Swordsman() {//剑修
    system("cls");//清空控制台内容
    printf("*------------------>剑来<----------------------*\n\n");
    Player.Class = 2;
    Player.HP = 1;
    Player.MP = 5;
    Player.ATK = 1;
    Player.DEF = 1;
    Player.Level = 1;
    printf("您的属性已生成!\n");
    printf("角色: 剑修  HP:%d  MP:%d  ATK:%d DEF:%d\n",Player.HP,Player.MP,Player.ATK,Player.DEF);
    printf("按下回车继续");
    EnterQuit();
}

void Monk() {//练气士
    system("cls");//清空控制台内容
    printf("*------------------>剑来<----------------------*\n\n");
    Player.Class = 3;
    Player.HP = 3;
    Player.MP = 10;
    Player.ATK = 2;
    Player.DEF = 2;
    Player.Level = 1;
    printf("您的属性已生成!\n");
    printf("角色: 练气士  HP:%d  MP:%d  ATK:%d DEF:%d\n",Player.HP,Player.MP,Player.ATK,Player.DEF);
    printf("按下回车继续");
    EnterQuit();
}

void MAster() {
    for(int i = 1; i <= MAXMAP; i ++) {
        ris[i] = 1;
        cnt[i] = 1;
    }
    Player.ATK = 999;
    Player.DEF = 999;
    Player.HP = 999;
    Player.MP = 999;
    if(Player.Class == 1) Player.Level = 13;
    else Player.Level = 15;
}

void Start() {//开始界面
    printf("*------------------>剑来<----------------------*\n");
    printf("*    欢迎来到zjz的修仙世界,预祝各位玩的开心    *\n");
    printf("*                                              *\n");
    printf("*         大千世界 无奇不有 天道崩塌           *\n"); 
    printf("*             我陈平安 唯有一剑                *\n");
    printf("*可搬山 断江 倒海 降妖 镇魔 敕神 摘星 摧城 开天*\n");
    printf("*    我叫陈平安 平平安安的平安 我是一名剑客    *\n");
    printf("*                                              *\n");
    printf("*            按下数字键开始修仙之旅！          *\n");
    printf("*                1.开始修仙！                  *\n");
    printf("*                2.查看所有武器                *\n");
    printf("*                3.查看boss爆率                *\n");
    printf("*                4.返回凡间。                  *\n");    
    printf("*                                              *\n");    
    printf("*      原著：《剑来》    作者：烽火戏诸侯      *\n");
    printf("*           游戏作者: zjz(已证天道)            *\n");
    printf("************************************************\n"); 
}

void HandleName() {//取名
    printf("*------------------>剑来<----------------------*\n\n");
    char name[100];
    printf("请输入您的尊讳：");
    rewind(stdin);//清空缓冲区内容
    scanf("%s",name);
    strcpy(Player.Name,name);
    if(strcmp(Player.Name,Master) == 0) {
        MAster();
    }
}

void ShowPanel() {//展示属性版
    system("cls");//清空控制台内容
    printf("*------------------>剑来<----------------------*\n\n");
    printf("===========================\n");
    switch(Player.Class) {
        case 1: printf("*         纯粹武夫        *\n"); break;
        case 2: printf("*          剑修           *\n"); break;
        case 3: printf("*          练气士         *\n"); break;
    }
    printf("尊讳:%s\n",Player.Name);
    printf("血量:%d\n",Player.HP);
    printf("蓝量:%d\n",Player.MP);
    printf("攻击力:%d\n",Player.ATK);
    printf("防御力:%d\n",Player.DEF);
    //printf("Level:%d\n",Player.Level);
    PrintLevel();
    printf("===========================\n");
    printf("按下回车继续");
    EnterQuit();
}

void ChooseCharacter() {//选取角色
    system("cls");//清空控制台内容
    printf("*------------------>剑来<----------------------*\n\n");
    printf("1.纯粹武夫 2.剑修 3.练气士 4.角色介绍\n");
    char c;
    printf("请选择角色：");
    rewind(stdin);//清空缓冲区内容
    scanf("%c",&c);
    switch(c) {
        case'1': Warrior(); break;
        case'2': Swordsman(); break;
        case'3': Monk(); break;
        case'4': ShowIntrChar(); ChooseCharacter();break;
    }
    HandleName();
    ShowPanel();
    printf("*------------------>剑来<----------------------*\n\n");
    if(strcmp(Player.Name,Master) == 0) {
        printf("欢迎回来,主人\n");
    }
    else {
        printf("欢迎少侠 %s 来到zjz的修仙世界,准备好开启你的修仙生活了吗?\n\n",Player.Name);
        printf("1.等不及了搞快点!  2.我要回炉重塑,TMD这属性是人玩的吗!\n");
        printf("请选择：");
        int x;
        scanf("%d",&x);
        if(x == 2) ChooseCharacter();
    }
}

void PrintTable() {
    system("cls");//清空控制台内容
    printf("*------------------>剑来<----------------------*\n\n");
    printf("*------------------------------*\n");
    printf("|         ===||======>         |\n");
    printf("*------------------------------*\n");
    printf("|                              |\n");
    printf("|         1.地图               |\n");
    printf("|         2.查看人物面板       |\n");
    printf("|         3.背包               |\n");
    printf("|         4.技能树             |\n");
    printf("|         5.返回人界           |\n");
    printf("|                              |\n");
    printf("*------------------------------*\n");
}

void ShowMap() {
    printf("目录\n");
     printf("======================\n");
    for(int i = 1; i <= MAXMAP; i ++) {
        printf("第%d关: ",i);
        if(ris[i - 1]) printf("%s\n",s[i]);
        else printf("? ? ?\n");
    }
    printf("\n");
    printf("%d.返回菜单\n",MAXMAP + 1);
    printf("======================\n\n");
}

void FirstActor() {
    printf("第一章————走出泥腿巷\n");
    printf("按下回车继续"); EnterQuit();
    printf("*------------------>剑来<----------------------*\n\n");
    printf("你原本是泥腿巷普通的一介草民,但在你5岁时,有人让你的父亲知道了小镇的秘密,就打碎了你的本命瓷,父母因受反噬双双离世,你的父亲是被人（马婆婆的儿子,马苦玄的父亲）害死,你的母亲病重而死...\n");
    printf("你本命瓷被打碎后,如黑暗中的萤火,小镇的机缘纷纷向你涌来,但却留不住...\n");
    printf("按下回车继续"); EnterQuit();
    printf("*------------------>剑来<----------------------*\n\n");
    printf("十四岁那年,小镇发生的事彻底颠覆了你对这个世界的看法...\n");
    printf("按下回车继续"); EnterQuit();
    printf("*------------------>剑来<----------------------*\n\n");
    printf("骊珠洞天(即泥腿巷)在那天向外乡人敞开了怀抱,虽然还有大道的压制,但欺负像你这样的普通人还是轻轻松松,你的长生桥就被被蔡金简打碎,让本来羸弱的你更加不堪...\n");
    printf("按下回车继续"); EnterQuit();
    printf("*------------------>剑来<----------------------*\n\n");
}

void FirstRound() {
    system("cls");//清空控制台内容
    printf("*------------------>剑来<----------------------*\n\n");
    g = 1; h = 1;
    // cnt[1] ++;//测试专用
    if(cnt[1] ++ == 0) FirstActor();
    else {
        if(Query()) {
            printf("*------------------>剑来<----------------------*\n\n");
            FirstActor(); 
        }
    }
    printf("对战boss————%s\n\n",boss[1].Name);
    ShowCharacter(0); ShowCharacter(1);

}

void SecondRound() {
    system("cls");//清空控制台内容
    printf("*------------------>剑来<----------------------*\n\n");
    g = 1; h = 1;
    if(ris[1]) {
        printf("敬请期待\n");
    }
    else {
        printf("少侠，请先完成前面的关卡\n");
    }
}

void ThirdRound() {
    system("cls");//清空控制台内容
    printf("*------------------>剑来<----------------------*\n\n");
    g = 1; h = 1;
    if(ris[2]) {
        printf("敬请期待\n");
    }
    else {
        printf("少侠，请先完成前面的关卡\n");
    }
}


void Map() {
    system("cls");//清空控制台内容
    printf("*------------------>剑来<----------------------*\n\n");
    ShowMap();
    printf("请做出你的选择: ");
    rewind(stdin);//清空缓冲区内容
    int x;
    scanf("%d",&x);
    switch(x) {
        case 1: FirstRound(); break;
        case 2: SecondRound(); break;
        case 3: ThirdRound(); break;
        default: break;
    }
    printf("按下回车继续");
    EnterQuit();
}

void ShowBackpack() {

}

void Backpack() {
    system("cls");//清空控制台内容
    printf("*------------------>剑来<----------------------*\n\n");
    ShowBackpack();
    printf("敬请期待\n");
    printf("按下回车继续");
    EnterQuit();
}

void ShowTalentTree() {
    
}

void TalentTree() {
    system("cls");//清空控制台内容
    printf("*------------------>剑来<----------------------*\n\n");
    ShowTalentTree();
    printf("敬请期待\n");
    printf("按下回车继续");
    EnterQuit();
}

void MidHandle() {
    char handle;
    ris[0] = 1;//让第一关可见
    while(1) {
        PrintTable();
        printf("请输入：");
        scanf("%c",&handle);
        switch(handle) {
            case'1': Map(); break;
            case'2': ShowPanel(); break;
            case'3': Backpack(); break;
            case'4': TalentTree(); break; 
            default: return; break;          
        }
    }
}

void ShowProbability() {//查看boss爆率
    system("cls");//清空控制台内容
    printf("*------------------>剑来<----------------------*\n\n");
    printf("尽情期待\n");
    printf("按下回车返回开始界面");
    EnterQuit();
}

void ShowWeapon() {//查看所有武器
    system("cls");//清空控制台内容
    printf("*------------------>剑来<----------------------*\n\n");
    printf("尽情期待\n");
    printf("按下回车返回开始界面");
    EnterQuit();
}

void SayGoodbye() {
    system("cls");//清空控制台内容
    printf("*------------------>剑来<----------------------*\n\n");
    printf("修仙之旅到此就结束啦,但人生的旅程还在继续.让我们珍惜每一天,活在当下,创造属于自己的精彩人生^_^.\n");
}


void FirstHandle() {
    char handle;
    while(1) {
        Start();
        printf("请输入：");
        scanf("%c",&handle);
        switch(handle) {
            case'1': ChooseCharacter(); printf("按下回车继续"); EnterQuit(); return; break;
            case'2': ShowProbability(); break;
            case'3': ShowWeapon(); break;
            default: f = 0; return; break;          
        }
    }
}

int main() {
    FirstHandle();
    if(f) MidHandle();
    SayGoodbye(); 
    system("pause");
    return 0;
}