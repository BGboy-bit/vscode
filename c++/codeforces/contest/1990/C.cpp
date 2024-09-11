#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n+1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1);
    ll ans = 0, maxx = 0;
    unordered_map<ll, ll> mp;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        ans += a[i];
        mp[a[i]] ++;
        if(mp[a[i]] >= 2) maxx = max(maxx, a[i]);
        a[i] = maxx;
    }

    unordered_map<ll, ll> cnt;
    vector<ll> b;
    maxx = 0;
    for(ll i = 1; i <= n; i ++ ) {
        if(a[i] != 0) {
            ans += a[i];
            cnt[a[i]] ++;
            if(cnt[a[i]] == 1) {
                b.push_back(a[i]);
                a[i] = maxx;
            } else {
                maxx = a[i];
            }
        }
    }
    ll summ = 1;
    for(ll i = b.size() - 2; i >= 2; i -- ) {
        if(cnt[b[i]] == 1) {
            if(cnt[b[i - 1]] > 1) {
                cnt[b[i - 1]] += summ;
                summ = 1;
            }
            else summ ++ ;
            cnt[b[i]] = 0;
        }
    }
    reverse(b.begin(), b.end());
    for(ll i : b) {
        cnt[i] = 0;
        b.pop_back();
    }
    for(ll i = 1; i <= n; i ++ ) {
        cnt[a[i]] ++ ;
        if(cnt[a[i]] == 1)
        b.push_back(a[i]);
    }
    summ = 0;
    reverse(b.begin(), b.end());
    for(auto i : b) {
        ans += i * cnt[i] * (cnt[i] + 1) / 2 + (i * cnt[i]) * summ;
        summ += cnt[i];
    }
    cout << ans << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}