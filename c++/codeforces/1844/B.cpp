#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;



void Solve() {
    ll n;
    cin >> n;
    if(n == 1) cout << "1" << "\n";
    else if(n == 2) cout << "2 1" << "\n";
    else if(n == 3) cout << "2 1 3" << "\n";
    else {
        cout << "2 "; 
        ll cnt = 1;
        for(ll i = 4; i <= n; i ++ ) {
            cnt ++ ;
            cout << i << " ";
            if(cnt == n / 2) cout << "1 ";        
        }
        cout << "3" << "\n";
    }
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