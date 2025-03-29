#include<bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
using pii = pair<int,int>;

constexpr ll N = 2E6 + 10, inf = 2E18 + 10;
int a[N],c[N];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    int l=1,r=1e9;
    int mid;
    multiset <int>s1,s2;

    while(l<r){
        mid=(l+r+1)/2;
        int f=1;
        s1.clear();
        s2.clear();
        for(int i=1;i<=n;i++){
            if(c[i]==0){
                if(s1.empty()){
                    s2.insert(a[i]);
                    continue;
                }
                if(s1.lower_bound(mid-a[i])!=s1.end()){
                    s1.erase(s1.lower_bound(mid-a[i]));
                }else {
                    f=0;
                }            
            }else {
                if(s2.empty()){
                    s1.insert(a[i]);
                    continue;
                }
                if(s2.lower_bound(mid-a[i])!=s2.end()){
                    s2.erase(s2.lower_bound(mid-a[i]));
                }else f=0;
            }
            
        }
        if(f){
            l=mid;
        }else {
            r=mid-1;
        }
    }
    cout<<l<<'\n';
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