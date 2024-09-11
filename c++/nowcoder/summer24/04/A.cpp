#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n + 1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1e6 + 10;
bool multi = 1;

vector<ll> de, he, fa;
ll n, u, v, c, fu, fv, i;

ll find(ll u) {
    if(fa[u] == u) return u;
	ll tmp = find(fa[u]);
	de[u] += de[fa[u]];
	return fa[u] = tmp;
}

void Solve() {
    cin >> n;
    de.resize(n + 1); he.resize(n + 1); fa.resize(n + 1);
    for(i = 1; i <= n; i ++ ) {
        fa[i] = i;
        de[i] = 0;
        he[i] = 0;
    }
    for(i = 1; i < n; i ++ ) {
        cin >> u >> v >> c;
		fa[v] = u;
		de[v] = 1;
		find(v);
		fu = find(u);
        he[fu] = max(he[fu], de[v] + he[v]);
        cout << he[c] << " \n"[i == n - 1];
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// struct DSU{
//     vector<int> fa,deep;
//     DSU(int n):fa(n),deep(n){
//         iota(begin(fa),end(fa),0);
//     }
//     int find(int x){
//         if(x==fa[x]) return x;
//         int tmp=find(fa[x]);
//         deep[x]+=deep[fa[x]];
//         return fa[x]=tmp;
//     }
// };
// void solve(){
//     int n;
//     cin>>n;
//     DSU dsu(n + 1);
//     vector<int> f(n + 1);
//     for(int i=0,u,v,c;i<n-1;i++){
//         cin>>u>>v>>c;
//         dsu.fa[v]=u;
//         dsu.deep[v]=1;
//         dsu.find(v);
//         f[dsu.find(u)]=max(f[dsu.find(u)],f[v]+dsu.deep[v]);
//         cout<<f[c]<<' ';
//     }
//     cout<<'\n';
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int t=1;
//     cin>>t;
//     while(t--) solve();
//     return 0;
// }