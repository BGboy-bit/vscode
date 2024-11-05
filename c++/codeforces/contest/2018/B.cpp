#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1);
    vector<vector<ll>> pos(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    ll st = -1, ed = -1, ans, st1, ed1;
    for(ll i = 1; i <= n; i ++ ) {
        if(pos[i].empty()) continue;
        if(pos[i].back() - pos[i].front() >= i) {
            cout << "0\n"; return ; 
        }
        if(st == -1) {
            st = pos[i].front(); ed = pos[i].back(); ed1 = min(st + i - 1, n), st1 = max((ed - i + 1), 1ll);
        } else {
            if(pos[i].front() < st && pos[i].front() + i <= ed || pos[i].back() > ed && pos[i].back() - i >= st) {
                cout << "0\n"; return ;        
            } else {
                st = min(st, pos[i].front()); ed = max(ed, pos[i].back()); 
                st1 = max(st1, pos[i].back() - i + 1), ed1 = min(ed1, pos[i].front() + i - 1);
            }
        }
    }
    cout << ed1 - st1 + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T; cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}