#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n + 1);
const ll inf = 2e16 + 10;
const int mod = 998244353;
const int maxn = 2e5 + 10;
bool multi = 0;

struct Node {
    ll x, y;
    char c;
}e[maxn];

void Solve() {
    ll n; cin >> n;
    for(ll i = 1; i <= n;i ++ ) {
        ll x, y; char c;
        cin >> x >> y >> c;
        c += 'a' - 'A';
        e[i].x = x; e[i].y = y; e[i].c = c;
    }
    ll maxxn = -inf, maxxs = inf, maxxw = inf, maxxe = -inf;
    // ll maxen = -inf, maxes = inf, maxws = inf, maxwn = -inf;
    // ll maxne = -inf, maxnw = inf, maxsw = inf, maxse = -inf; 
    ll N = 0, S = 0, W = 0, E = 0; 
    for(ll i = 1; i <= n; i ++ ) {
        ll x = e[i].x, y = e[i].y; char c = e[i].c;
        if(x > maxxe) {
            maxxe = x; E = 0; // maxen = -inf, maxes = inf;
        }
        if(x < maxxw) {
            maxxw = x; W = 0; // maxwn = -inf, maxws = inf;
        }
        if(y > maxxn) {
            maxxn = y; N = 0; // maxne = -inf, maxnw = inf;
        }
        if(y < maxxs) {
            maxxs = y; S = 0; // maxse = -inf, maxsw = inf;
        }
        if(x == maxxe) {
            if(c == 'e') E = 1;
            if((c == 'n' || c == 's')) {
                if(E <= 0) E = 2;
                // if(c == 'n') maxen = max(maxen, y);
                // if(c == 's') maxes = min(maxes, y);
            }
            if(c == 'w' && E == 0) E = -1;
        }
        if(x == maxxw) {
            if(c == 'w') W = 1;
            if((c == 'n' || c == 's')) {
                if(W <= 0) W = 2; 
                // if(c == 'n') maxwn = max(maxwn, y);
                // if(c == 's') maxws = min(maxws, y);
            }
            if(c == 'e' && W == 0) W = -1;
        }
        if(y == maxxn) {
            if(c == 'n') N = 1;
            if((c == 'e' || c == 'w')) {
                if(N <= 0) N = 2;
                // if(c == 'e') maxne = max(maxne, x);
                // if(c == 'w') maxnw = min(maxnw, x);
            }
            if(c == 's' && N == 0) N = -1;
        }
        if(y == maxxs) {
            if(c == 's') S = 1;
            if((c == 'e' || c == 'w')) {
                if(S <= 0) S = 2;
                // if(c == 'e') maxse = max(maxne, x);
                // if(c == 'w') maxsw = min(maxsw, x);
            }
            if(c == 'n' && S == 0) S = -1;
        }
    }
    // cout << "max N: " << maxxn << ", direct: " << N << "\n"; 
    // cout << "max S: " << maxxs << ", direct: " << S << "\n"; 
    // cout << "max E: " << maxxe << ", direct: " << E << "\n";
    // cout << "max W: " << maxxw << ", direct: " << W << "\n";
    // cout << "N max e:" << maxne << ", max w:" << maxnw << "\n";
    // cout << "S max e:" << maxse << ", max w:" << maxsw << "\n";
    // cout << "E max n:" << maxen << ", max s:" << maxes << "\n";
    // cout << "W max n:" << maxwn << ", max s:" << maxws << "\n";
    ll ans = 2 * (maxxn - maxxs + maxxe - maxxw);
    ll cnt = 0;
    if(N == 1) cnt ++ ; if(N == -1) cnt -- ; if(S == 1) cnt ++ ; if(S == -1) cnt -- ; 
    if(W == 1) cnt ++ ; if(W == -1) cnt -- ; if(E == 1) cnt ++ ; if(E == -1) cnt -- ;
    if(cnt >= 0) {
        cout << ans << "\n";
        return ;
    }
    ll maxee = -inf, maxss = inf, maxww = inf, maxnn = -inf;
    ll maxnt = -inf, maxst = inf, maxwt = inf, maxet = -inf;
    for(ll i = 1; i <= n; i ++ ) {
        ll x = e[i].x, y = e[i].y; char c = e[i].c;
        if(c == 'e') maxee = max(maxee, x);
        if(c == 'w') maxww = min(maxww, x);
        if(c == 'n') maxnn = max(maxnn, y);
        if(c == 's') maxss = min(maxss, y);
        if(x < maxxe && (c == 'n' || c == 's')) maxet = max(maxet, x);
        if(x > maxxw && (c == 'n' || c == 's')) maxwt = min(maxwt, x);
        if(y < maxxn && (c == 'e' || c == 'w')) maxnt = max(maxnt, y);
        if(y > maxxs && (c == 'e' || c == 'w')) maxst = min(maxst, y);
    }
    ll cntN = min((maxxn - maxnn) / 2, maxxn - maxnt); 
    ll cntE = min((maxxe - maxee) / 2, maxxe - maxet);
    ll cntW = min((maxww - maxxw) / 2, maxwt - maxxw);
    ll cntS = min((maxss - maxxs) / 2, maxst - maxxs);

    ll cntt = inf;
    vector<ll> a;
    if(N == -1) a.push_back(cntN); 
    if(E == -1) a.push_back(cntE);
    if(S == -1) a.push_back(cntS);
    if(W == -1) a.push_back(cntW);
    sort(a.begin(), a.end());
    for(ll i = 0; i < a.size(); i ++ ) {
        if(i > 0) a[i] -= a[i - 1];
        ans += cnt * a[i] * 2;
        cnt += 2;
        if(cnt >= 0) break;
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