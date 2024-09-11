#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e6 + 10;

namespace AC {
    int trie[maxn][26], cnt;     // 字典树
    int sum[maxn], fail[maxn];   // 节点字符串的个数，fail指针
    int in[maxn], vis[maxn];     // 拓扑排序优化
    int num[maxn], ans[maxn];    // 节点指向的字符串序号 出现次数

    void init() {
        cnt = 0;
        for(ll i = 0; i < maxn; i ++ ) {
            sum[i] = 0; fail[i] = 0; in[i] = 0; vis[i] = 0; num[i] = 0; ans[i] = 0;
            for(ll j = 0; j < 26; j ++ ) trie[i][j] = 0;
        }
    }

    void insert(string pat, ll i) { // 插入
        int pos = 0;
        for(auto c : pat) {
            if(!trie[pos][c - 'a']) trie[pos][c - 'a'] = ++ cnt;
            pos = trie[pos][c - 'a'];    
        }
        num[pos] = i;
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
                    in[fail[c]] ++ ;      // 拓扑序优化
                    q.push(c);
                } else trie[pos][v] = trie[f][v]; // “造”一个孩子，跳过去匹配
            }
        }   
    }
    
    void query(string &txt) {
        int pos = 0;
        for(auto c : txt) {
            pos = trie[pos][c - 'a']; vis[pos] ++ ; ans[num[pos]] = vis[pos];
        }
    }

    void topu() {
        queue<int> q;
        for(int i = 1; i <= cnt; i ++ ) {
            if(in[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int u = q.front(); q.pop();
            ans[num[u]] = vis[u];
            int v = fail[u]; in[v] -- ;
            vis[v] += vis[u];
            if(in[v] == 0) q.push(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    AC::init();
    ll n; cin >> n;
    vector<string> pat(n + 1);
    map<string, int> mp;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> pat[i];
        if(mp[pat[i]] == 0) {
            AC::insert(pat[i], i);
            mp[pat[i]] = i;
        }
    }
    AC::getfail();
    string txt; cin >> txt; 
    AC::query(txt);
    AC::topu();
    for(ll i = 1; i <= n; i ++ ) cout << AC::ans[mp[pat[i]]] << "\n";
    return 0;
}