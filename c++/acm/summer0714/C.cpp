#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int MAX = 2010;
string str;
ll n, k;
ll b[MAX], c[MAX];
unordered_map<char, ll> mp;

void Solve() {
    cin >> n >> k;
    cin >> str;
    ll cnt = 0;
    for(ll i = 1; i * i <= n; i ++ ) {
        if(n % i == 0) {
            b[++ cnt] = i;
            if(n / i != i) b[++ cnt] = n / i;
        }
    }
    sort(b + 1, b + cnt + 1);
    for(ll i = 1; i <= cnt; i ++) {
        ll tnc = 0;
        for(ll j = 0; j < b[i]; j ++) {
            ll maxx = 0;
            char c;
            for(ll k = j; k < n; k += b[i]) {
                mp[str[k]] ++ ;
                if(maxx < mp[str[k]]) {
                    c = str[k];
                    maxx = mp[str[k]];
                }
            }
            for(ll k = j; k < n; k += b[i]) {
                if(str[k] != c) tnc ++;
                mp[str[k]] = 0;
            }
        }
        if(tnc <= k) {
            cout << b[i] << "\n";
            break;
        }
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