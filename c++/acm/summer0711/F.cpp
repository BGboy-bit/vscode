#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 5e5 + 10;
ll a[MAX];
stack<ll> s;
ll maxx_left[MAX], maxx_right[MAX];
ll minn_left[MAX], minn_right[MAX];
ll n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    ll ans = 0;
    for(ll i = 1; i <= n; i ++ ) cin >> a[i];
    
    //maxx_right >=
    for(ll i = n; i >= 1; i -- ) {
        while(!s.empty() && a[s.top()] <= a[i]) s.pop();
        maxx_right[i] = s.empty() ? n + 1 : s.top();
        s.push(i);
    }
    while(!s.empty()) s.pop();

    //maxx_left >
    for(ll i = 1; i <= n; i ++ ) {
        while(!s.empty() && a[s.top()] < a[i]) s.pop();
        maxx_left[i] = s.empty() ? 0 : s.top();
        s.push(i);    
    }
    while(!s.empty()) s.pop();
    
    //algorithm
    for(ll i = 1; i <= n; i ++ ) {
        ans += ((maxx_right[i] - i - 1) * (i - maxx_left[i] - 1) + maxx_right[i] - maxx_left[i] - 2) * a[i];    
    }

    //minn_right >=
    for(ll i = n; i >= 1; i -- ) {
        while(!s.empty() && a[s.top()] >= a[i]) s.pop();
        minn_right[i] = s.empty() ? n + 1 : s.top();
        s.push(i);
    }
    while(!s.empty()) s.pop();

    //minn_left >
    for(ll i = 1; i <= n; i ++ ) {
        while(!s.empty() && a[s.top()] > a[i]) s.pop();
        minn_left[i] = s.empty() ? 0 : s.top();
        s.push(i);    
    }
    while(!s.empty()) s.pop();
    
    //algorithm
    for(ll i = 1; i <= n; i ++ ) {
        ans -= ((minn_right[i] - i - 1) * (i - minn_left[i] - 1) + minn_right[i] - minn_left[i] - 2) * a[i];    
    }

    cout << ans << "\n";
    return 0;
}