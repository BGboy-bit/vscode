#include<stdio.h>

const int MAX = 1e5 + 10;
int val[MAX], nxt[MAX];
int head = -1, idx = 0;

void add_to_head(int x) {
    val[idx] = x;
    nxt[idx] = head;
    head = idx ++ ;
}

void add(int k, int x) {
    val[idx] = x;
    nxt[idx] = nxt[k];
    nxt[k] = idx ++ ;
}

void remove(int k) {
    if(k == -1) head = nxt[head];
    else nxt[k] = nxt[nxt[k]];
} 

int main() {
    int m;
    scanf("%d", &m);
    while(m -- ) {
        char  op;
        getchar();
        scanf("%c", &op);
        if(op == 'H') {
            int x;
            scanf("%d", &x);
            add_to_head(x);
        }
        else if(op == 'D') {
            int k;
            scanf("%d", &k);
            remove(k - 1);
        }
        else if(op == 'I') {
            int k, x;
            scanf("%d %d", &k, &x);
            add(k - 1, x);
        }
    }
    for(int i = head; i != -1; i = nxt[i]) printf("%d ", val[i]);
    return 0;
}
