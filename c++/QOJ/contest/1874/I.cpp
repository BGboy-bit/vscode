#include<bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
using pii = pair<int,int>;

constexpr ll N = 2E6 + 10, INF = 2E18 + 10;

void solve()
{
    string a, b; cin >> a >> b;
    ll a1 = 0, b1 = 0;
    for(ll i = 0; i < a.size(); i ++ ) {
        a1 += a[i] - '0';
    }
    for(ll i = 0; i < b.size(); i ++ ) {
        b1 += b[i] - '0';
    }
    if(a1 % 3 == 1 && b1 % 3 == 1 || a1 % 3 == 2 && b1 % 3 == 2 || a1 % 3 == 2 && b1 % 3 == 0 || a1 % 3 == 0 && b1 % 3 == 1) {
        cout << "1\n";
    } else {
        cout << "0\n";
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
}