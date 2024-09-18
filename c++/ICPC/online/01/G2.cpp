#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
constexpr ll INF = 2E18+10;
constexpr int N=2e6+6,M=2006;
int a[M];
int b[N];
void solve()
{
    int n;
    cin>>n;
    int m=n*(n-1)/2;
    int f=0;
    multiset<int> q1;
    multiset<int,greater<>> q2;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int t=0,x,y;
    for(int i=1;i<=n;i++){
        if(!q2.empty()){
            x=*q2.begin();
            if(a[i]>x){
                q1.emplace(a[i]);
            }else {
                q2.emplace(a[i]);
            }
            while(q1.size()>q2.size()){
                x=*q1.begin();
                q1.erase(q1.begin());
                q2.emplace(x);
            }
            while(q2.size()-1>q1.size()){
                x=*q2.begin();
                q2.erase(q2.begin());
                q1.emplace(x);
            }
        }
        else {
            q2.emplace(a[i]);
        }
        if(f==0){
            b[++t]=*q2.begin();
            for(int j=i-1;j>=1;j--){
                x=*q2.begin();
                if(a[j]>x){
                    q1.emplace(a[j]);
                }else {
                    q2.emplace(a[j]);
                }
                while(q1.size()>q2.size()){
                    x=*q1.begin();
                    q1.erase(q1.begin());
                    q2.emplace(x);
                }
                while(q2.size()-1>q1.size()){
                    x=*q2.begin();
                    q2.erase(q2.begin());
                    q1.emplace(x);
                }
                b[++t]=*q2.begin();
            }
        }else {
            b[++t]=*q2.begin();
            for(int j=1;j<i;j++){
                x=*q2.begin();
                if(a[j]>x){
                    q1.erase(q1.find(a[j]));
                }else {
                    q2.erase(q2.find(a[j]));
                }

                while(q1.size()>q2.size()){
                    x=*q1.begin();
                    q1.erase(q1.begin());
                    q2.emplace(x);
                }
                while(q2.size()-1>q1.size()){
                    x=*q2.begin();
                    q2.erase(q2.begin());
                    q1.emplace(x);
                }
                b[++t]=*q2.begin();
            }
            q1.clear();
            q2.clear();
        }
        f=1-f;
    }

    sort(b+1,b+t+1);
    // for(int i=1;i<=t;i++){
    //     cout<<b[i]<<' ';
    // }
    // cout<<'\n';
    // cout<<t<<'\n';
    int p=(t+1)/2;
    int l=-1,r=-1;
    for(int i=p;i<=n;i++){
        if(b[i]!=b[p]){
            r=b[p];
            break;
        }
    }
    for(int i=p;i>=1;i--){
        if(b[i]!=b[p]){
            l=b[p];
            break;
        }
    }
    vector<int> ans;
    if(l>0)ans.push_back(l);
    ans.push_back(b[p]);
    if(r>0)ans.push_back(r);
    // for(auto it : ans){
    //     cout<<it<<"\n";
    // }
    cout<<ans[rand()%ans.size()]<<'\n';

}
// 2 2 2 7 7 8 8 8 8 8 8 8 11 11 11 11 11 11 11 43 43 43 49 49 49 49 49 49 49 49 49 49 49 49 49 49 49 49 49 49 49 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 59 59 59 59 59 59 71 75 75 75 75 75 75 75 75 90 90 93 93 93 93 99    
// 2 2 2 7 7 8 8 8 8 8 8 8 11 11 11 11 11 11 11 43 43 43 49 49 49 49 49 49 49 49 49 49 49 49 49 49 49 49 49 49 49 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 59 59 59 59 59 59 71 75 75 75 75 75 75 75 75 90 90 93 93 93 93 99
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    srand(time(0));
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
}