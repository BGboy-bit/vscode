#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const int MAX = 1e5 + 10;

ll n, k;
string str;

void Solve() {
    cin >> n >> k;
    ll K = k;
    cin >> str;
    bool ff = 0;
    for(ll i = 0; i < n; i ++ ) {
        if(str[i] == '0') {
            if(!ff) {
                k -- ;
                ff = 1;
            }
            str[i] = '1';
        } else {
            ff = 0;
            if(k == 0) break;
        }
    }
    if(n == 1 && k % 2 == 1) str[0] = '0';
    if(K == k && k == 1) str[n - 1] = '0';
    cout << str << "\n";
} 


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}
