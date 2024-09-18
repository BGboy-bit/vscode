// Fibonacci again and again
// https://acm.hdu.edu.cn/showproblem.php?pid=1848

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fib[100];
ll sg[1010];

void FBI() {
    fib[1] = 1;
    fib[2] = 2;
    ll cnt = 3;
    while((fib[cnt] = fib[cnt - 1] + fib[cnt - 2]) && fib[cnt] <= 1000) {
        cnt ++ ;
    }
}

void SG() {
    for(ll i = 0; i <= 1000; i ++ ) {
        set<ll> s;
        for(ll j = 1; fib[j] <= i; j ++ ) {
            s.insert(sg[i - fib[j]]);
        }
        while(s.find(sg[i]) != s.end()) {
            sg[i] ++ ;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    FBI();
    SG();
    ll m, n, p; cin >> m >> n >> p;
    while(m != 0 && n != 0 && p != 0) {
        ll ans = sg[m] ^ sg[n] ^ sg[p];
        if(ans) {
            cout << "Fibo\n";
        } else {
            cout << "Nacci\n";
        }
        cin >> m >> n >> p;
    }
    return 0;
}