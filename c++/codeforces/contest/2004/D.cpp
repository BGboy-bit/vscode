#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n + 1);
const ll inf = 100000000000;
const int mod = 998244353;
const int maxn = 2e5 + 10;
bool multi = 1;

vector<ll> BR1(maxn), BG1(maxn), BY1(maxn), GR1(maxn), RY1(maxn), GY1(maxn);
vector<ll> BR2(maxn), BG2(maxn), BY2(maxn), GR2(maxn), RY2(maxn), GY2(maxn);
ll x, y; 

ll ac(string aa) {
    ll ans = inf;
    if(aa == "BR") {
        if(BR1[y] != -1) ans = min(abs(BR1[y] - y) + abs(BR1[y] - x), ans);  
        if(BR2[x] != -1) ans = min(abs(BR2[x] - y) + abs(BR2[x] - x), ans);
    }
    if(aa == "BY") {
        if(BY1[y] != -1) ans = min(abs(BY1[y] - y) + abs(BY1[y] - x), ans);  
        if(BY2[x] != -1) ans = min(abs(BY2[x] - y) + abs(BY2[x] - x), ans);
    }
    if(aa == "BG") {
        if(BG1[y] != -1) ans = min(abs(BG1[y] - y) + abs(BG1[y] - x), ans);  
        if(BG2[x] != -1) ans = min(abs(BG2[x] - y) + abs(BG2[x] - x), ans);
    }
    if(aa == "GY") {
        if(GY1[y] != -1) ans = min(abs(GY1[y] - y) + abs(GY1[y] - x), ans);  
        if(GY2[x] != -1) ans = min(abs(GY2[x] - y) + abs(GY2[x] - x), ans);
    }
    if(aa == "RY") {
        if(RY1[y] != -1) ans = min(abs(RY1[y] - y) + abs(RY1[y] - x), ans);  
        if(RY2[x] != -1) ans = min(abs(RY2[x] - y) + abs(RY2[x] - x), ans);
    }
    if(aa == "GR") {
        if(GR1[y] != -1) ans = min(abs(GR1[y] - y) + abs(GR1[y] - x), ans);  
        if(GR2[x] != -1) ans = min(abs(GR2[x] - y) + abs(GR2[x] - x), ans);
    }
    if(ans == -1) ans = inf;
    return ans;
}

void Solve() {
    ll n, m; cin >> n >> m;
    vector<string> a(n + 1);

    ll br = -1, bg = -1, by = -1, GR = -1, ry = -1, gy = -1;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        if(a[0] > a[1]) swap(a[0], a[1]);
    }
    for(ll i = 1; i <= n; i ++ ) {
        if(a[i] == "BR") {
            BR1[i] = i; br = i;
            BG1[i] = bg; BY1[i] = by; GR1[i] = GR; RY1[i] = ry; GY1[i] = gy;
        }
        if(a[i] == "BY") {
            BY1[i] = i; by = i;
            BG1[i] = bg; BR1[i] = br; GR1[i] = GR; RY1[i] = ry; GY1[i] = gy;
        }
        if(a[i] == "BG") {
            BG1[i] = i; bg = i;
            BY1[i] = by; BR1[i] = br; GR1[i] = GR; RY1[i] = ry; GY1[i] = gy;
        }
        if(a[i] == "GR") {
            GR1[i] = i; GR = i;
            BY1[i] = by; BR1[i] = br; BG1[i] = bg; RY1[i] = ry; GY1[i] = gy;
        }
        if(a[i] == "RY") {
            RY1[i] = i; ry = i;
            BY1[i] = by; BR1[i] = br; BG1[i] = bg; GR1[i] = GR; GY1[i] = gy;
        }
        if(a[i] == "GY") {
            GY1[i] = i; gy = i;
            BY1[i] = by; BR1[i] = br; BG1[i] = bg; GR1[i] = GR; RY1[i] = ry;
        }
    }
    br = -1, bg = -1, by = -1, GR = -1, ry = -1, gy = -1;
    for(ll i = n; i >= 1; i -- ) {
        if(a[i] == "BR") {
            BR2[i] = i; br = i;
            BG2[i] = bg; BY2[i] = by; GR2[i] = GR; RY2[i] = ry; GY2[i] = gy;
        }
        if(a[i] == "BY") {
            BY2[i] = i; by = i;
            BG2[i] = bg; BR2[i] = br; GR2[i] = GR; RY2[i] = ry; GY2[i] = gy;
        }
        if(a[i] == "BG") {
            BG2[i] = i; bg = i;
            BY2[i] = by; BR2[i] = br; GR2[i] = GR; RY2[i] = ry; GY2[i] = gy;
        }
        if(a[i] == "GR") {
            GR2[i] = i; GR = i;
            BY2[i] = by; BR2[i] = br; BG2[i] = bg; RY2[i] = ry; GY2[i] = gy;
        }
        if(a[i] == "RY") {
            RY2[i] = i; ry = i;
            BY2[i] = by; BR2[i] = br; BG2[i] = bg; GR2[i] = GR; GY2[i] = gy;
        }
        if(a[i] == "GY") {
            GY2[i] = i; gy = i;
            BY2[i] = by; BR2[i] = br; BG2[i] = bg; GR2[i] = GR; RY2[i] = ry;
        }
    }
    while(m -- ) {
        cin >> x >> y;
        if(x >= y) swap(x, y);
        if(a[x][0] == a[y][0] || a[x][0] == a[y][1] || a[x][1] == a[y][0] || a[x][1] == a[y][1]) {
            cout << abs(x - y) << "\n"; continue;
        }
        string a1, a2, a3, a4;
        a1 += a[x][0] ,a1 += a[y][0]; a2 += a[x][0], a2 += a[y][1]; 
        a3 += a[x][1], a3 += a[y][0]; a4 += a[x][1], a4 += a[y][1];
        if(a1[0] > a1[1]) swap(a1[0], a1[1]);
        if(a2[0] > a2[1]) swap(a2[0], a2[1]);
        if(a3[0] > a3[1]) swap(a3[0], a3[1]);
        if(a4[0] > a4[1]) swap(a4[0], a4[1]);
        ll ans = min(ac(a1), min(ac(a2), min(ac(a3), ac(a4))));
        if(ans == inf) ans = -1;
        cout << ans << "\n";
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