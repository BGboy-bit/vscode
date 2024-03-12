#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX_SIZE 1000

typedef struct LinearList {
    int *data;
    int length;
} LinearList;

// 初始化线性表
void InitList(LinearList *list) {
    list->data = (int *)malloc(sizeof(int) * MAX_SIZE);
    list->length = 0;
}

// 在某个位置之前插入一个元素
void Insert(LinearList *list, int n) {
    int i, j, pos, val;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &pos, &val);
        // 将pos及其之后的元素向后移动一位
        for (j = list->length - 1; j >= pos - 1; j--) {
            list->data[j + 1] = list->data[j];
        }
        // 插入新元素
        list->data[pos - 1] = val;
        list->length++;
    }
}

// 删除某个位置的元素
void Delete(LinearList *list) {
    int pos, i;
    scanf("%d", &pos);
    printf("%d\n",list->data[pos - 1]);
    // 将pos及其之后的元素向前移动一位
    for (i = pos; i < list->length; i++) {
        list->data[i - 1] = list->data[i];
    }
    list->length--;
    
}

// 清除所有元素
void Clear(LinearList *list) {
    list->length = 0;
}

// 获取某个位置的元素
void Getelem(LinearList *list) {
    int pos;
    scanf("%d", &pos);
    printf("%d\n", list->data[pos - 1]);
}

int main() {
    LinearList list;
    InitList(&list);
    
    char command[10];
    int n;

    while (1) {
        scanf("%s", command);
        if (strcmp(command, "insert") == 0) {
            Insert(&list, n);
        } else if (strcmp(command, "delete") == 0) {
            Delete(&list);
        } else if (strcmp(command, "clear") == 0) {
            Clear(&list);
        } else if (strcmp(command, "getelem") == 0) {
            Getelem(&list);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Error: invalid command\n");
        }
    }

    free(list.data);
    return 0;
}
