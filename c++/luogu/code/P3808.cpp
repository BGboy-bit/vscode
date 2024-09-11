#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e6 + 10;

namespace AC {
    int trie[MAX][26], cnt;     // 字典树
    int sum[MAX], fail[MAX];
    void insert(string pat) {   // 插入
        int pos = 0;
        for(auto c : pat) {
            if(!trie[pos][c - 'a']) trie[pos][c - 'a'] = ++ cnt;
            pos = trie[pos][c - 'a'];
        }
        sum[pos] ++ ;   
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
                sum[v] = -1;  // 加过标记成-1
                v = fail[v];  // 跳往fail节点
            }
            pos = trie[pos][c - 'a']; // 前往下一个节点
        }
        return ans;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    for(ll i = 1; i <= n; i ++ ) {
        string pat; cin >> pat;
        AC::insert(pat);
    }
    AC::getfail();
    string txt; cin >> txt;
    cout << AC::find(txt) << "\n";
    return 0;
}