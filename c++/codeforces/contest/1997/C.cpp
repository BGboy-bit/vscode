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
    s = " " + s; 
    stack<ll> q;
    ll sum = 0;
    for(ll i = 1; i <= n; i ++ ) {
        if(i % 2 == 1) {
            if(!q.empty()) {
                ll x = q.top();
                sum += i - x;
                q.pop();
                s[i] = ')';
            } else {
                if(s[i + 1] == ')') {
                    sum ++ ;
                } else {
                    q.push(i), q.push(i + 1);
                }
            } 
        } else {
            if(s[i] == ')' && !q.empty()) {
                ll x = q.top();
                sum += i - x;
                q.pop();                
            } else if(s[i] == '(' && s[i - 1] == ')') q.push(i);
        }
    }
    cout << sum << '\n';
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