#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int MAX = 2e5 + 10;
const int MAXX = 1e4 + 10;
ll a[MAX];
ll n, k;
// vector<vector<ll>> v;
ll v[MAXX][MAXX];
ll b[MAX];
set<ll> s;
unordered_map<ll, ll> mp;

void Solve() {
    //ll n, k;  
    ll cnt = 0;
    cin >> n >> k;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        if(a[i] < 0) {
            ll x = (- a[i]) / i;
            ll y = (- a[i]) % i;
            if(s.count(x) == 0) {
                s.insert(x);
                mp[x] = ++ cnt;
            }
            v[mp[x]][b[mp[x]] ++ ] = y;   
        } 
    }
    for(ll i = 1; i <= k; i ++ ) {
        if(s.count(i) == 1) {
            sort(v[mp[i]], v[mp[i]] + b[mp[i]]);
            bool ff = 0;
            for(ll j = 0; j < b[mp[i]]; j ++ ) {
                if(v[i][j] != j) {
                    cout << j << "\n";
                    ff = 1;
                    break;
                }
            }        
            if(!ff) cout << b[mp[i]] << "\n";
        }
        else cout << "0" << "\n";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}