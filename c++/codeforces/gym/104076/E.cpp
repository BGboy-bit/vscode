#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;

int n,k;

bool ac = 0;
void dfs(ll res, ll pos, vector<ll> &a) {
    if(pos == k) {
        if(n % 2 == 0 && res == 0 || n % 2 && (res == 1 || res == -1))
            ac = 1;
        return ;
    }
    dfs(res + a[pos], pos + 1, a);
    dfs(res - a[pos], pos + 1, a);
}

void test() {
    k = 6;
    for(ll i = 1; i <= 50; i ++ ) {
        ac = 0;
        n = i;
        ll x1 = n / k;
        ll x2 = n % k;
        vector<ll> a(k, x1);
        for(ll i = 0; i < x2; i ++ ) {
            a[i] ++ ;
        }
        dfs(0, 0, a);
        cout << i << ": ";
        if(ac) 
            cout << "Yes\n";
        else 
            cout << "No\n";
    }
}

void solve() {
    cin >> n >> k;
    if(k % 2 == 0) {
        cout << "Yes\n";
        return ;
    }
    ll x = n / k;
    if(n - k * x > x - 2 && k * (x + 1) - n > x - 1) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--){
        solve();
        // test();
    }
}