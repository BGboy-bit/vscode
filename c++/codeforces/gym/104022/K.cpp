#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 3e6 + 10;        // 定义最大节点数
const int CHARSET_SIZE = 30;     // 字符集大小（大写字母26个，小写字母26个，数字10个）

ll ans = 0;

struct Trie {
    int nex[MAX][CHARSET_SIZE];  // 存储子节点索引
    bool exis[MAX];              // 标记是否有单词在此结束
    int cnt;                     // 当前使用的节点数
    int sum[MAX];   
    int son[MAX];

    void init() {
        cnt = 0;
        memset(nex, 0, sizeof(nex));
        memset(exis, false, sizeof(exis));
        memset(sum, 0, sizeof(sum));
        memset(son, 0, sizeof(son));
    }
    inline int getnum(char x) {  // 映射字符到索引
        if (x >= 'a' && x <= 'z')
            return x - 'a';
        else if(x == '.')
            return 26;
        else if(x == '/')
            return 27;
        else return 0;
    }
    inline void insert(const string &s) {
        int pos = 0;
        for (char c : s) {  
            int index = getnum(c);
            if (!nex[pos][index]) {
                son[pos] ++ ;
                nex[pos][index] = ++ cnt;
            }
            pos = nex[pos][index];
            sum[pos] ++ ;
        }   
        exis[pos] = true;
    }
    inline void find(const string &s) {
        int pos = 0, fa = 0;
        for (ll c = 0; c < s.size(); c ++ ) {
            int index = getnum(s[c]);
            fa = pos;
            pos = nex[pos][index];
            sum[pos] -- ;
            if(sum[pos] == 0) {
                if(sum[fa] == 0 && fa != 0) {
                    ans -= son[fa] - 1;
                }
                if(son[pos] == 0) {
                    ans += 1;
                    cout << ans << "\n"; return ;
                }
            }  
        }
    }
}t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    while (T--) {
        t.init();
        ll n; cin >> n;
        vector<string> s(n);
        for (ll i = 0; i < n; i++) {
            cin >> s[i]; t.insert(s[i]);
        }
        for(ll i = 0; i < n; i ++ ) 
            t.find(s[i]);
    }
    return 0;
}