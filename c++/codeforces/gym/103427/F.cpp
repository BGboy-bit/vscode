#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;

constexpr int N =1000+10;
string t[N];
vector<vector<int>> a(26),b(30, vector<int>(1010));
int x[40];
void solve()
{
    int n;
    string s;
    cin>>n;
    cin>>s;
    s=' '+s;

    for(int l=1;l<=n;l++){
        a[s[l]-'a'].push_back(l);
        for(int i=0;i<26;i++){
            b[i][l] = b[i][l - 1];
            if(s[l]-'a' == i) {
                b[i][l] ++ ;
            } 
        }

    }
    vector<int>p(30);
    int sum=0;
    vector<ll> pos(n + 1);
    for(int i=n;i>=1;i--){
        pos[i] = sum;
        if(p[s[i]-'a']==0){
            p[s[i]-'a']=1;
            sum++;
        }
    }
    vector<string> ss;
    for(ll r = 1; r <= n; r ++ ) {
        string s1; 
        vector<ll> mp(26);
        for(ll j = 0; j < 26; j ++ ) {
            ll res = upper_bound(a[j].begin(), a[j].end(), r) - a[j].begin() - 1;
            if(res == -1) continue;
            ll ppp = 0; 
            for(ll i = 0; i < 26; i ++ ) {
                if(b[i][r] - b[i][a[j][res]]) {
                    ppp ++ ;
                }
            }
            mp[j] = 'a' + ppp;
        }
        for(ll i = 1; i <= r; i ++ ) {
            s1.push_back(mp[s[i] - 'a']);
        }
        ss.push_back(s1);
    }
    sort(ss.begin(), ss.end());
    cout << ss[ss.size() - 1] << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
}