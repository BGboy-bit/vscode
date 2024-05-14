#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int MAX = 2e5 + 10;

struct node { 
    ll point = 0;
    ll cos = 0;
    ll soc = 0;
};

void Solve() {
    ll n, m, h;
    cin >> n >> m >> h;
    node num[n + 1];
    vector<ll> t(m + 1, 0);
    vector<ll> tt(m + 1, 0);
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= m; j ++ ) {
            cin >> t[j];
        }
        sort(t.begin(), t.end());
        ll cnt = 1;
        while(num[i].cos + t[cnt] <= h && cnt <= m) {
            tt[cnt] = tt[cnt - 1]  + t[cnt]; 
            num[i].cos += t[cnt];
            num[i].soc += tt[cnt];
            num[i].point ++ ;
            cnt ++ ;
        }
    }
    ll ans = 1;
    for(ll i = 2; i <= n; i ++ ) {
        if(num[i].point > num[1].point) ans ++ ;
        else if(num[i].point == num[1].point) {
            if(num[i].soc < num[1].soc) ans ++ ;
        }
    }
    cout << ans << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}