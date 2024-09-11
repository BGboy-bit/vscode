#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 3e6 + 10;        // 定义最大节点数
const int CHARSET_SIZE = 62;     // 字符集大小（大写字母26个，小写字母26个，数字10个）

struct Trie {
    int nex[MAX][CHARSET_SIZE];  // 存储子节点索引
    bool exis[MAX];              // 标记是否有单词在此结束
    int cnt;                     // 当前使用的节点数
    int sum[MAX];   

    void init() {
        cnt = 0;
        memset(nex, 0, sizeof(nex));
        memset(exis, false, sizeof(exis));
        memset(sum, 0, sizeof(sum));
    }
    inline int getnum(char x) {  // 映射字符到索引
        if (x >= 'A' && x <= 'Z')
            return x - 'A';
        else if (x >= 'a' && x <= 'z')
            return x - 'a' + 26;
        else
            return x - '0' + 52;
    }
    inline void insert(const string &s) {
        int pos = 0;
        for (char c : s) {  
            int index = getnum(c);
            if (!nex[pos][index]) 
                nex[pos][index] = ++ cnt;
            pos = nex[pos][index];
            sum[pos] ++ ;
        }   
        exis[pos] = true;
    }
    inline int find(const string &s) {
        int pos = 0;
        for (char c : s) {
            int index = getnum(c);
            if (!nex[pos][index])
                return false;
            pos = nex[pos][index];
        }
        return sum[pos];
    }
}t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T; cin >> T;
    while (T--) {
        t.init();
        ll n, q;
        cin >> n >> q;
        string s;
        for (ll i = 0; i < n; i++) {
            cin >> s;
            // trie.insert(s);
            t.insert(s);
        }
        for (ll i = 0; i < q; i++) {
            cin >> s;
            // if (trie.find(s)) ans++;
            cout << t.find(s) << "\n";
        }
    }
    return 0;
}
