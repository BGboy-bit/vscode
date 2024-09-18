#include<bits/stdc++.h>
using namespace std;
// typedef __int128 i128;
typedef double db;

const db PI = acos(-1);
typedef array<int, 2> PII; // vector<PII> a(n + 1);
const int inf = 2e18 + 10;
const int mod = 998244353;
const int maxn = 1e7;
bool multi = 1;

int pr[maxn + 10];
vector<int> prr;
int idx[maxn + 10], cnt;

void isprime() {
    for(int i = 2; i <= maxn; i ++ ) {
        if(!pr[i]) {
            pr[i] = i;
            prr.push_back(i);
        }
        for (int j = 0; j < prr.size() && prr[j] <= pr[i] && i * prr[j] <= maxn; j ++ )
            pr[i * prr[j]] = prr[j];
    }
    for(auto i : prr) {
        idx[i] = ++ cnt;
    }
}

int get(int x) {
    if(x == 1) 
        return 1; 
    x = pr[x];
    if(x == 2) 
        return 0;
    return idx[x];
}

void Solve() {
    int n; cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i ++ ) {
        int x; cin >> x;
        ans ^= get(x);
    } 
    if(ans) cout << "Alice\n";
    else cout << "Bob\n";
}


signed main() {
    // freopen("test.in","r",stdin);  
    // freopen("code.out","w",stdout);    
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    isprime();
    int T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}