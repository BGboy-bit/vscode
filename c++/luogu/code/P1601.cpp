#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string a, b; cin >> a >> b;
    ll n = a.size(), m = b.size();
    reverse(a.begin(), a.end()); reverse(b.begin(), b.end());
    ll c = 0;
    string ans;
    for(ll i = 0; i < max(n, m); i ++ ) {
        char x = '0' + c; c = 0;
        if(i < n) {
            x += a[i] - '0';
        } 
        if(i < m) {
            x += b[i] - '0';
        }
        if(x > '9') {
            ans.push_back(x - 10); c = 1;
        } else {
            ans.push_back(x);
        }
    }
    if(c == 1) {
        ans.push_back('1');
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}