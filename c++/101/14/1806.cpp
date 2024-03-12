#include<bits/stdc++.h>
using namespace std;

typedef struct BiNode {
    char data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;
//初始化
void init(BiTree *t) {
    *t = NULL;
}
int cnt;
int a[1010];

//前序输入创建二叉树
void CreateBiTree(BiTree *t) {
    char ch;
    ch = getchar();
    if(ch == '#') *t = NULL;
    else {
        *t = (BiNode *)malloc(sizeof(BiNode));
        if(!*t) exit(1);
        (*t)->data = ch;
        CreateBiTree(&(*t)->lchild);
        CreateBiTree(&(*t)->rchild);
    }
}

//求二叉树的深度
void BiTreeDepth(BiTree t, int depth) {
    if(t == NULL) return;
    if(t -> lchild == NULL && t -> rchild == NULL) {
        a[cnt ++ ] = depth;
        return;
    }
    BiTreeDepth(t -> lchild, depth + 1);
    BiTreeDepth(t -> rchild, depth + 1);
}


int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T -- ) {
        cnt = 0;
        getchar();
        BiTree t;
        CreateBiTree(&t);
        BiTreeDepth(t, 0);
        sort(a, a + cnt);
        if(cnt != 1) cout << a[cnt - 1] + a[cnt - 2] << "\n";
        else cout << a[0] << "\n";
    }
    return 0;
}

/*c*/
// #include<stdio.h>
// #include<stdbool.h>
// #include<stdlib.h>
// #include<string.h>
// #include<math.h>

// int cnt;
// int a[1010];

// typedef struct BiNode {
//     char data;
//     struct BiNode *lchird, *rchird;
// } BiNode, *BiTree;

// void CreateTree(BiTree *t) {
//     char ch;
//     ch = getchar();
//     if(ch == '#') *t = NULL;
//     else {
//         *t = (BiNode *)malloc(sizeof(BiNode));
//         (*t) -> data = ch;
//         CreateTree(&(*t) -> lchird);
//         CreateTree(&(*t) -> rchird);
//     }
    
// }

// void BiTreeDepth(BiTree t, int depth) {
//     if(t == NULL) return;
//     if(t -> lchird == NULL && t -> rchird == NULL) {
//         a[cnt ++ ] = depth;
//         return;
//     }
//     BiTreeDepth(t -> lchird, depth + 1);
//     BiTreeDepth(t -> rchird, depth + 1);
// }

// int cmp(const void *a,const void *b) {
//     return *(int*)b - *(int*)a;
// }

// int main() {
//     int t;
//     scanf("%d", &t);
//     while( t -- ) {
//         cnt = 0;
//         getchar(); 
//         BiTree t;
//         CreateTree(&t);
//         BiTreeDepth(t, 0);
//         qsort(a, cnt, sizeof(a), cmp);
//         if(cnt != 1) printf("%d\n", a[cnt - 1] - a[cnt - 2]);
//         printf("%d\n", a[0]); 
//     }
//     return 0;
// }



