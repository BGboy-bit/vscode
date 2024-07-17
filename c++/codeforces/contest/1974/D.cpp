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
bool multi = 1;

void Solve() {
    ll n; cin >> n;
    string str; cin >> str;
    ll sum1 = 0, sum2 = 0;
    for(ll i = 0; i < n; i ++ ) {
        if(str[i] == 'N') sum1 ++ ;
        else if(str[i] == 'S') sum1 -- ;
        else if(str[i] == 'E') sum2 ++ ;
        else if(str[i] == 'W') sum2 -- ;

    }
    if(sum1 % 2 != 0 || sum2 % 2 != 0 || n == 2 && sum1 == 0 && sum2 == 0) {
        cout << "NO" << "\n";
        return ;
    }
    ll sa1 = 0, sa2 = 0, sb1 = 0, sb2 = 0;
    ll sum11 = 0, sum22 = 0;
    // bool f11 = false, f12 = false, f21 = false, f22 = false;
    for(ll i = 0; i < n; i ++ ) {
        if(str[i] == 'N') {
            if(sa1 < sum1 / 2 || sum1 == 0 &&  (sum11 == 0 || sa1 == -1) && sum22 == 0) {
                cout << 'R'; sa1 ++ ; sum11 ++ ;
            } else {
                cout << 'H'; sb1 ++ ;
            }
        } 
        else if(str[i] == 'S') {
            if(sa1 > sum1 / 2 || sum1 == 0 && (sum11 == 0 || sa1 == 1) && sum22 == 0) {
                cout << 'R'; sa1 -- ; sum11 ++ ;
            } else {
                cout << 'H'; sb1 -- ;
            }
        } 
        else if(str[i] == 'E') {
            if(sa2 < sum2 / 2 || sum2 == 0 && (sum22 == 0 || sa2 == -1) && sum11 == 0) {
                cout << "R"; sa2 ++ ; sum22 ++ ;
            } else {
                cout << 'H'; sb2 ++ ;
            }
        }
        else if(str[i] == 'W') {
            if(sa2 > sum2 / 2 || sum2 == 0 && (sum22 == 0 || sa1 == 1) && sum11 == 0) {
                cout << 'R'; sa2 -- ; sum22 ++ ;
            } else {
                cout << 'H'; sb2 -- ;
            }
        }
    }
    cout << "\n";
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