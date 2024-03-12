#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1e6 + 10;
bool multi = 1;//¶à×éÊäÈë

ll n;
ll b[MAX];

void Solve() {
    cin >> n;
    ll m = n * (n - 1) / 2;
    for(ll i = 1; i <= m; i ++ ) {
        cin >> b[i];
    }
    sort(b + 1, b + m + 1);
    ll res = b[1], cnt = 0, summ = 0, ress = 1;
    for(ll i = 1; i <= m; i ++ ) {
        if(b[i] == res) {
            cnt = 0;
            for(ll j = i; j <= m; j ++ ) {
                if(b[j] == res) cnt ++ ;
                else if(b[j] != res || j == m) {
                    if(cnt == n - ress) {
                        cout << res << " "; ress ++ ;
                    }
                    else {
                        while(cnt != 0) {
                            cout << res << " ";
                            cnt -= n - ress;
                            ress ++ ;
                        }
                    }
                    
                    res = b[j]; i = j - 1; break;
                }
                if(j == m && res == b[j]) {
                    if(cnt == n - ress) {
                        cout << res << " "; ress ++ ;
                    }
                    else {
                        while(cnt != 0) {
                            cout << res << " ";
                            cnt -= n - ress;
                            ress ++ ;
                        }
                    }
                    i = m;
                }
            }
        } 
    }
    cout << b[m];
    cout << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}