#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n + 1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int maxn = 1e6 + 10;
bool multi = 1;

ll nxt[maxn], nxt1[maxn];

void Solve() {
    string pat, txt;
    cin >> txt >> pat;
    if(txt.size() < pat.size()) swap(txt, pat);
    ll txtl = txt.size(), patl = pat.size();
    ll cnt = 0, len1 = 0, len2 = 0;
    //make next
    nxt[0] = -1;
    for(ll i = 1, j = -1; i < patl; i ++ ) {
        while(j != -1 && pat[i] != pat[j + 1]) j = nxt[j];
        if(pat[i] == pat[j + 1]) j ++ ;
        nxt[i] = j;
    }
    //kmp
    for(ll i = 0, j = -1; i < txtl; i ++ ) {
        while(j != -1 && txt[i] != pat[j + 1]) j = nxt[j];
        if(txt[i] == pat[j + 1]) j ++ ;
        if(i == txtl - 1) len1 = max(len1, j + 1);
        if(j == patl - 1) cnt ++ ; 
    }
    if(cnt > 1) {
        cout << "-1\n"; return ;
    } else if(cnt == 1) {
        cout << txt.size() << "\n"; return ;
    } else if(cnt == 0) {
        for(ll i = 0; i <= patl; i ++ ) nxt[i] = 0;
        swap(pat, txt); swap(patl, txtl);
        nxt[0] = -1;
        for(ll i = 1, j = -1; i < patl; i ++ ) {
            while(j != -1 && pat[i] != pat[j + 1]) j = nxt[j];
            if(pat[i] == pat[j + 1]) j ++ ;
            nxt[i] = j;
        }
        //kmp
        for(ll i = 0, j = -1; i < txtl; i ++ ) {
            while(j != -1 && txt[i] != pat[j + 1]) j = nxt[j];
            if(txt[i] == pat[j + 1]) j ++ ;
            if(i == txtl - 1) len2 = max(len2, j + 1);
        }
        cout << patl + txtl - max(len1, len2) << "\n";
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