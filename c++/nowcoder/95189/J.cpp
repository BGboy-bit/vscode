#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    vector<vector<ll>> ans(2);
    vector<ll> vis(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        if(vis[i]) continue;
        vector<ll> cir;
        ll res = a[i];
        while(!vis[res]) {
            cir.push_back(res); 
            vis[res] = 1;
            res = a[res];
        }
        for(ll l = 0, r = cir.size() - 1; l < r; l ++ , r -- ) {
            ans[0].push_back(cir[l]);
            ans[0].push_back(cir[r]);
        }
        for(ll l = 1, r = cir.size() - 1; l < r; l ++ , r -- ) {
            ans[1].push_back(cir[l]);
            ans[1].push_back(cir[r]);
        }
    } 
    if(ans[0].size() == 0) {
        cout << "0\n"; return ;
    }
    if(ans[1].size() == 0) {
        cout << "1\n";
        cout << ans[0].size() / 2 << " "; 
        for(ll i = 0; i < ans[0].size(); i ++ ) {
            cout << ans[0][i] << " \n"[i == ans[0].size() - 1];
        }
        return ;
    }
    cout << "2\n";
    cout << ans[0].size() / 2 << " "; 
    for(ll i = 0; i < ans[0].size(); i ++ ) {
        cout << ans[0][i] << " \n"[i == ans[0].size() - 1];
    }
    cout << ans[1].size() / 2 << " "; 
    for(ll i = 0; i < ans[1].size(); i ++ ) {
        cout << ans[1][i] << " \n"[i == ans[0].size() - 1];
    }   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    while(T -- ) {
        Solve();
    }
    return 0;
}