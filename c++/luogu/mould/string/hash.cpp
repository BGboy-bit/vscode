// P3370 【模板】字符串哈希
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ull base = 131;
ull a[10010];
ll prime = 233317; 
ull mod = 212370440130137957ll;

ull hashe(string ss) {
    ll len = ss.length();
    ull anss = 0;
    for (ll i = 0; i < len; i ++ )
        anss = (anss * base + (ull)ss[i]) % mod + prime;
    return anss;
}

int main() {
    ll n,ans = 0;
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; i ++ ) {
        string str; cin >> str;
        a[i] = hashe(str);
    }
    sort(a + 1, a + n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        if(a[i] != a[i - 1]) ans ++ ;
    }
    cout << ans << "\n";
    return 0;
}