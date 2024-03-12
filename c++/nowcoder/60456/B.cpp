#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double db;

const int MAX = 1e5 + 10;
// pair<ll, ll> p[MAX];
struct node {
    ll first;
    ll second;
}p[MAX];

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    ll n;
    // cin >> n;
    scanf("%lld", &n);
    for(ll i = 1; i <= n; i ++ ) {
        ll x;
        // cin >> x;
        scanf("%lld", &x);
        p[i].first = x;
    }
    //string s;
    //cin >> s;
    char s[MAX];
    getchar();
    fgets(s, n + 1, stdin);
    // printf("%s\n", s);
    for(ll i = 0; i < n; i ++ ) {
        if(s[i] == 'R') p[i + 1].second = 1;
        else p[i + 1].second = 0;
    }
    ll ans = 0;
    for(ll i = 2;i <= n;) {
        if(p[i - 1].second != p[i].second) {
            ll vis, cnt = p[i - 1].first + p[i].first;
            for(ll j = i + 1; j <= n; j ++ ) {
                if(p[j - 1].second == p[j].second) {
                    vis = j - 1;
                    break;
                }
                cnt += p[j].first;
                if(j == n) vis = n;
            }
            ans += cnt;
            if((vis - i + 2) % 2 != 0) {
                if(p[vis].first > p[i - 1].first) ans -= p[i - 1].first;
                else ans -= p[vis].first;
            }
            i = vis + 1;
        }
        else i ++ ;
    }
    //cout << ans << "\n";
    printf("%lld\n", ans);
    return 0;
}