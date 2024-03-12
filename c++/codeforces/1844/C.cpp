#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int MAX = 2e5 + 10;
ll c[MAX], a[MAX];
ll n;

void Solve() {
    cin >> n;
    ll ans = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> c[i];
        ans += c[i];
    }
    ll cnt = 0;
    for(ll i = 1; i <= n; i ++ ) {
        if(c[i] < 0) {
            ll ris, sum = 0;
            for(ll j = i; j <= n; j ++ ) {
                if(c[j] >= 0) {
                    ris = j;
                    break;
                }
                sum += c[j];
                if(j == n) ris = n;
            }

            if((ris - i + 1) % 2 != 0) {
                i = ris;
                ans -= sum;
            }
            else {
                if(ris == n || i == 1) {
                    i = ris;
                    ans -= sum;
                }
                else {
                    if(c[i] > c[ris]) {
                        ans -= sum - c[i];
                        a[++ cnt] = c[i] + c[ris + 1];
                        i = ris + 1;
                    }
                    else {
                        ans -= sum - c[ris];
                        a[cnt] += c[ris];
                        i = ris;
                    }
                }
            }
        }
        else a[ ++ cnt] = c[i];  
    }
    for()
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