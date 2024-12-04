#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using PII = pair<int,int>;

constexpr ll INF = 2E18 + 10;
constexpr int N = 2E6 + 10;

void solve()
{
    string s; cin >> s;
    ll n = s.size();
    s = "!" + s;
    if(s[1] != '>') {
        cout << "No\n"; return ;
    }
    ll pos = 0;
    for(ll i = n; i > 1; i -- ) {
        if(s[i] == '-') {
            pos = i; break;
        }
    }
    if(pos > n - 3 || pos == 0) {
        cout << "No\n"; return ;
    }

    vector<pair<ll, ll>> ans;
    for(ll i = n; i >= pos + 3; i -- ) {
            ans.push_back({1, i});
    }
    for(ll i = 2; i < pos; i ++ ) {
        if(s[i] == '>')
            ans.push_back({i, pos + 3 - i + 1});
    }

    cout << "Yes " << ans.size() << "\n";
    for(ll i = 0; i < ans.size(); i ++ ) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
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