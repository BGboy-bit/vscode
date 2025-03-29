#include<bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
using pii = pair<int,int>;

constexpr ll N = 2E6 + 10, inf = 2E18 + 10;

// 先定义所有结构体
struct Info{
    array<int,31> bt;
};

Info operator+(Info a,Info b){
    Info c;
    for(int i=0;i<=30;i++){
        c.bt[i]=a.bt[i]+b.bt[i];
    }
    return c;
}

struct MAX{
    int val;
};

MAX operator+(MAX a,MAX b){
    return MAX{max(a.val,b.val)};
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
        init(std::vector<Info>(n_,v_));
    }
    template<class T>
    void init(vector<T> init_){
        n=init_.size();
        info.assign(4<<__lg(n),Info());
        function<void(int,int,int)>build=[&](int p,int l,int r){
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
    void modify(int p,int l,int r,int x,const Info&v){
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
        if(l>=y || r<=x){
            return Info();
        }
        if(l>=x&&r<=y){
            return info[p];
        }
        int m=(l&r)/2;
        return rangeQuery(2*p,l,m,x,y) + rangeQuery(2*p+1,m,r,x,y);
    }
    Info rangeQuery(int l,int r){
        return rangeQuery(1,0,n,l,r);
    }
};

void solve()
{
    int n,q;
    cin>>n>>q;
    SegmentTree<Info> tr(n+1);
    array<SegmentTree<MAX>,31> trk;
    for(int i=0;i<=30;i++){
        trk[i].init(n+1);
    }
    vector<vector<int>> a(31,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        array<int,31> tmp;
        for(int j=0;j<=30;j++){
            for(int k=30;k>=0;k--){
                if((x>>k)>0){
                    trk[k].modify(i,MAX{x>>k});
                }
            }
            int t=(x>>j&1);
            tmp[j]+=t;
        }
        tr.modify(i,Info{tmp});
    }
    // cout<<"ok\n";
    while(q--){
        int l,r,k;
        cin>>l>>r>>k;
        bool ok=0;
        auto w=tr.rangeQuery(l,r+1).bt;
        for(int j=30;j>=0;j--){
            if(k-w[j]>=0){
                k-=w[j];
                if(j-1>=0)
                    w[j-1]+=w[j];
            }else{
                if(r-l+1<k){
                    continue;
                }
                cout<<trk[j].kth(l,r+1,k).val<<"\n";
                ok=1;
                break;
            }      
        }
        if(!ok){
            cout<<0<<"\n";
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T = 1;
    // cin>>T;
    while(T--){
        solve();
    }
}