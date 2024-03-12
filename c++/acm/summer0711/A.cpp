#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int MAX = 1e5 + 10;
ll a[MAX];
ll b[MAX];
ll n, k;

void Prime() {
    // for(ll i = 1; i <= n - k; i ++ ) {
    //     ll cnt = 0;
    //     for(ll j = i; j <= n; j += k) {
    //         b[cnt ++ ] = a[j];
            
    //     } 
    //     sort(b, b + cnt);
    //     cnt = 0;
    //     for(ll j = i; j <= n; j += k) {
    //         a[j] = b[cnt ++ ];
    //     } 
    // }
    sort(b + 1, b + n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        if(a[i] != b[i]) {
            bool ff = 0;
            for(ll j = i; j <= n; j += k) {
                if(a[j] == b[i]) {
                    swap(a[i], a[j]);
                    ff = 1;
                    break;
                }
            }
            if(!ff) {
                printf("No\n");
                return;
            }
        }
    }
    printf("Yes\n");
}

void Solve() {

    // cin >> n >> k;
    scanf("%lld %lld", &n, &k);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        b[i] = a[i];
    }
    Prime();

  
    // ll maxx = 0;
    // bool ff = 0;
    // for(ll i = 1; i <= n; i ++ ) {
    //     if(maxx > a[i]) {
    //         ff = 1;
    //         break;
    //     }
    //     else maxx = a[i];
    // }
    // // if(ff) cout << "No" << "\n";
    // // else cout << "Yes" << "\n"; 
    // if(ff) printf("No\n");
    // else printf("Yes\n");
} 


int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}