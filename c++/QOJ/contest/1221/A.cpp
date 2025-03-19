#include<bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
using PII = pair<int,int>;

constexpr int N = 2E6 + 10;
constexpr ll INF = 2E18 + 10;

void solve()    
{
    int n;
    cin>>n;
    int las = 0;
    int l = 1,r = n; 
    while (1){
        if(las == 0) {
            cout << "? " << l << endl;
            ll x; cin >> x;
            if(x == 0) {
                cout << "! " << l << endl;
                return ;
            } 
            l ++ ;
            las = x;
        } else {
            ll mid = l + r >> 1;
            cout << "? " << mid << endl;
            ll x; cin >> x;
            if(x == las) {
                cout << "! " << mid << endl;
                return ;
            }
            if(x < las) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
            las = x;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
}