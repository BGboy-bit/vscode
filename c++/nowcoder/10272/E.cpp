#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;

constexpr ll INF = 2E18 + 10;
constexpr int N = 2E6 + 10;

void solve()
{
    int mx,my;
    cin>>mx>>my;
    string s;
    cin>>s;
    int n=s.size();

    int ex=0,ey=0;
    int nu=0,nd=0,nl=0,nr=0;
    vector<string> ans;
    for(int i=0;i<n;i++){
        if(s[i]=='U'){ey++;nu++;}
        if(s[i]=='D'){ey--;nd++;}
        if(s[i]=='L'){ex--;nl++;}
        if(s[i]=='R'){ex++;nr++;}
    }
    if(mx==0&&my==0||mx==ex&&my==ey){
        cout<<"Impossible\n";
        return ;
    }

    if(ex==0||ey==0){
        string t;
        if(ey==0){
            if(nu>0&&nd>0){
                t+="U";
                for(int i=1;i<=nu+nd-2;i++){
                    if(i%2==1){
                        t+="D";
                    }else{
                        t+="U";
                    }
                }
                if(ex>=0){
                    for(int i=1;i<=nl;i++){
                        t+="RL";
                    }
                    for(int i=1;i<=nr-nl;i++){
                        t+="R";
                    }
                }else{
                    for(int i=1;i<=nr;i++){
                        t+="LR";
                    }
                    for(int i=1;i<=nl-nr;i++){
                        t+="L";
                    }
                }
                t+="D";
                ans.push_back(t);
                t.clear();
                t+="D";
                for(int i=1;i<=nu+nd-2;i++){
                    if(i%2==0){
                        t+="D";
                    }else{
                        t+="U";
                    }
                }
                if(ex>=0){
                    for(int i=1;i<=nl;i++){
                        t+="RL";
                    }
                    for(int i=1;i<=nr-nl;i++){
                        t+="R";
                    }
                }else{
                    for(int i=1;i<=nr;i++){
                        t+="LR";
                    }
                    for(int i=1;i<=nl-nr;i++){
                        t+="L";
                    }
                }
                t+="U";
                ans.push_back(t);
                t.clear();
            }
        }else{
            if(nl>0&&nr>0){
                t+="R";
                for(int i=1;i<=nl+nr-2;i++){
                    if(i%2==1){
                        t+="L";
                    }else{
                        t+="R";
                    }
                }
                if(ey>=0){
                    for(int i=1;i<=nd;i++){
                        t+="UD";
                    }
                    for(int i=1;i<=nu-nd;i++){
                        t+="U";
                    }
                }else{
                    for(int i=1;i<=nu;i++){
                        t+="DU";
                    }
                    for(int i=1;i<=nd-nu;i++){
                        t+="D";
                    }
                }
                t+="L";
                ans.push_back(t);
                t.clear();
                t+="L";
                for(int i=1;i<=nl+nr-2;i++){
                    if(i%2==0){
                        t+="L";
                    }else{
                        t+="R";
                    }
                }
                if(ey>=0){
                    for(int i=1;i<=nd;i++){
                        t+="UD";
                    }
                    for(int i=1;i<=nu-nd;i++){
                        t+="U";
                    }
                }else{
                    for(int i=1;i<=nu;i++){
                        t+="DU";
                    }
                    for(int i=1;i<=nd-nu;i++){
                        t+="D";
                    }
                }
                t+="R";
                ans.push_back(t);
                t.clear();
            }
        }
    }

    if(ex>=0&&ey>=0){
        string t;
        for(int i=1;i<=nl;i++){
            t+="RL";
        }
        for(int i=1;i<=nr-nl;i++){
            t+="R";
        }
        for(int i=1;i<=nd;i++){
            t+="UD";
        }
        for(int i=1;i<=nu-nd;i++){
            t+="U";
        }
        ans.push_back(t);
        t.clear();
        for(int i=1;i<=nd;i++){
            t+="UD";
        }
        for(int i=1;i<=nu-nd;i++){
            t+="U";
        }
        for(int i=1;i<=nl;i++){
            t+="RL";
        }
        for(int i=1;i<=nr-nl;i++){
            t+="R";
        }
        ans.push_back(t);
    }
    if(ex<=0&&ey>=0){
        string t;
        for(int i=1;i<=nr;i++){
            t+="LR";
        }
        for(int i=1;i<=nl-nr;i++){
            t+="L";
        }
        for(int i=1;i<=nd;i++){
            t+="UD";
        }
        for(int i=1;i<=nu-nd;i++){
            t+="U";
        }
        ans.push_back(t);
        t.clear();
        for(int i=1;i<=nd;i++){
            t+="UD";
        }
        for(int i=1;i<=nu-nd;i++){
            t+="U";
        }
        for(int i=1;i<=nr;i++){
            t+="LR";
        }
        for(int i=1;i<=nl-nr;i++){
            t+="L";
        }
        ans.push_back(t);
    }
    if(ex<=0&&ey<=0){
        string t;
        for(int i=1;i<=nr;i++){
            t+="LR";
        }
        for(int i=1;i<=nl-nr;i++){
            t+="L";
        }
        for(int i=1;i<=nu;i++){
            t+="DU";
        }
        for(int i=1;i<=nd-nu;i++){
            t+="D";
        }
        ans.push_back(t);
        t.clear();
        for(int i=1;i<=nu;i++){
            t+="DU";
        }
        for(int i=1;i<=nd-nu;i++){
            t+="D";
        }
        for(int i=1;i<=nr;i++){
            t+="LR";
        }
        for(int i=1;i<=nl-nr;i++){
            t+="L";
        }
        ans.push_back(t);
    }
    if(ex>=0&&ey<=0){
        string t;
        for(int i=1;i<=nl;i++){
            t+="RL";
        }
        for(int i=1;i<=nr-nl;i++){
            t+="R";
        }
        for(int i=1;i<=nu;i++){
            t+="DU";
        }
        for(int i=1;i<=nd-nu;i++){
            t+="D";
        }
        ans.push_back(t);
        t.clear();
        for(int i=1;i<=nu;i++){
            t+="DU";
        }
        for(int i=1;i<=nd-nu;i++){
            t+="D";
        }
        for(int i=1;i<=nl;i++){
            t+="RL";
        }
        for(int i=1;i<=nr-nl;i++){
            t+="R";
        }
        ans.push_back(t);
    }   
    auto check=[&](string x)->bool{
        int endx=0,endy=0;
        for(auto c : x){
            if(c=='U'){endy++;}
            if(c=='D'){endy--;}
            if(c=='L'){endx--;}
            if(c=='R'){endx++;}
            if(endx==mx&&endy==my) return 0;
        }
        return 1;
    };

    for(auto str : ans){
        if(check(str)){
            cout<<str<<"\n";
            return ;
        }
    }
    cout<<"Impossible"<<"\n";
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