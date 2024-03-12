#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1e6 + 10;
bool multi = 0;//多组输入

ll ksm(ll a ,ll k) //a代表底数，k代表大指数
{
    ll rec = 1;
    while(k)
    {
        if (k & 1)
            rec = rec * a % mod;
        k >>= 1;
        a = a * a % mod;
    }
    return rec;
}

void Solve() {
    ll m;
    string s, t;
    cin >> m >> s >> t;
    ll ls = s.size(), lt = t.size();
    //s与t的长度和为奇数没有答案
    if((ls + lt) % 2 == 1) {
        for(ll i = 1; i <= m; i ++ ) cout << "0 ";
        cout << "\n"; return ;
    }
    //s和t的长度相等，则每一位都任意
    else if(ls == lt) {
        for(ll i = 1; i <= m; i ++ ) cout << ksm(26, i) <<" ";
        cout << "\n"; return ;
    }
    //s的长度大于t
    else if(ls > lt) {
        //t在s上对应的位置始终相等      
        for(ll j = ls -  (ls - lt) / 2, k = lt; k >= 1; j -- , k -- ) {
            if(s[j - 1] != t[k - 1]) {
                for(ll i = 1; i <= m; i ++ )
                cout << "0 "; 
                cout << "\n"; return ;
            }
        }
        for(ll i = 1; i <= m; i ++ ) {
            if(i < (ls - lt) / 2) {
                bool ff = 0;
                for(ll j = ls - ((ls - lt) / 2 - i), k = 0; j < ls; j ++ , k ++ ) {
                    if(s[j] != s[k]) {
                        cout << "0 "; ff = 1; break;    
                    } 
                }
                if(!ff) cout << "1 ";
            }
            else {
                cout << ksm(26, i - (ls - lt) / 2) << " ";
            }
        }
        cout << "\n";
    }

    else if(lt > ls) {
        for(ll j = lt -  (lt - ls) / 2, k = ls; k >= 1; j -- , k -- ) {
            if(t[j - 1] != s[k - 1]) {
                for(ll i = 1; i <= m; i ++ )
                cout << "0 "; 
                cout << "\n"; return ;
            }
        }
        for(ll i = 1; i <= m; i ++ ) {
            if(i < (lt - ls) / 2) {
                bool ff = 0;
                for(ll j = lt - ((lt - ls) / 2 - i), k = 0; j < lt; j ++ , k ++ ) {
                    if(t[j] != t[k]) {
                        cout << "0 "; ff = 1; break;    
                    } 
                }
                if(!ff) cout << "1 ";
            }
            else {
                cout << ksm(26, i - (lt - ls) / 2) << " ";
            }
        }
        cout << "\n";
    } 
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}