#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = (1 << 21) - 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n, k; cin >> n >> k;
    vector<bool> a1(N + 1), a2(N + 1), a3(N + 1);
    a1[0] = true;
    for(ll i = 1; i <= n; i ++ ) {
        ll a, b; cin >> a >> b;
        for(ll j = 0; j < N; j ++ ) {
            ll x = j ^ a, y = j ^ a ^ b;
            if(a1[j] && x < N && y < N) {
                a2[x] = true; a3[y] = true;
            }
        }
        for(ll j = 0; j < N; j ++ ) {
            a1[j] = a1[j] | a2[j] | a3[j];
        }
    }
    for(ll i = N - 1; i >= 0; i -- ) {
        if(a1[i]) k -- ;
        if(!k) {
            cout << i << "\n"; return 0;
        } 
    }
    cout << "-1\n";
    return 0;
}