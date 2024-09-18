#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
constexpr ll INF = 2E18+10;

void solve()
{
    vector<ll> a(33);
    for(ll i = 1; i <= 32; i ++ ) cin >> a[i];
    ll y = a[1];
    sort(a.begin() + 1, a.end());
    ll x;
    for(ll i = 1; i <= 32; i ++ ) {
        if(a[i] == y) {
            x = i;
            break;
        } 
    }
    if(x <= 2) {
        cout << "32\n"; return ;
    } else if(x <= 6) {
        cout << "16\n"; return ;
    } else if(x <= 13) {
        cout << "8\n"; return ;
    } else if(x <= 27) {
        cout << "4\n"; return ;
    } else if(x <= 31) {
        cout << "2\n"; return ;
    } else cout << "1\n";
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