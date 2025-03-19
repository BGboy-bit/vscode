#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1e6 + 10;

ll nxt[MAX], nxt1[MAX];

void Solve() {
    string pat, txt;
    cin >> txt >> pat;
    nxt[0] = -1; 
    for(ll i = 1, j = -1; i < pat.size(); i ++ ) {
        while(j != -1 && pat[i] != pat[j + 1]) j = nxt[j];
        if(pat[i] == pat[j + 1]) nxt[i] = nxt[ ++ j] ; 
        if(pat[i + 1] != pat[j + 1] || pat[i] != pat[j]) nxt[i] = j;

    }

    // nxt1[0] = -1; 
    //     for(ll i = 1, j = -1; i < pat.size(); i ++ ) {
    //     while(j != -1 && pat[i] != pat[j + 1]) j = nxt1[j];
    //     if(pat[i] == pat[j + 1]) j ++ ;
    //     nxt1[i] = j;
    // }


    for(ll i = 0, j = -1; i < txt.size(); i ++ ) {
        while(j != -1 && txt[i] != pat[j + 1]) j = nxt[j];
        if(txt[i] == pat[j + 1]) j ++ ;
        if(j == pat.size() - 1) cout << i - j + 1 << "\n";
    }

    // for(ll i = 0; i < pat.size(); i ++ ) cout << nxt1[i] + 1 << " ";
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