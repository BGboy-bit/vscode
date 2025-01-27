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
bool multi = 0;

string S = "nowcoder";

void Solve() {
    string s; cin >> s;
    map<char, ll> mp;
    ll cnt = 0;
    for(auto i : s) {
        for(auto j : S) {
            if(i == j) {
                if(i == 'o') {
                    if(mp[i] <= 1) {
                        cnt ++ ; mp[i] ++ ;   
                    }
                } else if(mp[i] == 0) {
                    cnt ++ ; mp[i] ++ ;
                }
                break;
            }
        }
    }
    if(cnt == 8) {
        cout << "happy new year" << "\n";
    } else {
        cout << "I AK IOI" << "\n";
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