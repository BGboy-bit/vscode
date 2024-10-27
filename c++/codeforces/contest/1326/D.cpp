#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    string s; cin >> s;
    ll n = s.size(), m = n;
    ll sum = 0;
    for(ll i = 0; i < n / 2; i ++ ) {
        if(s[i] != s[n - i - 1]) break;
        sum ++ ;
    }
    string ans1 = s.substr(0, sum);
    s = s.substr(sum, n - sum * 2);
    n = s.size();
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
    string ans2;
    ll maxx = 0, pos;
    for(ll i = 0; i < n; i ++ ) {
        if((i - d1[i] + 1 == 0 || i + d1[i] == n) && maxx < d1[i] * 2 - 1) {
            maxx = d1[i] * 2 - 1; pos = i;
        }
    }
    if(maxx > 0) {
        ans2 = s.substr(pos - maxx / 2, maxx);
    }
    for(ll i = 0; i < n; i ++ ) {
        if((i - d2[i] == 0 || i + d2[i] == n) && maxx < d2[i] * 2) {
            maxx = d2[i] * 2; pos = i;
        }
    }
    if(maxx > ans2.size()) {
        ans2 = s.substr(pos - maxx / 2, maxx);
    }
    if(ans1.size() * 2 <= m) {
        cout << ans1 + ans2;
        reverse(ans1.begin(), ans1.end());
        cout << ans1 << "\n";
    } else {    
        cout << ans1 << "\n";
    }
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