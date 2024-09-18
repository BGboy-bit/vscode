#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using PII = pair<int,int>;

string s, t;
ll sl, tl;
vector<vector<ll>> v;
const ll mod = 998244353;

void dfs(ll res, ll le, queue<ll> q) {
    bool ff = 0;
    for(ll i = le; i < sl; i ++ ) {
        if(sl - i < tl - res) return;
        if(s[i] == t[res]) {
            if(res == tl - 1) {
                if(!ff) {
                    ff = 1;
                    q.push(i);
                    vector<ll> v1;
                    while(!q.empty()) {
                        v1.push_back(q.front());
                        q.pop();
                    }
                    v.push_back(v1);
                } else {
                    vector<ll> v1;
                    for(ll j = 0; j < v[v.size() - 1].size() - 1; j ++ ) {
                        v1.push_back(v[v.size() - 1][j]);
                    }
                    v1.push_back(i);
                    v.push_back(v1);
                }
            } else {
                q.push(i);
                dfs(res + 1, i + 1, q);
                q.pop();
            }
        }
    }
}

ll dfs1(ll res, ll u) {

}

void solve()
{
    cin >> s >> t;
    sl = s.length(), tl = t.length();
    queue<ll> q;
    for(ll i = 0; i < sl - tl; i ++ ) {
        if(s[i] == t[0]) {
            q.push(i);
            dfs(1, i + 1, q);
            q.pop();
        }        
    }
    // for(ll i = 0; i < v.size(); i ++ ) {
    //     for(ll j = 0; j < tl; j ++ ) {
    //         cout << v[i][j] << " \n"[j == tl - 1];
    //     }
    // }
    ll ans = 0;
    for(ll i = 0; i < v.size(); i ++ ) {
        // ans = (ans + dfs1(i, )) % mod;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    for(int i=1;i<=T;i++){
        solve();
    }
}
