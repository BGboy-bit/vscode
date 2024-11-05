#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
using PII = pair<int,int>;

constexpr ll INF = 2E18 + 10;
constexpr int N = 2E6 + 10;

vector<vector<ll>> g(10000);
map<pair<ll, ll>, ll> mp, mp1;
ll lok[10000], ans[10000];
ll t; 

void bfs(ll st) {
    vector<ll> vis(10000);
    queue<pair<ll, ll>> q; q.push({st, 0});
    while(!q.empty()) {
        ll res = q.front().first, cnt = q.front().second; q.pop();
        vis[res] = 1;
        if(lok[res]) {
            ans[res] = cnt; t -- ;
            if(t == 0) return ;   
        }
        string ss = to_string(res); 
        while(ss.size() < 4) ss = '0' + ss;
        for(ll i = 0; i < 4; i ++ ) {
            for(ll j = i; j < 4; j ++ ) {
                string ss1 = ss, ss2 = ss;
                for(ll k = i; k <= j; k ++ ) {
                    ss1[k] += 1;
                    if(ss1[k] > '9') ss1[k] = '0';
                    ll ress = 0;
                    for(ll kk = 0; kk < 4; kk ++ ) {
                        ress = ress * 10 + ss1[kk] - '0'; 
                    }
                    if(!vis[ress]) {
                        vis[ress] = 1;
                        q.push({ress, cnt + 1});
                        // cout << i << " " << j << " ";
                        // cout << ress << "\n";
                    }
                    ss2[k] -= 1;
                    if(ss2[k] < '0') ss2[k] = '9';
                    ress = 0;
                    for(ll kk = 0; kk < 4; kk ++ ) {
                        ress = ress * 10 + ss2[kk] - '0'; 
                    }
                    if(!vis[ress]) {
                        vis[ress] = 1;
                        q.push({ress, cnt + 1});
                        // cout << i << " " << j << " ";
                        // cout << ress << "\n";
                    }        
                }
            }
        }
    }
}

void solve() {
    cin >> t;
    vector<ll> aa;
    for(ll i = 1; i <= t; i ++ ) {
        ll a, b; cin >> a >> b;
        ll x = 0, c = 0;
        for(ll i = 0; i <= 3; i ++ ) {
            ll a1 = a % 10, b1 = b % 10; c = c == 0 ? 1 : c * 10;
            a /= 10, b /= 10; 
            x += c * (a1 - b1 >= 0 ? a1 - b1 : 10 + a1 - b1);
        }
        lok[x] = 1;
        aa.push_back(x);
    }
    bfs(0);
    for(ll i : aa) {
        cout << ans[i] << "\n";
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
}