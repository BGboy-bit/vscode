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

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    if(a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}

void Solve() {
    ll n, k; cin >> n >> k;
    vector<pair<ll, ll>> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) cin >> a[i].first;
    for(ll i = 1; i <= n; i ++ ) cin >> a[i].second;
    sort(a.begin() + 1, a.end(), cmp);
    if(k == 0 || a[n].second == 1) {
        cout << a[n / 2].first + a[n].first + k << "\n";
        return ;
    }
    if(a[n / 2].second == 1) {
        k -= min(a[n / 2 + 1].first - a[n / 2].first, k);
        a[n / 2].first += min(a[n / 2 + 1].first - a[n / 2].first, k);
        if(k == 0) {
            cout << a[n / 2].first + a[n].first + k << "\n";
            return ;           
        }
    }
    ll summ = 0, res = 0;
    bool ff = 0;
    for(ll i = n - 1; i >= n / 2; i -- ) {
        if(a[i].second == 1) {
            summ = a[n].first - a[i].first;
            res = a[i].first;
            ff = 1;
            break;
        }
    }
    for(ll i = n / 2 - 1; i >= 1; i -- ) {
        if(a[i].second == 1) {
            if(a[n / 2].first - a[i].first >= summ) {
                cout << a[n / 2].first + a[n].first + max(0ll, k - summ) << "\n";
                return ;
            } else {
                if(a[n / 2 + 1].first > a[n / 2].first) {
                    k -= max(0ll, min(k - (a[n / 2].first - a[i].first), a[n / 2 + 1].first - a[n / 2].first));
                    a[n / 2].first += max(0ll, min(k - (a[n / 2].first - a[i].first), a[n / 2 + 1].first - a[n / 2].first));
                    res = max(res, a[n / 2].first);
                    summ = a[n].first - res;
                    if(k == 0) {
                        cout << a[n / 2].first + a[n].first + k << "\n";      
                        return ;              
                    }
                } else {
                                                                        
                }
            }
        }        
    }
    if(ff)
        cout << a[n / 2].first + a[n].first + max(0ll, k - summ) << "\n";
    else  
        cout << a[n / 2].first + a[n].first << "\n";
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