#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int MAX = 2e5 + 10;
ll a[MAX];
int n, k;
ll ans = INT_MAX;
queue<ll> q;
ll maxx;

void clear(queue<ll>& q) {
    queue<ll> empty;
    swap(empty, q);
}

ll bfs(vector<ll> &b, ll x) {
    clear(q);
    ll sum = b[x];
    ll cnt = 1; //层数
    ll cnt1 = 0;//记录是否到下一层
    ll ans = 0;
    if(sum >= k) return ans;
    if(x * 2 - 1 < maxx && x * 2 - 1 != x) q.push(x * 2 - 1);
    if(x * 2 < maxx) q.push(x * 2);
    while(sum < k && !q.empty()) {
        ll y = q.front();
        if(b[y] < k - sum) {
            sum += b[y];
            ans += cnt * b[y];
        }
        else {
            ans += cnt * (k - sum);
            return ans;
        }
        q.pop();
        if(y * 2 - 1 < maxx) q.push(y * 2 - 1);
        if(y * 2 < maxx) q.push(y * 2);
        cnt1 ++;
        if(cnt1 % 2 == 0) cnt ++;
    }
    return INT_MAX;
}

void Solve() {

    cin >> n >> k;
    vector<ll> b(MAX, 0);
    for(ll i = 0; i < n; i ++ ) {
        cin >> a[i];
        b[a[i]] ++;
        maxx = max(maxx, a[i]);
    }
    for(ll i = 0; i < n; i ++ ) {
        ans = min(bfs(b, a[i]), ans);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    int T = 1;
    //cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}