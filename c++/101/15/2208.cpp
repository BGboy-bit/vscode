#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e5 + 10;
int n, m;
ll a[MAX], b[MAX], tmp[MAX];

void merge_sort() {
    int x = 1, y = 1, k = 1;
    while(x <= n && y <= m) {
        if(a[x] < b[y]) tmp[k ++ ] = a[x ++ ];
        else tmp[k ++ ] = b[y ++ ]; 
    }
    while(x <= n) tmp[k ++ ] = a[x ++ ];
    while(y <= m) tmp[k ++ ] = b[y ++ ];
    for(int i = 1; i < k; i ++ ) {
        printf("%d", tmp[i]);
        if(i != k - 1) printf(" ");
    } 
    printf("\n");
}

int main() {
    while(scanf("%d", &n) != EOF) {
        for(ll i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
        scanf("%d", &m);
        for(ll i = 1; i <= m; i ++ ) scanf("%d", &b[i]);
        merge_sort();
    }
    return 0;
}