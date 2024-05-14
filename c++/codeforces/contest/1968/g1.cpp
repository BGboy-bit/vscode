#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, l, r; cin >> n >> l >> r;
    string str; cin >> str;
    // make next
    vector<ll> nxt(n + 1);
    nxt[0] = -1;
    cout << str[0] << "\t";
    for(ll i = 1, j = -1; i < n; i ++ ) {
        while(j != -1 && str[i] != str[j + 1]) j = nxt[j];
        if(str[i] == str[j + 1]) j ++ ;
        nxt[i] = j;
        cout << str[i] << "\t\n"[i == n - 1];
    }
    for(ll i = 0; i < n; i ++ ) cout <<  nxt[i] + 1 << "\t\n"[i == n - 1];
    cout << "\n";
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