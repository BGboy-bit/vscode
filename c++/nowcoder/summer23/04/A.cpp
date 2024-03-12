#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1e6 + 10;

ll n;
string pat;
ll nxt[MAX], nxt1[MAX];
void Solve() {
    cin >> n >> pat;
    nxt[0] = 0; 
    for(ll i = 1, j = 0; i < pat.size(); i ++ ) {
        while(j != 0 && pat[i] != pat[j]) j = nxt[j - 1];

        // if(pat[i] == pat[j]) j ++ ;
        // nxt[i] = j;
        
        bool b = pat[i] == pat[j], c = pat[i + 1] == pat[j + 1];
        if(b) nxt[i] = nxt[j ++ ] ; 
        if(!b || !c) nxt[i] = j;

    }
    //kmp 
    string s1(n, '0');
    string s2(n, '1');
    string txt = pat + s1 + pat; 
    ll cnt = 0;
    for(ll i = 0, j = 0; i < txt.size(); i ++ ) {
        while(j != 0 && txt[i] != pat[j]) j = nxt[j - 1];
        if(txt[i] == pat[j]) j ++ ;
        if(j == pat.size())  cnt ++ ;
    }
    if(cnt == 2) cout << s1 << "\n";
    else cout << s2 << "\n";
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