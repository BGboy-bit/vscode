#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2010;

ll n;
string s[MAX];

ll check(string x, string y) {
    if(x == y) return 0; 
    else {
        for(ll i = 0; i < y.size(); i ++ ) {
            if(!(x[i] == '0' && y[i] == '1' || x[i] == '1' && y[i] == '0')) return -1;
        }
        return 1;
    }
}

void filp() {
    for(ll i = 0; i < n; i ++ ) {
        for(ll j = i + 1; j < n; j ++ ) swap(s[i][j], s[j][i]);
    }
}

void Solve() {
    cin >> n;
    for(ll i = 0; i < n; i ++ ) cin >> s[i];

    ll ansr = 0, ansr1 = 0, ansc = 0, ansc1 = 0;
    //计算行所需的次数
    for(ll i = 1; i < n; i ++ ) {
        ll x = check(s[0], s[i]);
        if(x == -1) {
            // cout << "-1" << "\n"; return ;
            ansr = inf; break;
        }
        ansr += x;
    }
    if(ansr != inf) {
        ll cnt = 0;
        for(auto i : s[0]) {
            if(i == '0') cnt ++ ;
        }
        ansr1 = n - ansr;
        ansr = ansr + min(cnt, n - cnt);
        ansr1 = ansr1 + min(cnt, n - cnt);
        ansr = min(ansr, ansr1);
    }
    
    //计算列所需的次数
    filp();
    for(ll i = 1; i < n; i ++ ) {
        ll x = check(s[0], s[i]);
        if(x == -1) {
            // cout << "-1" << "\n"; return ;
             ansc = inf; break;
        }
        ansc += x;
    }
    if(ansc != inf) {
        ll cnt = 0;
        for(auto i : s[0]) {
            if(i == '0') cnt ++ ;
        }
        ansc1 = n - ansc;
        ansc = ansc + min(cnt, n - cnt);
        ansc1 = ansc1 + min(cnt, n - cnt);
        ansc = min(ansc, ansc1);
    }


    if(ansr == inf && ansc == inf) cout << "-1" << "\n";
    else cout << min(ansc, ansr) << "\n";
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