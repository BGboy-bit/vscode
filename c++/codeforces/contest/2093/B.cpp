#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    string s; cin >> s;
    bool ff = 0;
    ll ans = 0;
    for(ll i = s.size() - 1; i >= 0; i -- ) {
        if(s[i] > '0') {
            if(!ff) 
                ff = 1;
            else    
                ans ++ ;
        } else {
            if(!ff)
                ans ++ ;
        }
    }
    cout << ans << "\n";
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