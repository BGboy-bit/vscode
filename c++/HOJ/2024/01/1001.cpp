#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1048888;  
string txt, pat;
ll nxt[MAX];

void Solve() {
    ll ans = 0;
    cin >> pat >> txt;
    //make next
    nxt[0] = -1;
    for(ll i = 1, j = -1; i < pat.size(); i ++ ) {
        while(j != -1 && pat[i] != pat[j + 1]) j = nxt[j];
        if(pat[i] == pat[j + 1]) j ++ ;
        nxt[i] = j;
    } 
    vector<ll> pos(txt.size() * 2, 0); // pos为pat最后一位
    //kmp    
    for(ll i = 0, j = -1; i < txt.size(); i ++ ) {
        while(j != -1 && txt[i] != pat[j + 1]) j = nxt[j];
        if(txt[i] == pat[j + 1]) j ++ ;
        if(j == pat.size() - 1) {
            // pos[i] = 1;
            if(pos[i] != 1) {
                ans ++ ;
                pos[i] = 1;
            }
            for(ll k = i + 1; k < txt.size() && k < i + pat.size(); k ++ ) {  // 向后匹配
                if(txt[k] == pat[k - i - 1]) {
                    ans ++ ;
                    pos[k] = 1;
                }
                else break;
            }
            for(ll k = i - j - 1, poss = pat.size() - 1; k >= 0 && pos[k + pat.size() - 1] != 1; k --, poss -= 1) { // 向前匹配
                if(poss == -1) poss = pat.size() - 1;
                if(txt[k] == pat[poss]) ans ++ ;
                else break;
            }
        } else {
            if(i < txt.size() - 1 && txt[i + 1] != pat[j + 1] && j != -1 || i == txt.size() - 1) {
                bool ff = 0;
                ll cnt = 0;
                for(ll k = i - j - 1, poss = pat.size() - 1; k >= 0 && pos[k + pat.size() - 1] != 1; k -- , poss -= 1) {
                    if(poss == -1) poss = pat.size() - 1;
                    if(txt[k] != pat[poss]) break;
                    cnt ++ ;
                    if(cnt + j == pat.size() - 1) {
                        ans ++ ; ff = 1;
                        pos[k + pat.size() - 1] = 1;
                    }
                    else if(ff) {
                        ans ++ ;
                        pos[k + pat.size() - 1] = 1;
                    }
                }
            }
        }
    } 
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T; cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}