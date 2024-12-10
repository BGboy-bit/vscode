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

void Solve() {
    ll n; cin >> n;
    string s; cin >> s;
    vector<ll> a(26);
    for(ll i = 0; i < n; i ++ ) {
        a[s[i] - 'a'] ++ ;
    }
    ll maxx = 0, maxc, minn = maxn, minc, cnt = 0;
    for(ll i = 0; i < 25; i ++ ) {
        if(a[i] == 0) continue;
        cnt ++ ;
        if(maxx < a[i]) {
            maxx = a[i]; maxc = i;
        }
        if(minn > a[i]) {
            minn = a[i]; minc = i;
        }
    }
    if(maxc == minc && cnt > 1) {
        ll ans1 = 1, ans2 = 1, sum = maxx;
        for(ll i = 0; i < 26; i ++ ) {
            if(a[i] == 0) continue;
            if(i == maxc) continue;
            ans1 *= (sum + 1) * a[i];
            sum += a[i];
        }
        sum = maxx + 1;
        bool ff = 0;
        for(ll i = 0; i < 26; i ++ ) {
            if(a[i] == 0) continue;
            if(i == maxc) continue;
            if(!ff) {
                ans2 *= (sum + 1) * (a[i] - 1);
                sum += a[i] - 1;
                ff = 1; 
                continue;
            }
            ans2 *= (sum + 1) * a[i];
            sum += a[i]; 
        }
        if(ans1 > ans2) {
            for(ll i = 0; i < n; i ++ ) {
                if(s[i] - 'a' != maxc) {
                    s[i] = maxc + 'a'; break;
                }
            }
        }
    } else {
        ll ans1 = 1, ans2 = 1, sum = maxx;
        for(ll i = 0; i < 26; i ++ ) {
            if(a[i] == 0) continue;
            if(i == maxc) continue;
            ans1 *= (sum + 1) * a[i];
            sum += a[i];
        }
        sum = maxx + 1;
        bool ff = 0;
        for(ll i = 0; i < 26; i ++ ) {
            if(a[i] == 0) continue;
            if(i == maxc) continue;
            if(i == minc && !ff) {
                ans2 *= (sum + 1) * (a[i] - 1);
                sum += a[i] - 1;
                ff = 1; 
                continue;
            }
            ans2 *= (sum + 1) * a[i];
            sum += a[i]; 
        }
        if(ans1 > ans2) {
            for(ll i = 0; i < n; i ++ ) {
                if(s[i] - 'a' == minc) {
                    s[i] = 'a' + maxc;
                    break;
                }
            }
        }
    }
    cout << s << "\n";
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