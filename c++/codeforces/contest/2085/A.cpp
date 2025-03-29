#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, k; cin >> n >> k;
    string s, s1; cin >> s; s1 = s;
    reverse(s.begin(), s.end());
    if(s > s1) {
        cout << "Yes\n"; return ;
    } else if(k == 0) {
        cout << "No\n"; return ;
    }
    if(s1[0] > s1[n - 1]) {
        cout << "Yes\n"; return ;
    }
    for(ll i = 1; i < n - 1; i ++ ) {
        if(s1[i] > s1[0] || s1[i] < s1[n - 1]) {
            cout << "Yes\n"; return ;
        } 
    }
    cout << "No\n";
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