#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 110;

void Solve() {
    string s[MAX];
    bool f[MAX];
    ll n, k, cnt = 0;
    memset(f, 0, sizeof(f));
    cin >> n >> k;
    for(ll i = 0; i < n; i ++) {
        cin >> s[i];
    }
    for(ll i = 0; i < k;i ++) {
        for(ll j = 0; j < n; j ++) {
            if(s[j][i] != s[0][i]) f[j] = 1; 
        }
    }
    for(ll i = 0; i < n; i ++) {
        if(f[i] == 0) cnt ++;
    }
    cout << cnt << "\n";
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