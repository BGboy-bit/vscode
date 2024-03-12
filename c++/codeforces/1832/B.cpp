#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int MAX = 2e5 + 10;

ll n, k, sum;
ll b[MAX], c[MAX];

void Solve() {
    ll sum = 0, ans = 0;
    cin >> n >> k;
    vector<int> vt(n);
    queue<ll> q1, q2; 
    for(ll i = 0; i < n; i ++) {
        cin >> vt[i];
        sum += vt[i];
    } 
    sort(vt.begin(), vt.end());
    for(int i = 1; i <= k; i ++) {
        b[i] += b[i - 1] + vt[2 * i - 2] + vt[2 * i - 1];
        c[i] += c[i - 1] + vt[n - i - 1];
    }
    for(int i = 0; i <= k; i ++) {
        ans = max(sum - b[i] - c[k - i], ans);        
    }
    cout << ans << "\n";
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