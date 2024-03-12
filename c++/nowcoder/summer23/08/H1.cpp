#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1e6 + 10;
bool multi = 0;//∂‡◊È ‰»Î

ll n;
stack<int> s;
priority_queue<int> q[MAX];

void Solve() {
    cin >> n;
    ll ans = 0;
    for(ll i = 1; i <= n; i ++ ) { 
        ll a; cin >> a;
        if(a == 1) {
            s.push(i);
            q[1].push(i);
        }
        else {
            ll x = 0;
            if(!q[a - 1].empty()) {
                x = q[a - 1].top();
                q[a - 1].pop();
                q[a].push(x);
            }         
            while(!s.empty() && s.top() > x) s.pop();
        }
        ans += s.size();
    }
    cout << ans << "\n";
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