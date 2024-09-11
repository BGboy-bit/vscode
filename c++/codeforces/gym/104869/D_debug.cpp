#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e6 + 10;

namespace AC {
    int trie[maxn][26], cnt;     // 字典树
    int sum[maxn], fail[maxn];

    void init() {
        cnt = 0;
        for(ll i = 0; i < maxn; i ++ ) {
            sum[i] = 0; fail[i] = 0;
            for(ll j = 0; j < 26; j ++ ) trie[i][j] = 0;
        }
    }

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
                } else trie[pos][v] = trie[f][v]; // “造”一个孩子，跳过去匹配
            }
        }   
    }

    ll find(string txt) {
        int pos = 0;
        ll ans = 0;
        for(auto c : txt) {
            int v = trie[pos][c - 'a'];
            while(v && sum[v] != -1) {
                ans += sum[v];
                // sum[v] = -1;  // 加过标记成-1
                v = fail[v];  // 跳往fail节点
            }
            pos = trie[pos][c - 'a']; // 前往下一个节点
        }
        return ans;
    }
}

string a, b; 

ll Solve1() {
    AC::init();
    for(ll i = 0; i < a.size(); i ++ ) {
        string s;
        for(ll j = i; j < a.size(); j ++ ) {
            s += a[j];
            AC::insert(s);
        }
    }
    AC::getfail();
    ll ans = AC::find(b); 

    AC::init();
    for(ll i = 1; i < a.size() - 1; i ++ ) {
        string s;
        for(ll j = i; j < a.size() - 1; j ++ ) {
            s += a[j];
            if(a[i - 1] == a[j + 1]) {
                AC::insert(s);
                ll len = j - i + 1;
                for(ll k = j + 2, q = 0; q < len - 1; k ++, q ++  ) {
                    if(a[k] == s[q]) {
                        string ss = s.substr(q + 1, len - (q + 1));
                        AC::insert(ss);
                    } else break;
                }
            }
                
        }        
    }
    AC::getfail();
    ans += AC::find(b);

    AC::init();
    for(ll i = 1; i < b.size() - 1; i ++ ) {
        string s;
        for(ll j = i; j < b.size() - 1; j ++ ) {
            s += b[j];
            if(b[i - 1] == b[j + 1]) {
                AC::insert(s);
                ll len = j - i + 1;
                for(ll k = j + 2, q = 0; q < len - 1; k ++, q ++  ) {
                    if(b[k] == s[q]) {
                        string ss = s.substr(q + 1, len - (q + 1));
                        AC::insert(ss);
                    } else break;
                }
            }
                
        }        
    } 
    AC::getfail();
    ans += AC::find(a);  
    return ans;
}

ll Solve2() {
    vector<string> aa, bb;
    for(ll i = 0; i < a.size(); i ++ ) {
        string s;
        for(ll j = i; j < a.size(); j ++ ) {
            s += a[j];
            aa.push_back(s);
        }
    }
    ll ans = 0;
    for(ll i = 0; i < b.size(); i ++ ) {
        string s;
        for(ll j = i; j < b.size(); j ++ ) {
            s += b[j];
            for(ll k = 0; k < aa.size(); k ++ ) {
                string ss = aa[k] + s;
                if(ss.size() % 2 == 1) continue;
                string s1 = ss.substr(0, ss.size() / 2), s2 = ss.substr(ss.size() / 2, ss.size() / 2);
                if(s1 == s2) {
                    ans ++ ;
                    // cout << aa[k] << " " << s << "\n";
                }
            }
        }
    }
   return ans;
}

// 生成一个随机长度的、只包含小写字母的字符串
string generateRandomString() {
    string result;
    for(ll i = 1; i <= 10; i ++ ) {
        result += 'a' + rand() % 26;
    }
    return result;
}

signed main() {
    for(ll i = 1; i <= 100; i ++ ) {
        a = generateRandomString();
        b = generateRandomString();
        ll ans1 = Solve1(), ans2 = Solve2();
        if(ans1 != ans2) {
            cout << a << " " << b << " " << ans1 << " " << ans2 << "\n";
        } else {
            cout << "ac" << "\n";
        }
    } 

}
/*
cjbprhtneg yiwxgcjwlg 6 5
cdyrfvvriv uyeegfivdr 11 10
*/