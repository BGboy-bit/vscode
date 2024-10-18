#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool Check1(ll x, vector<ll> &a) {
    ll sum = 0;
    for(ll i = 1; i < a.size(); i ++ ) {
        if(a[i] > x) {
            sum += a[i] - x;
        } else {
            if(a[i] + sum >= x)
                sum -= x - a[i];
            else 
                return false;
        }
    }
    return true;
}

bool Check2(ll x, vector<ll> &a) {
    ll sum = 0;
    for(ll i = 1; i < a.size(); i ++ ) {
        if(a[i] > x) {
            sum += a[i] - x;
        } else {
            sum -= x - a[i];
            sum = max(sum, 0ll);
        }
    }
    return sum <= 0;
}

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    ll lo = 0, hi = 10, maxx, minn;

    while(lo < hi) {
        ll mid = lo + hi + 1 >> 1;
        if(Check1(mid, a)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    minn = lo;
    
    lo = 0, hi = 1e15;
    while(lo < hi) {
        ll mid = lo + hi >> 1;
        if(Check2(mid, a)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    maxx = lo;
    cout << maxx - minn << "\n";
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T; cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}