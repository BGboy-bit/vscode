#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    string s; cin >> s;
    ll n = s.size();
    vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i ++ ) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    vector<int> d2(n);
    for (int i = 0, l = 0, r = -1; i < n; i ++ ) {
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
    vector<ll> vis1(n + 1), vis2(n + 1);
    for(ll i = 1; i < n; i ++ ) {
        if(d1[i] - i == 1) vis1[i + d1[i] - 1] = 1;
        if(d2[i] - i == 0) vis1[i + d2[i] - 1] = 1;
        if(d1[i] + i == n) vis2[i - d1[i] + 1] = 1;
        if(d2[i] + i == n) vis2[i - d2[i]] = 1;
    }
    for(ll i = 1; i < n; i ++ ) {
        if(!vis1[i] && !vis2[i + 1]) {
            cout << "Yes\n";
            if(i + 1 < n) {
                cout << "2\n";
                cout << s.substr(0, i + 1) << " " << s.substr(i + 1, n - i - 1) << "\n";
            } else {
                cout << "1\n";
                cout << s << "\n";
            }
            return ;
        }
    }
    cout << "No\n"; return ;
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