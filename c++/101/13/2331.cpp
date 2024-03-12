#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (long long)2e+18
const int N=2e6+10;
const int mod=1e9;
int m,n;
double sum=0;
void solve()
{
 sum=0;
 sum+=m*n;
 if(m%2==0){
  
 }
 else if(n%2==0){
  
 }else{
  sum+=sqrt(2)-1;
 }
 cout<<fixed<<setprecision(2)<<sum<<'\n';
}

int main()
{
// ios::sync_with_stdio(false);
 //   cin.tie(0),cout.tie(0);
    
    while(cin>>m>>n){
     solve();
 }
}