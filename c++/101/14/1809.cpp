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
    if(ch == '0') *t = NULL;
    else if(ch == '1') {
        *t = (BiNode *)malloc(sizeof(BiNode));
        if(!*t) exit(1);
        (*t)->data = ch;
        CreateBiTree(&(*t)->lchild);
    }
    else {
        *t = (BiNode *)malloc(sizeof(BiNode));
        if(!*t) exit(1);
        (*t)->data = ch;
        CreateBiTree(&(*t)->lchild);
        CreateBiTree(&(*t)->lchild);
    }
}

//求二叉树的深度
void BiTreeDepth(BiTree t, int depth) {
    if(t == NULL) return;
    if(t -> lchild == NULL && t -> rchild == NULL) {
        a[cnt ++] = depth;
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
    }
    return 0;
}

