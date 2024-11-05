#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;

constexpr ll INF = 2E18 + 10;
constexpr int N = 2E6 + 10;

string s1="URDL",s2="ULDR",s3="DLUR",s4="DRUL";

void solve()
{
    int mx,my;
    cin>>mx>>my;
    string s;
    cin>>s;
    int su=0,sd=0,sl=0,sr=0;
    int p;
    if(mx>=0&&my>=0){
        p=1;
    }
    if(mx<=0&&my>=0){
        p=2;
    }
    if(mx<=0&&my<=0){
        p=3;
    }
    if(mx>=0&&my<=0){
        p=4;
    }

    for(int i=0;i<s.size();i++){
        if(s[i]=='U')su++;
        if(s[i]=='D')sd++;
        if(s[i]=='L')sl++;
        if(s[i]=='R')sr++;
    }

    if(mx==0&&my==0){
        cout<<"Impossible\n";
     
        return;
    }
    if(mx==sr-sl&&my==su-sd){
        cout<<"Impossible\n";
        return;
    }
    string str;
    while(su&&sd&&sl&&sr){
        su--;
        sl--;
        sr--;
        sd--;
        if(p==1)str=str+s3;
        if(p==2)str=str+s4;
        if(p==3)str=str+s1;
        if(p==4)str=str+s2;
    }
    while(sl&&sr){
        sl--;
        sr--;
        if(mx>=0){
            str=str+"LR";
        }else {
            str=str+"RL";
        }
    }
    while(su&&sd){
        su--;
        sd--;
        if(my>=0){
            str=str+"DU";
        }else {
            str=str+"UD";
        }
    }
    if(mx==0){
        while(sl){
            sl--;
            str=str+"L";
        }
        while(sr){
            sr--;
            str=str+"R";
        }
        while(su){
            su--;
            str=str+"U";
        }
        while(sd){
            sd--;
            str=str+"D";
        }
    }
    else if(my==0){
        while(su){
            su--;
            str=str+"U";
        }
        while(sd){
            sd--;
            str=str+"D";
        }
        while(sl){
            sl--;
            str=str+"L";
        }
        while(sr){
            sr--;
            str=str+"R";
        }
    }else {
        if(sr-sl!=mx){
            while(sl){
                sl--;
                str=str+"L";
            }
            while(sr){
                sr--;
                str=str+"R";
            }
            while(su){
                su--;
                str=str+"U";
            }
            while(sd){
                sd--;
                str=str+"D";
            }
        }else {
            while(su){
                su--;
                str=str+"U";
            }
            while(sd){
                sd--;
                str=str+"D";
            }
            while(sl){
                sl--;
                str=str+"L";
            }
            while(sr){
                sr--;
                str=str+"R";
            }
        }
    }
    int f=1;
    int x=0,y=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='L')x--;
        if(str[i]=='R')x++;
        if(str[i]=='U')y++;
        if(str[i]=='D')y--;
        if(x==mx&&y==my){
            f=0;
            break;
        }
    }
    if(!f){
        cout<<"Impossible\n";
        return;
    }
    cout<<str<<'\n';
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