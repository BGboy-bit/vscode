#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n + 1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int maxn = 2e5 + 10;
bool multi = 0;

const int ALPH = 26;

struct Trie {
    int nxt[ALPH];
    Trie() {
        memset(nxt, -1, sizeof(nxt));
    }
};

void Solve() {
    ll n, m; cin >> n >> m;
    vector<string> s(n + 1);
    ll maxx = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> s[i];
        maxx = max(maxx, (ll)s[i].size());
    }
    vector<Trie> trie;
    trie.push_back(Trie());
    int tot = 1;

    for (auto &w: s) {
        int cur = 0; 
        for (char c: w) {
            int cidx = c - 'a';
            if (trie[cur].nxt[cidx] < 0) {
                trie[cur].nxt[cidx] = tot;
                trie.push_back(Trie());
                tot ++ ;
            }
            cur = trie[cur].nxt[cidx];
        }
    }
    ll ans = 2 * (tot - 1) - maxx;
    cout << ans << "\n";
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