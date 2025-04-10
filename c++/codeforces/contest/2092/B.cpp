#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    string a, b; cin >> a >> b;
    ll cnt1 = 0, cnt2 = 0;
    for(ll i = 0; i < n; i ++ ) {
        if(i % 2 == 0) {
            if(a[i] == '1') cnt1 ++ ;
            if(b[i] == '1') cnt2 ++ ;
        } else if(i % 2 == 1) {
            if(b[i] == '1') cnt1 ++ ;
            if(a[i] == '1') cnt2 ++ ;
        }
    }
    if(cnt1 > n / 2 || cnt2 > (n + 1) / 2) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1; cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}