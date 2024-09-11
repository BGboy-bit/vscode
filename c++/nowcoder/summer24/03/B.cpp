#include <bits/stdc++.h>
#define int long long
using ll = long long;
using PII = std::array<int, 2>;
using namespace std;
const ll INF = 2E18 + 10;

// struct cmp{bool operator()(const int & x, const int &y) const{ return x<y;}};
const int N = 2E6 + 10;

void SINGLE_TEST() 
{
    int n,d;
    cin>>n>>d;
    vector<int> h(n+2);
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    ll g = h[1];
    for(ll i = 2; i <= n; i ++ ) g = __gcd(g, h[i]);
    d = d % g;
    cout << min(d, g - d) << "\n";
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int SAMPLES = 1;
    // cin >> SAMPLES;
    while (SAMPLES--) SINGLE_TEST();
}
