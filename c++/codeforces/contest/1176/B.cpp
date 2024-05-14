#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n,cnt = 0,cnt1 = 0,cnt2 = 0;
    ll a[104],b[104];
    cin >> n;
    for(ll i = 0; i < n; i ++) {
        cin >> a[i];
        if(a[i] % 3 == 0) cnt ++;
        if(a[i] % 3 == 1) cnt1 ++;
        if(a[i] % 3 == 2) cnt2 ++;
    }
    cnt += min(cnt1, cnt2) + (max(cnt1, cnt2) - min(cnt1, cnt2)) / 3;
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