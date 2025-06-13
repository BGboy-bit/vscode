#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.first * a.second == b.first * b.second) {
        return a.first < b.first;
    }
    return a.first * a.second < b.first * b.second;
}

bool cmp1(vector<ll> &a, vector<ll> &b) {
    if(a.size() == b.size()) {
        for (ll i = a.size() - 1; i >= 0; i--) {
            if (a[i] != b[i]) {
                return a[i] > b[i];
            }
        }
    } else {
        return a.size() > b.size();
    }
}

vector<ll> mul(vector<ll> &A, ll b) {
    vector<ll> C;
    ll t = 0;
    for (ll i = 0; i < A.size() || t; i ++ ) {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

vector<ll> div(vector<ll> &A, ll b) {
    vector<ll> C;
    ll r = 0;
    for (ll i = A.size() - 1; i >= 0; i -- ) {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    ll k1, k2; cin >> k1 >> k2;
    vector<pair<ll, ll>> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin() + 1, a.end(), cmp);
    vector<ll> ans, cur, cur1;
    while(k1) {
        cur.push_back(k1 % 10);
        k1 /= 10;
    }
    for(ll i = 1; i <= n; i ++ ) {
        cur1 = cur;
        cur = div(cur, a[i].second);
        if(!cmp1(ans, cur)) {
            ans = cur;
        }
        cur = mul(cur1, a[i].first);
    }
    reverse(ans.begin(), ans.end());
    for(ll i = 0; i < ans.size(); i ++ ) {
        cout << ans[i];
    }
    cout << "\n";
    return 0;
}