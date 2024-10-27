#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
using PII = pair<int,int>;

std::mt19937_64 rng(
    std::chrono::steady_clock::now().time_since_epoch().count()
);

constexpr ll INF = 2E18 + 10;
constexpr int N = 2E5 + 10;
int p[10];
int a[6],b[6];
int up[6],d[6],q1[10],q2[10];
ll aaaa;
void Solve(string ss, string tt)
{
    int n,m;
    // string ss,tt;
    // cin>>ss>>tt;
    for(int i=0;i<4;i++){
        a[i+1]=ss[i]-'0';
        b[i+1]=tt[i]-'0';
        // a[i]=rand()%10;
        // b[i]=rand()%10;
    }
    int x,y;
    int ans=1e18;
    for(int i=1;i<=4;i++){
        if(b[i]>=a[i]){
            up[i]=b[i]-a[i];
            d[i]=10-(b[i]-a[i]);
        }else {
            up[i]=10-(a[i]-b[i]);
            d[i]=a[i]-b[i];
        }
    }
    for(int k=0;k<20;k++){
        x=k;
        y=0;
        for(int i=1;i<=4;i++){
            p[i]=0;
        }
        while(x){
            p[++y]=x%2;
            x/=2;
        }
        int cnt=0;
        for(int i=1;i<=4;i++){
            if(i!=1&&p[i]==p[i-1]){
                continue;
            }
            int l=i,r=i;
            int res=0;
            while(p[r]==p[i]&&r<=4){
                r++;
            }
            r=min(4ll,r);
            if(p[r]!=p[i])r--;
            for(int j=l;j<=r;j++){
                q1[j]=up[j];
                q2[j]=d[j];
            }

            int f=1;
            while(1){
                f=1;
                for(int j=l;j<=r;j++){
                    if(p[i]==0){
                        if(q1[j]>0){
                            q1[j]--;
                            f=0;
                        }else if(f==0)break;       
                    }else {
                            if(q2[j]>0){
                            q2[j]--;
                            f=0;
                        }else if(f==0)break; 
                    }
               
                    
                }

                if(f==1)break;
                res++;
            }
            cnt+=res;
        }
        ans=min(ans,cnt);
    }
    cout<<ans<<'\n';
    // aaaa = ans;
    
}
vector<vector<ll>> g(10000);
map<pair<ll, ll>, ll> mp, mp1;
vector<ll> siz(10000);

void bfs(ll st) {
    vector<ll> vis(10000);
    queue<pair<ll, ll>> q; q.push({st, 0});
    while(!q.empty()) {
        ll res = q.front().first, cnt = q.front().second; q.pop();
        vis[res] = 1;
        if(mp1.count({st, res})) {
            mp[{st, res}] = cnt; siz[st] --; siz[res] -- ;
            if(siz[st] == 0) return ;   
        }
        string ss = to_string(res); 
        while(ss.size() < 4) ss = '0' + ss;
        for(ll i = 0; i < 4; i ++ ) {
            for(ll j = i; j < 4; j ++ ) {
                string ss1 = ss, ss2 = ss;
                for(ll k = i; k <= j; k ++ ) {
                    ss1[k] += 1;
                    if(ss1[k] > '9') ss1[k] = '0';
                    ll ress = 0;
                    for(ll kk = 0; kk < 4; kk ++ ) {
                        ress = ress * 10 + ss1[kk] - '0'; 
                    }
                    if(!vis[ress]) {
                        vis[ress] = 1;
                        q.push({ress, cnt + 1});
                        // cout << i << " " << j << " ";
                        // cout << ress << "\n";
                    }
                    ss2[k] -= 1;
                    if(ss2[k] < '0') ss2[k] = '9';
                    ress = 0;
                    for(ll kk = 0; kk < 4; kk ++ ) {
                        ress = ress * 10 + ss2[kk] - '0'; 
                    }
                    if(!vis[ress]) {
                        vis[ress] = 1;
                        q.push({ress, cnt + 1});
                        // cout << i << " " << j << " ";
                        // cout << ress << "\n";
                    }        
                }
            }
        }
    }
}

void solve(ll ss, ll tt) {
    ll t; //cin >> t; 
    t = 1;
    vector<ll> a(t + 1), b(t + 1); 
    for(ll i = 1; i <= t; i ++ ) {
        // cin >> a[i] >> b[i];
        a[i] = ss; b[i] = tt;
        g[a[i]].push_back(b[i]); g[b[i]].push_back(a[i]);
        mp1[{a[i], b[i]}] = 1; mp[{b[i], a[i]}] = 1;
    }
    vector<ll> p(10000);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](ll x, ll y){
        if(g[x].size() == g[y].size())
            return x < y;
        return g[x].size() > g[y].size();
    });
    for(ll i = 0; i <= 9999; i ++ ) {
        siz[i] = g[i].size();
    }
    for(ll i = 0; i <= 9999; i ++ ) {
        if(siz[p[i]] > 0){
            bfs(p[i]);
        }  
    }
    for(ll i = 1; i <= t; i ++ ) {
        cout << mp[{a[i], b[i]}] << "\n";
        // if(aaaa != mp[{a[i], a[i]}]) {
        //     cout << a[i] << " " << b[i] << "\n";
        // } else {
        //     cout << "ac\n";
        // }
    } 
}
signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);

    int T=1;
    // cin>>T;
    // for(ll x = 0; x <= 100; x ++ ) {
    //     ll i = rng() % 10000, j = rng() % 10000;
    //      Solve(to_string(i), to_string(j));
    //      solve(i, j); 
    // }
    ll i, j; cin >> i >> j;
         Solve(to_string(i), to_string(j));
         solve(i, j); 
}