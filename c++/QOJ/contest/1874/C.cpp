#include<bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
using pii = pair<int,int>;

constexpr ll N = 2E6 + 10, INF = 2E18 + 10;

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    set<int> se;
    map<int,int> cnt;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
        se.insert(a[i]);
    }

    vector<int> b(n+1);
    for(int i=1;i<=n;i++){
        int e1=-1,e2=-1;
        int now=a[i];
        bool ha=0;
        if(se.find(a[i])!=se.end()) ha=1;
        se.erase(now);
        if(se.size()>=1) e1=*se.begin();
        if(se.size()>=2) e2=*next(se.begin());
        b[i]=e1;
        if(b[i]==-1){
            cout<<"Impossible"<<"\n";
            return ;
        }
        cnt[e1]--;
        if(cnt[e1]==0) se.erase(e1);
        if(ha) se.insert(now);
    }
    for(int i=1;i<=n;i++){
        cout<<b[i]<<" \n"[i==n];
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
}