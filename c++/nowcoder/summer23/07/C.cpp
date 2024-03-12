#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1e6 + 10;
bool multi = 1;//¶à×éÊäÈë

ll bit[40];
ll n, k;
ll a[MAX];


void Solve() {
    cin >> n >> k;
    ll res = -1;
    bool wa = 0;
    vector<bool> ff(40, 0);
    vector<ll> b(n + 1, 0);
    vector<ll> c, d;
    ll maxx = 0;
    ll cnt = 0;
    for(ll i = 1; i < n; i ++ ) {
        cin >> a[i]; maxx = max(a[i], maxx);
        ll x = a[i];
        for(ll i = 30; i >= 0; i -- ) {
            if(x >= bit[i]) {
                x -= bit[i];
                ff[i] = 1;
            }
        }
    }
    ll summ = 0;
    for(ll i = 30; i >= 0; i -- ) {
        if(maxx >= bit[i]) {
            maxx = bit[i + 1] - 1;
            cnt = i + 1; summ = i + 1;
            for(ll j = 0; j < cnt; j ++ ) {
                if(!ff[j]) c.push_back(bit[j]); summ -- ;
            } 
            if(bit[30 - summ] < k) {cout << "-1" << "\n"; return ;} 
            for(ll i = cnt; i <= 30; i ++ ) c.push_back(bit[i]);
            break;
        }
    }
    ll x = a[1], y = a[2];
    for(ll j = 30; j >= 0; j -- ) {
        if(x == a[1] && x > bit[j] && y == a[2] && y > bit[j]) {cout << "-1" << "\n"; return ;}
        else if(x >= bit[j] && y >= bit[j]) if(a[1] > a[2] && b[1] == 0) b[1] += bit[j];
        if(x >= bit[j]) x -= bit[j];
        if(y >= bit[j]) y -= bit[j];
    }
    // if(a[1] > a[2]) b[1] = a[2];
    for(ll i = 1; i < n; i ++ ) {
        bitset<40> B1(a[i]);
        bitset<40> B2(b[i]);
        string b1 = B1.to_string();
        string b2 = B2.to_string();
        for(ll j = b1.size() - 1; j >= 0; j -- ) {
            if(b1[j] != b2[j]) b[i + 1] += bit[b1.size() - 1 - j];
        }
        if(b[i + 1] == maxx && i != n - 1 || b[i + 1] < b[i]) {cout << "-1" << "\n"; return ;}   
    } 

    k -- ;
    if(k % 2 != 0) {d.push_back(0); k -- ;}
    for(ll i = 1; i <= 30; i ++ ) {
        if(k == 0) break;
        if(k % bit[i] == 0) {
            k -= bit[i]; d.push_back(i);
        }
    }
    for(ll i = 1; i <= n; i ++ ) {
        for(auto j : d) {
            b[i] += c[j];
        }
    }
    for(ll i = 1; i <= n; i ++ ) cout << b[i] << " ";
    cout << "\n";    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    bit[0] = 1;
    for(ll i = 1; i <= 30; i ++ ) bit[i] = bit[i - 1] * 2; 
    ll T = 1;
    if(multi) cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}