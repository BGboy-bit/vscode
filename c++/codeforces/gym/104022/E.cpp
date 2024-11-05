#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;

constexpr ll INF = 2E18 + 10;
constexpr int N = 2E6 + 10;
string s[]={"-F", "-Cl", "-Br", "-I", "-CH3", "-CH2CH3", "-CH2CH2CH3", "-H"};
void solve()
{
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    int r1,r2,r3,r4;
    for(int i=0;i<8;i++){
        if(s1==s[i]){
            r1=i+1;
            break;
        }
    }
    for(int i=0;i<8;i++){
        if(s2==s[i]){
            r2=i+1;
            break;
        }
    }
    for(int i=0;i<8;i++){
        if(s3==s[i]){
            r3=i+1;
            break;
        }
    }
    for(int i=0;i<8;i++){
        if(s4==s[i]){
            r4=i+1;
            break;
        }
    }
    if(r1==r3||r2==r4){
        cout<<"None\n";
        return ;
    }
    if(r1==r2||r3==r4){
        cout<<"Cis\n";
        return ;
    }
    if(r1==r4||r2==r3){
        cout<<"Trans\n";
        return ;
    }
    int p1,p2;
    if(r1<r3){
        p1=1;
    }else p1=2;

    if(r2<r4){
        p2=1;
    }else p2=2;
    if(p1==p2){
        cout<<"Zasamman\n";
        return ;
    }
    cout<<"Entgegen\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T = 1;
    cin>>T;
    while(T--){
        solve();
    }
}