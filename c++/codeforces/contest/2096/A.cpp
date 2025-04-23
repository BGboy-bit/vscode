#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    string s; cin >> s; s = '!' + s;
    ll cnt1 = 1, cnt2 = 0;
    for(ll i = 1; i < n; i ++ ) {
        if(s[i] == '<') {
            cnt1 ++ ;        
        } else {
            cnt2 ++ ;
        }
    } 
    if(s[1] == '<') 
        cout << cnt1 << " ";
    else 
        cout << n - cnt2 << " ";
    for(ll i = 1; i < n; i ++ ) {
        if(s[i] == '>') {
            cout << n - ( -- cnt2) << " \n"[i == n - 1];
        } else {
            cout << -- cnt1 << " \n"[i == n - 1];
        }
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