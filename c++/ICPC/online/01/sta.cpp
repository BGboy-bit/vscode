#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
constexpr ll INF = 2E18+10;

struct DSU{
    vector<int> f,siz;
    DSU(int n):f(n),siz(n,1){iota(f.begin(),f.end(),0);}
    int find(int x){
        while(x!=f[x]) x=f[x]=f[f[x]];
        return x;
    }
    bool same(int x,int y){return find(x)==find(y);}
    bool merge(int x,int y){
        x=find(x);y=find(y);
        if(x==y) return false;
        siz[x]+=siz[y];
        f[y]=x;
        return true;
    }
    int size(int x){return siz[find(x)];}
};

template<class T>
constexpr T power(T a,ll b,ll mod){
    a%=mod;
    T res=1;
    for(;b;b/=2,a*=a,a%=mod){
        if(b%2){
            res*=a;
            res%=mod;
        }
    }
    return res;
}

template<class Info>
struct SegmentTree{
    int n;
    vector<Info> info;
    SegmentTree():n(0){}
    SegmentTree(int n_,Info v_=Info()){
        init(n_,v_);
    }
    template<class T>
    SegmentTree(vector<T> init_){
        init(init_);
    }
    void init(int n_,Info v_=Info()){
        init(std::vector(n_,v_));
    }
};



void solve()
{

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
}