#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using PII = pair<int,int>;

constexpr ll INF = 2E18+10;
constexpr int N = 2E6+10;

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
        init(vector(n_,v_));
    }
    template<class T>
    void init(vector<T> init_){
        n=init_.size();
        info.assign(4<<__lg(n),Info());
        function<void(int,int,int)> build=[&](int p,int l,int r){
            if(r-l==1){
                info[p]=init_[l];
                return ;
            }
            int m=(l+r)/2;
            build(2*p,l,m);
            build(2*p+1,m,r);
            pull(p);
        };
        build(1,0,n);
    }
    void pull(int p){
        info[p]=info[2*p]+info[2*p+1];
    }
    void modify(int p,int l,int r,int x,const Info &v){
        if(r-l==1){
            info[p]=v;
            return ;
        }
        int m=(l+r)/2;
        if(x<m){
            modify(2*p,l,m,x,v);
        }else{
            modify(2*p+1,m,r,x,v);
        }
        pull(p);
    }
    void modify(int p,const Info &v){
        modify(1,0,n,p,v);
    }
    Info rangeQuery(int p,int l,int r,int x,int y){
        if(l>=y||r<=x){
            return Info();
        }
        if(l>=x&&r<=y){
            return info[p];
        }
        int m=(l+r)/2;
        return rangeQuery(2*p,l,m,x,y)+rangeQuery(2*p+1,m,r,x,y);
    }
    Info rangeQuery(int l,int r){
        return rangeQuery(1,0,n,l,r);
    }
};

struct Info{
    int sum=0;
    int mx=-INF;
    int mn=INF;
};

Info operator+(Info a,Info b){
    Info c;
    c.sum=a.sum+b.sum;
    c.mx=max(a.mx,b.mx);
    c.mn=min(a.mn,b.mn);
    return c;
}

template<typename T = ll>
bool extgcd(T a,T b,T &x,T &y,T d){
    if(!b&&d%a) return false;
    if(!b){
        x=d/a,y=0;
        return true;
    }
    if(extgcd(b,a%b,y,x,d)){
        y-=a/b*x;
        return true;
    }
    return false;
}
int exgcd(int a,int b,int &x,int &y){
    int d=a;
    if(!b){
        x=1,y=0;
    }else{
        d=exgcd(b,a%b,y,x);
        y-=a/b*x;
    }
    return d;
}

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

void solve()
{
    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    for(int i=1;i<=T;i++){
        solve();
    }
}
