#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n+1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;//¶à×éÊäÈë

void Solve() {
    ll n; cin >> n;
    string str; cin >> str;
    bool d = 0, D = 0, f = 0,F = 0, ac = 0, AC = 0;
    for(auto i : str) {
        if(i == 'd') d = 1;
        else if(i == 'D') D = 1;
        else if(i == 'f' && d == 1) f = 1;
        else if(i == 'F' && D == 1) F = 1;
        else if(i == 's' && f == 1) ac = 1;
        else if(i == 'S' && F == 1) AC = 1; 
    }
    if(AC == 1) cout << "1 ";
    else cout << "0 ";
    if(ac == 1) cout << "1" << "\n";
    else cout << "0" << "\n";

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