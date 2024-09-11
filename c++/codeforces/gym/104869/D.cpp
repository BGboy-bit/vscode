#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
int n, trie[N][26], fail[N], cnt, in[N], vis[N], ans[N];


vector <int> flag[N]; //点对应的字符串

void initACAutomaton() {
    cnt = 0; // 重置计数器
    for (int i = 0; i < N; i++) {
        fill(trie[i], trie[i] + 26, 0); // 初始化trie节点
        fail[i] = 0; // 初始化失败指针
        in[i] = 0; // 初始化入度
        vis[i] = 0; // 初始化访问次数
        ans[i] = 0; // 初始化答案数组
        flag[i].clear(); // 清空对应的vector
    }
}

void add (string x, int id) { //建trie树
	int len = x.length (), now = 0;
	for (int i = 0; i < len; i++) {
		int c = x[i] - 'a';
		if (!trie[now][c])
			trie[now][c] = ++cnt;
		now = trie[now][c];
	}
	flag[now].push_back (id);
}

void get_fail () { //添加fail边
	queue <int> q;
	for (int i = 0; i < 26; i++)
		if (trie[0][i])
			q.push (trie[0][i]);
	while (!q.empty ()) {
		int u = q.front ();
		q.pop ();
		for (int i = 0; i < 26; i++) {
			if (trie[u][i]) {
				fail[trie[u][i]] = trie[fail[u]][i];
				in[fail[trie[u][i]]]++; //fail边指向的点入度+1
				q.push (trie[u][i]);
			}
			else trie[u][i] = trie[fail[u]][i];
		}
	}
}

void query (string x) { //查询答案
	int len = x.length (), now = 0;
	for (int i = 0; i < len; i++) {
		int c = x[i] - 'a';
		now = trie[now][c];
		vis[now]++; //不需跳fail边
	}
}

void topu () { //拓扑排序
	queue <int> q;
	for (int i = 1; i <= cnt; i++)
		if (!in[i])
			q.push (i);
	while (!q.empty ()) {
		int u = q.front ();
		q.pop ();
		for (auto it = flag[u].begin (); it != flag[u].end (); it++)
			ans[*it] = vis[u];
		int v = fail[u];
		vis[v] += vis[u];
		in[v]--;
		if (!in[v])
			q.push (v);
	}
}

int main() {
    string a, b; cin >> a >> b;
    ll summ = 0, anss = 0;
    for(ll i = 0; i < a.size(); i ++ ) {
        string s;
        for(ll j = i; j < a.size(); j ++ ) {
            s += a[j];
            add(s, ++ summ);
        }
    }
	get_fail ();
	query (b);
	topu ();
    for(ll i = 1; i <= summ; i ++ ) anss += ans[i];
    summ = 0;
    initACAutomaton(); 
    for(ll i = 1; i < a.size() - 1; i ++ ) {
        string s;
        for(ll j = i; j < a.size() - 1; j ++ ) {
            s += a[j];
            if(a[i - 1] == a[j + 1]) {
                add(s, ++ summ);
                ll len = j - i + 1;
                for(ll k = j + 2, q = 0; q < len - 1; k ++, q ++  ) {
                    if(a[k] == s[q]) {
                        string ss = s.substr(q + 1, len - (q + 1));
                        add(ss, ++ summ);
                    } else break;
                }
            }
                
        }        
    }
	get_fail ();
	query (b);
	topu ();
    for(ll i = 1; i <= summ; i ++ ) anss += ans[i];
    summ = 0;
    initACAutomaton();
    for(ll i = 1; i < b.size() - 1; i ++ ) {
        string s;
        for(ll j = i; j < b.size() - 1; j ++ ) {
            s += b[j];
            if(b[i - 1] == b[j + 1]) {
                add(s, ++ summ);
                ll len = j - i + 1;
                for(ll k = j + 2, q = 0; q < len - 1; k ++, q ++ ) {
                    if(b[k] == s[q]) {
                        string ss = s.substr(q + 1, len - (q + 1));
                        add(ss, ++ summ);
                    } else break;
                }
            }
                
        }        
    } 
	get_fail ();
	query (a);
	topu ();
    for(ll i = 1; i <= summ; i ++ ) anss += ans[i];
    cout << anss << "\n";
    return 0;
}