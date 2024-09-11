#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n + 1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int maxn = 3e5 + 10;
const int N = 2e5 + 10;
bool multi = 1;

vector<vector<ll>> co(N);
vector<ll> pr(maxn, 0);
vector<ll> ans(N);
vector<ll> coo(N);
void init() {
    pr[1] = 1;
    for(ll i = 2; i <= maxn; i ++ ) {
        if(pr[i] == 0) {
            for(ll j = i * 2; j <= maxn; j += i) pr[j] = 1;
        }
    }
    ll maxx = 1; 
    for(ll i = 1; i <= 2000; i += 4) {
        co[1].push_back(i);
        coo[i] = 1;
    }
    ans[1] = 1;
    for(ll i = 2; i <= 2000; i ++ ) {
        if(coo[i]) continue;
        bool ff = true;
        for(ll j = 1; j <= maxx; j ++ ) {
            ff = true;
            for(auto k : co[j]) {
                if(pr[(i ^ k)] == 0) {
                    ff = false;
                    break;
                }
            }
            if(ff) {
                co[j].push_back(i);
            }
        }
        if(!ff) co[++ maxx].push_back(i);
        ans[i] = maxx;
    }
    cout << maxx << "\n";
}

void Solve() {
    ll n; cin >> n;
    cout << ans[n] << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}