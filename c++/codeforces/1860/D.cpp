#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 200;
bool multi = 0;//∂‡◊È ‰»Î
string str;

bool check() {
    vector<ll> a(str.length() + 2, 0), b(str.length() + 1, 0); 
    ll cnt1 = 0, cnt2 = 0;
    for(ll i = 1; i < str.length(); i ++ ) {
            if(str[i] == '0') a[i] = a[i - 1] + 1;
            else a[i] = a[i - 1];
    }
    for(ll i = str.length() - 1; i >= 1; i -- ) {
        if(str[i] == '0') b[i] = b[i + 1] + 1;
        else b[i] = b[i + 1];
    }
    for(ll i = 1; i < str.length(); i ++ ) {
        if(str[i] == '1') {
            cnt1 += a[i], cnt2 += b[i];
        }
    }
    if(cnt1 == cnt2) return true;
    else return false;
}

void Solve() {
    
    cin >> str;
    str = "?" + str; 
    // do {
    //     vector<ll> a(str.length() + 2, 0), b(str.length() + 1, 0); 
    //     ll cnt1 = 0, cnt2 = 0;
    //     for(ll i = 1; i < str.length(); i ++ ) {
    //         if(str[i] == '0') a[i] = a[i - 1] + 1;
    //         else a[i] = a[i - 1];
    //     }
    //     for(ll i = str.length() - 1; i >= 1; i -- ) {
    //         if(str[i] == '0') b[i] = b[i + 1] + 1;
    //         else b[i] = b[i + 1];
    //     }
    //     for(ll i = 1; i < str.length(); i ++ ) {
    //         if(str[i] == '1') {
    //             cnt1 += a[i], cnt2 += b[i];
    //         }
    //     }
    //     if(cnt1 == cnt2) {cout << "Yes" << "\n" << str << "\n"; break;}
    // }while(next_permutation(str.begin(), str.end()));
    if(check) {cout << "0" << "\n"; return; }
    for(ll i = 1; i < str.length(); i ++ ) {
        if(str[i] == '1') {
            for(ll j = 1; j < str.length(); j ++ ) {
                if(str[j] == '0') {
                    swap(str[i], str[j]);
                    if(check()) {cout << "1" << "\n"; return ; }
                }
            }
        }
    }
    ll cnt1 = 0, cnt0 = 0;
    for(ll i = 1; i < str.length(); i ++ ) {
        if(str[i] == '1') cnt1 ++ ;
        else cnt0 ++ ;
    }
    if(cnt1 % 2 == 0) {
        ll ans1 = 0, ans2 = 0;
        for(ll i = 1; i <= cnt1 / 2; i ++ ) {
            if(str[i] != '1') ans1 ++ ; 
        }
        for(ll i = str.length() - 1; i >= str.length() - 1 - cnt1 / 2; i -- ) {
            if(str[i] != '1') ans1 ++ ;
        }
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