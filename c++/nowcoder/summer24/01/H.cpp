#include<bits/stdc++.h>
#define int long long
using ll = long long;
using PII = std::array<int,2>;
using namespace std;
const ll INF = 2E18+10;
// struct cmp{bool operator()(const int & x, const int &y) const{ return x<y; }};
const int N = 2E6 + 10;

void SINGLE_TEST()
{
    int n,m;
    cin>>n;
    map<string,PII> a,b;
    int ans=INF;
    vector<string> s,w;
    vector<int> s1,s2,w1,w2;
    int t1,t2;
    int z1,z2;
    map<string,bool> vis1,vis2;
    for(int i=1;i<=n;i++){
        string ss;cin>>ss;
        int ss1,ss2;
        cin>>ss1>>ss2;
        s.push_back(ss);
        s1.push_back(ss1);
        s2.push_back(ss2);
        if(ss=="lzr010506"){
            t1=ss1;
            t2=ss2;
        }
        vis1[ss]=true;
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        string ss;cin>>ss;
        int ss1,ss2;
        cin>>ss1>>ss2;
        w.push_back(ss);
        w1.push_back(ss1);
        w2.push_back(ss2);
        if(ss=="lzr010506"){
            z1=ss1;
            z2=ss2;
        }
        vis2[ss]=true;
    }
    int p1=0,p2=0;
    for(int i=0;i<n;i++){
        if(s[i]=="lzr010506") continue;
        if(s1[i]>t1 || s1[i]==t1 && s2[i]<t2){
            p1++;
            if(vis2[s[i]]){
                p1--;
            }
        }
        
    }
    for(int i=0;i<m;i++){
        if(w[i]=="lzr010506") continue;
        if(w1[i]>z1 || w1[i]==z1 && w2[i]<z2){
            p2++;
            if(vis1[w[i]]){
                p2--;
            }
        }
        
    }
    cout<<min(p1,p2)+1<<"\n";
}

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);

    int SAMPLES = 1;
	// cin>>SAMPLES;
    while(SAMPLES--) SINGLE_TEST();
}
