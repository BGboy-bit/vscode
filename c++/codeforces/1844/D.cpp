#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int MAX = 1e6 + 10;
ll b[1010], c[1010];
bool vis[27];
ll a[MAX];

void Solve() {
    ll n;
    cin >> n;
    ll cnt1 = 0, cnt2 = 0;
    b[++ cnt1] = 1;
    c[++ cnt2] = n;
    for(ll i = 2; i * i <= n; i ++ ) {
        if(n % i == 0) {
            b[ ++ cnt1] = i;
            if(n / i != i) c[ ++ cnt2] = n / i;
        }
    }
    for(ll i = cnt2; i >= 1; i --) {
        b[ ++ cnt1] = c[i];
    }
    for(ll i = 1; i <= n; i ++ ) {
        memset(vis, 0, sizeof(vis));
        for(ll j = 1; i - b[j] > 0; j ++ ) {
            vis[a[i - b[j]]] = 1; 
        }
        for(ll j = 1; j <= 26; j ++ ) {
            if(!vis[j]) {
                char c = 'a' + j - 1;
                cout << c;
                a[i] = j;
                break;
            }
        }
    }
    cout << "\n";  
}


int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    ll T = 1;
    cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}