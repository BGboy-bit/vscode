#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n + 1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int maxn = 2e5 + 10;
bool multi = 1;

struct Node {
    ll a, b, w1, w2;
};

bool cmp(Node x, Node y) {
    if(x.a == y.a) 
        return x.b < y.b;
    else 
        return x.a < y.a;
}

bool cmp1(Node x, Node y) {
    return x.w < y.w;
}

void Solve() {
    ll n, k; cin >> n >> k; 
    vector<Node> d(n + 1), e(n + 1);
    ll summ = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> d[i].a >> d[i].b;
        e[i].w1 = d[i].a + d[i].b;
        e[i].w2 = d[i].a * d[i].b;  
        if(d[i].a > d[i].b) swap(d[i].a, d[i].b);
        summ += d[i].a + d[i].b;
    }
    if(summ < k) {
        cout << "-1\n"; return ;
    }
    ll ans = 0;
    sort(d.begin() + 1, d.end(), cmp);
    for(ll i = 1; i <= n; i ++ ) {
        ll a = d[i].a, b = d[i].b;
        if(a == 1 && b == 1) {
            ans += 1;
            k -= 2;
            if(k <= 0) {
                cout << ans << "\n"; return ;
            }
        } else if(a == 1 && b == 2) {
            ans += 1;
            k -= 1;
            if(k <= 0) {
                cout << ans << "\n"; return ;
            }
            ans += 1;
            k -= 2;
            if(k <= 0) {
                cout << ans << "\n"; return ;
            }
        }
        else  {
            for(ll j = 1; j <= b - a + 1; j ++ ) {
                ans += a;
                k -- ;
                if(k <= 0) {
                    cout << ans << "\n"; return ;
                }
            }
     
            for(ll j = a - 1, cnt = 0; j >= 2; ) {
                ans += j;
                k -- ;
                cnt += 1;
                if(k <= 0) {
                    cout << ans << "\n"; return ;
                }
                if(cnt == 2) {
                    cnt = 0; j -- ;
                }
            }
            ans += 1;
            k -= 1;
            if(k <= 0) {
                cout << ans << "\n"; return; 
            }
            ans += 1;
            k -= 2;
            if(k <= 0) {
                cout << ans << "\n"; return; 
            }
        }
    }
}


signed main() {
    // freopen("test.in","r",stdin);  
    // freopen("code.out","w",stdout);    
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}