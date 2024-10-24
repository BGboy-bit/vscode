#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    string s; cin >> s;
    ll n = s.size();
    vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k ++ ;
        }
        d1[i] = k -- ;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    vector<int> d2(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k;
        }
    }
    string ans;
    for(ll i = 0; i < n; i ++ ) {
        if((i - d1[i] + 1 == 0 || i + d1[i] == n) && d1[i] * 2 - 1 > ans.size()) {
            ans = s.substr(i - d1[i] + 1, d1[i] * 2 - 1);
        }
    }
    for(ll i = 0; i < n; i ++ ) {
        if((i - d2[i] == 0 || i + d2[i] == n) && d2[i] * 2 > ans.size()) {
            ans = s.substr(i - d2[i], d2[i] * 2);
        }
    }
    ll sum = 0;
    for(ll i = 0; i < n; i ++ ) {
        if(s[i] != s[n - i - 1] || sum * 2 >= n) break;
        sum ++ ;
    }
    if(sum * 2 + 1 > ans.size() && sum * 2 < n ) {
        ans = s.substr(0, sum + 1) + s.substr(n - sum, sum);   
    } else if(sum * 2 > ans.size() && sum * 2 == n) {
        ans = s.substr(0, sum) + s.substr(n - sum, sum);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T; cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}