#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FL(a,b,c) for(int a=(b),a##end=(c);a<=a##end;++a)
#define FR(a,b,c) for(int a=(b),a##end=(c);a>=a##end;--a)
#define lowbit(x) ((x)&-(x))
#define eb emplace_back
#define SZ(x) (int)((x).size())
#define ll long long
#define vt vector
#define ar(x) array<int,x>
#define PII pair<int, int>
#define max(a, b)({auto f7r=(a);auto j3h=(b);f7r<j3h?j3h:f7r;})
#define cmax(a, b)({auto j3h=(b);(j3h>a)&&(a=j3h);})
#define min(a, b)({auto f7r=(a);auto j3h=(b);f7r>j3h?j3h:f7r;})
#define cmin(a, b)({auto j3h=(b);(j3h<a)&&(a=j3h);})
constexpr int N = 1e6 + 10;
int c[N], n, m, vis[N], k;
vt<int>e[N];
bool f(int x){
    queue<int>q;int ans = 1e9, u;
    FL(s, 0, log2(n)){
        while(!q.empty())q.pop();
        FL(i, 1, n)
            if(c[i] != x || !(i & (1 << s)))vis[i] = 0;
            else q.emplace(i), vis[i] = 1;
        while(!q.empty()){
            u = q.front(), q.pop();
            for(int&v : e[u])if(!vis[v]){
                if(c[v] == x){cmin(ans, vis[u]);goto end1;}
                vis[v] = vis[u] + 1, q.emplace(v);
            }
        }
        end1:
        while(!q.empty())q.pop();
        FL(i, 1, n)
            if(c[i] != x || (i & (1 << s)))vis[i] = 0;
            else q.emplace(i), vis[i] = 1;
        while(!q.empty()){
            u = q.front(), q.pop();
            for(int&v : e[u])if(!vis[v]){
                if(c[v] == x){cmin(ans, vis[u]);goto end2;}
                vis[v] = vis[u] + 1, q.emplace(v);
            }
        }
        end2:
        if(ans < k)return 0;
    }
    return ans >= k;
}
bool solve(){
    int x, y;
    cin >> n >> m >> k;
    FL(i, 1, n)cin >> c[i], e[i].clear();
    while(m--)cin >> x >> y, e[x].eb(y);
    FL(i, 1, 50)if(!f(i))return 0;  
    return 1;
}
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--)cout << (solve() ? "YES" : "NO") << endl;
    return 0;
}