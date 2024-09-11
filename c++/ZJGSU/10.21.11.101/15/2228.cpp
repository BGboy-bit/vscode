#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef int ll;

ll a[1100];
ll cnt;

int main() {
    ll n;
    while(scanf("%d", &n) != EOF) {
        cnt = 0;
        for(ll i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
        for(ll i = 1; i <= n; i ++ ) {
            if(i != a[i]) {
                cnt ++;
                for(ll j = 1; j <= n; j ++ ) {
                    if(a[j] == i) {
                        ll x = a[j];
                        a[j] = a[i];
                        a[i] = x;
                    }
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0; 
}
