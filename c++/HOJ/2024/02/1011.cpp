// #include<bits/stdc++.h>
// #define int long long
// using namespace std;
// const int N = 2e5 + 6;

// string S, pp, c, q;
// int sa[N], rk[N], tmp[N];
// int k;

// bool cmp(int a, int b) {
//     if (rk[a] != rk[b]) {
//         return rk[a] < rk[b];
//     }
//     int ra = (a + k <= S.length()) ? rk[a + k] : -1;
//     int rb = (b + k <= S.length()) ? rk[b + k] : -1;
//     return ra < rb;
// }

// void construct_sa() {
//     int n = S.length();
//     for (int i = 0; i <= n; i++) {
//         sa[i] = i;
//         rk[i] = (i < n) ? S[i] : -1;
//     }
//     for (k = 1; k <= n; k *= 2) {
//         sort(sa, sa + n + 1, cmp);
//         tmp[sa[0]] = 0;
//         for (int i = 1; i <= n; i++) {
//             tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
//         }
//         for (int i = 0; i <= n; i++) {
//             rk[i] = tmp[i];
//         }
//     }
// }

// bool contain(const string &T) {
//     int l = 0, r = S.length();
//     while (l <= r) {
//         int mid = (l + r) / 2;
//         int cmp_result = S.compare(sa[mid], T.length(), T);
//         if (cmp_result == 0) {
//             return true;
//         } else if (cmp_result < 0) {
//             l = mid + 1;
//         } else {
//             r = mid - 1;
//         }
//     }
//     return false;
// }

// void solve() {
//     int n;
//     cin >> n;
//     cin >> S >> pp;
//     construct_sa();
//     int f = 0;
//     for (int i = 1; i <= n; i++) {
//         cin >> c >> q;
//         if (contain(c) && q.find(pp) != string::npos) {
//             if (f) cout << ' ';
//             cout << i;
//             f = 1;
//         }
//     }
//     cout << '\n';
// }

// signed main() {
//     cin.tie(nullptr)->sync_with_stdio(false);
//     int T;
//     cin >> T;
//     while (T--) {
//         solve();
//     }
//     return 0;
// }
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
bool multi = 1;

const int MAX = 1e5 + 10;
vector<ll> cntt(maxn);

namespace AC {
    int trie[maxn][26], cnt;     // 字典树
    int sum[maxn], fail[maxn];
    vector<vector<ll>> node(maxn);

void init() {
    cnt = 0;
    for(ll i = 0; i < maxn; i ++ ) {
            sum[i] = 0; fail[i] = 0;
            for(ll j = 0; j < 26; j ++ ) trie[i][j] = 0; 
        }
        node.assign(maxn, vector<ll>()); // Resize and re-initialize each sub-vector
    }


    void insert(string pat, ll i) {   // 插入
        int pos = 0;
        for(auto c : pat) {
            if(!trie[pos][c - 'a']) trie[pos][c - 'a'] = ++ cnt;
            pos = trie[pos][c - 'a'];
        }
        sum[pos] ++ ;   
        node[pos].push_back(i);
    }
    
    void getfail() {            // bfs求失配指针
        queue<int> q;
        for(ll v = 0; v < 26; v ++ ) { // 预处理第二层，此时所有子节点的fail指向root
            int c = trie[0][v];
            if(c) {
                fail[c] = 0;
                q.push(c);
            }
        }
        while(!q.empty()) {
            int pos = q.front(); q.pop();
            int f = fail[pos]; // 父节点的fail指针
            for(ll v = 0; v < 26; v ++ ) {
                int c = trie[pos][v];
                if(c) {
                    fail[c] = trie[f][v]; // 如果父节点的fail指针下有当前字符，则指向它，否则指向root，而trie[f][v]默认值为0
                    q.push(c);
                } else trie[pos][v] = trie[f][v];
            }
        }
    }
    ll find(string txt) {
        ll pos = 0;
        ll ans = 0;
        for(auto c : txt) {
            ll v = trie[pos][c - 'a'];
            while(v && sum[v] != -1) {
                ans += sum[v];
                for(auto i : node[v]) 
                    cntt[i] ++ ;
                sum[v] = -1;  // 加过标记成-1
                v = fail[v];  // 跳往fail节点
            }
            pos = trie[pos][c - 'a']; // 前往下一个节点
        }
        return ans;
    }
}

void Solve() {
    AC::init();
    ll n; cin >> n;
    string a, c; cin >> a >> c;
    string b1, b2;
    for(ll i = 1; i <= n; i ++ ) cntt[i] = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> b1 >> b2;
        AC::insert(b1, i);
        if(b2.find(c) != b2.npos) cntt[i] ++ ;
    }
    AC::getfail();
    AC::find(a);
    for(ll i = 1; i <= n; i ++ ) {
        if(cntt[i] >= 2) {
            cout << i;
            if(i < n) cout << " ";
        }
    }
    cout << "\n";
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