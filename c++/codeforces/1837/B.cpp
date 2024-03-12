#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

ll n;
string str;


void Solve() {
    cin >> n >> str;
    ll cnt = 0, cnt1 = 0, cnt2 = 0;
    for(ll i = 0; i < n; i ++ ) {
        if(str[i] == '>') {
            cnt1 ++;
            cnt = max(cnt, cnt2);
            cnt2 = 0;
        }
        else {
            cnt2 ++;
            cnt = max(cnt, cnt1);
            cnt1 = 0;
        }
    } 
    cnt = max(cnt, cnt1);
    cnt = max(cnt, cnt2);
    cout << cnt + 1 << "\n";
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