#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e4 + 10;
int n;
int a[MAX];

int main() {
    while(scanf("%d", &n) != EOF) {
        for(ll i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        for(ll i = 1; i <= n; i ++ ) {
            printf("%d", a[i]);
            if(i != n) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
