#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e6 + 10;  
string txt, pat;
ll nxt[MAX];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> txt >> pat;

    //make next
    nxt[0] = -1;
    for(ll i = 1, j = -1; i < pat.size(); i ++ ) {
        while(j != -1 && pat[i] != pat[j + 1]) j = nxt[j];
        if(pat[i] == pat[j + 1]) j ++ ;
        nxt[i] = j;
    } 

    //kmp    
    for(ll i = 0, j = -1; i < txt.size(); i ++ ) {
        while(j != -1 && txt[i] != pat[j + 1]) j = nxt[j];
        if(txt[i] == pat[j + 1]) j ++ ;
        if(j == pat.size() - 1) cout << i - j + 1 << "\n";
    } 

    for(ll i = 0; i < pat.size(); i ++ ) cout << nxt[i] + 1 << " ";
    return 0;
}