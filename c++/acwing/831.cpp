#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;
const int M = 1e6 + 10;
string txt, pat;
ll n, m;
ll nxt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> pat >> m >> txt;
    
    //make next
    nxt[0] = -1;
    for(ll i = 1, j = -1; i < n; i ++ ) {
        while(j != -1 && pat[i] != pat[j + 1]) j = nxt[j];
        if(pat[i] == pat[j + 1]) j ++ ;
        nxt[i] = j;
    }

    //kmp
    for(ll i = 0, j = -1; i < m; i ++ ) {
        while(j != -1 && txt[i] != pat[j + 1]) j = nxt[j];
        if(txt[i] == pat[j + 1]) j ++ ;
        //accept 
        if(j == n - 1) {
            cout << i - j << " ";
            j = nxt[j];
        }
    }
    return 0;
}