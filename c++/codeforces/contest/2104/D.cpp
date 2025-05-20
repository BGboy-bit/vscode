#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pr[5800100];
ll p[400001];
ll nw = 0;

void Prime() {
    for(ll i = 2; i <= 5800080; i ++ ) {
        if(pr[i] == 0) {
            pr[i] = 1; p[++ nw] = i;
            for(ll j = i * i; j <= 5800080; j += i) {
                pr[j] = 1;
            }
        }
    }
}

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }   
    sort(a.begin() + 1, a.end(), greater<ll>());
    ll ans = 0;
    ll sum1 = 0, sum2 = 0;
    for(ll i = 1; i <= n; i ++ ) {
        sum1 += a[i];
        sum2 += p[i];
        if(sum1 >= sum2) {
            ans = i;
        }
    }
    cout << n - ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1; cin >> T;
    Prime();   
    while(T -- ) {
        Solve();
    }
    return 0;
}