#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, q; cin >> n >> q;
    vector<ll> a(n + 1);
    map<ll, ll> mp;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i]; mp[a[i]] = i;
    }
    while(q -- ) {
        ll l, r, k; cin >> l >> r >> k;
        ll pos = mp[k];
        if(pos > r || pos < l) {
            cout << "-1" << " \n"[q == 0]; continue;
        }
        ll ans1 = 0, ans2 = 0, cnt1 = 0, cnt2 = 0;
        while(l < r) {
            ll mid = l + r >> 1;
            if(a[mid] == k) {
                break;
            } else if(a[mid] > k) {
                if(mid < pos) {
                    ans2 ++ ; l = mid + 1;
                } else {
                    cnt1 ++ ; r = mid - 1;
                }
            } else if(a[mid] < k) {
                if(mid > pos) {
                    ans1 ++ ; r = mid - 1;
                } else {
                    cnt2 ++ ; l = mid + 1;
                }
            }
        }
        if(ans1 > n - k - cnt1 || ans2 > k - 1 - cnt2) {
            cout << "-1" << " \n"[q == 0];
        } else {
            cout << 2 * max(ans1, ans2) << " \n"[q == 0];
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