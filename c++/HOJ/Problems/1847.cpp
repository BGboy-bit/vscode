// Good Luck in CET-4 Everybody!
// https://acm.hdu.edu.cn/showproblem.php?pid=1847

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1000;
ll b2[20];
ll sg[maxn + 10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    b2[0] = 1;
    for(ll i = 1; i < 20; i ++ ) {
        b2[i] = b2[i - 1] * 2;
    }
    for(ll i = 0; i <= maxn; i ++ ) {
        set<ll> s;
        for(ll j = 0; b2[j] <= i; j ++ ) {
            s.insert(sg[i - b2[j]]);
        }
        while(s.find(sg[i]) != s.end()) {
            sg[i] ++ ;
        }
    }
    // for(ll i = 0; i <= 100; i ++ ) {
    //     cout << i << " " << sg[i] << "\n";
    // }
    ll x; while(cin >> x) {
        if(sg[x])
            cout << "Kiki\n";
        else 
            cout << "Cici\n";
    }
    return 0;
}