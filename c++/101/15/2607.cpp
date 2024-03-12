#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef int ll;

ll a[1010];
ll b[10][1010];
ll ris[10];

int main() {
    while(scanf("%d", &a[1]) != EOF) {
        ll x, cnt = 1;
        while(scanf("%d", &x) && x != -1) a[ ++ cnt] = x;
        for(ll i = 0; i < 3; i ++ ) {
            memset(ris, 0, sizeof(ris));
            for(ll j = 1; j <= cnt; j ++ ) {
                ll x = (ll)(a[j] / pow(10, i)) % 10; 
                b[x][ris[x] ++ ] = a[j];
            }

            for(ll m = 1, j = 0; j < 10; j ++ ) {
                for(ll k = 0; k < ris[j]; k ++ ) {
                    a[m] = b[j][k];
                    printf("%d",a[m ++ ]);
                    if(m != cnt + 1) printf(" ");
                } 
            } 
            printf("\n");
        }
    }
    return 0;
}