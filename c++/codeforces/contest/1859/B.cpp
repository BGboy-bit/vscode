#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1e5 + 10;
bool multi = 1;//∂‡◊È ‰»Î

ll n;
ll a[MAX];

struct node {
    ll minn, minnn;
    ll x, y;
}e[MAX];

bool cmp(node u, node v) {
    return u.y < v.y;
}

void Solve() {
    cin >> n;
    vector<node> mn;
    ll summ = 0;
    ll minnnn = inf;
    for(ll i = 1; i <= n; i ++ ) {
        ll m;
        cin >> m;
        ll minn = inf, minnn = inf;
        for(ll i = 1; i <= m; i ++ ) {
            cin >> a[i];
            if(a[i] < minn) {
                if(minn < minnn) minnn = minn;
                minn = a[i];
            }
            else if(a[i] >= minn && a[i] < minnn) minnn = a[i];
        }
        minnnn = min(minn, minnnn);
        summ += minn;
        mn.push_back({minn, minnn, minnn - minn});
    }
    if(n == 1) {cout << minnnn << "\n"; return; }
    for(ll i = 0; i < n; i ++ ) {
        mn[i].y = mn[i].minn - minnnn + mn[i].x;
    }
    sort(mn.begin(), mn.end(), cmp);
    for(ll i = 0; i < n; i ++ ) {
        if(i == 0) summ -= mn[0].minn - minnnn;
        else {
            summ += mn[i].x;
        } 
    }
    cout << summ << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}