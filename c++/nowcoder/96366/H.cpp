#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, q; cin >> n >> q;
    string s; cin >> s;
    vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i ++ ) {
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
    for (int i = 0, l = 0, r = -1; i < n; i ++ ) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k ++ ;
        }
        d2[i] = k -- ;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k;
        }
    }
    vector<vector<ll>> pre(26, vector<ll>(n, 0));
    vector<vector<ll>> odd(26, vector<ll>(n, 0)), even(26, vector<ll>(n, 0));
    for(ll i = 0; i < n; i ++ ) {
        for(ll j = 0; j < 26; j ++ ) {
            if(i > 0) {
                pre[j][i] = pre[j][i - 1]; 
                odd[j][i] = odd[j][i - 1];
                even[j][i] = even[j][i - 1];
            }
            if(s[i] - 'a' == j) {
                pre[j][i] ++ ;
                if(i % 2 == 1) odd[j][i] ++ ;
                else even[j][i] ++ ;
            }
        }
    }

    while(q -- ) {
        ll l, r; cin >> l >> r; l -- , r -- ;
        ll mid = l + r + 1 >> 1;
        ll ans = 0;
        ll len = r - l + 1;
        if(len % 2 == 1) {
            if(d1[mid] < len / 2 + 1) ans += len;  
        } else {
            if(d2[mid] < len / 2) ans += len;
        }
        if(l > 0 && pre[s[r] - 'a'][r] - pre[s[r] - 'a'][l - 1] != len || l == 0 && pre[s[r] - 'a'][r] != len) {
            ll x = len % 2 == 0 ? len - 2 : len - 1;
            if(x >= 2)
                ans += (x + 2) * ((x - 2) / 2 + 1) / 2;
        }
        if(len % 2 == 0) {
            if(l % 2 == 1 && ((odd[s[l] - 'a'][r] - odd[s[l] - 'a'][l - 1]) != len / 2 || 
            (even[s[r] - 'a'][r] - even[s[r] - 'a'][l - 1] != len / 2))) {
                ll x = len % 2 == 1 ? len - 2 : len - 1;
                if(x >= 3)
                    ans += (x + 3) * ((x - 3) / 2 + 1) / 2;
            }
            if(l % 2 == 0 && l > 0 && ((even[s[l] - 'a'][r] - even[s[l] - 'a'][l - 1]) != len / 2 || 
            (odd[s[r] - 'a'][r] - odd[s[r] - 'a'][l - 1] != len / 2))) {
                ll x = len % 2 == 1 ? len - 2 : len - 1;
                if(x >= 3)
                    ans += (x + 3) * ((x - 3) / 2 + 1) / 2;                
            }
            if(l == 0 && (even[s[l] - 'a'][r]  != len / 2 || odd[s[r] - 'a'][r] != len / 2)) {
                ll x = len % 2 == 1 ? len - 2 : len - 1;
                if(x >= 3)
                    ans += (x + 3) * ((x - 3) / 2 + 1) / 2;                  
            }
        } else {
            if(l % 2 == 1 && ((odd[s[l] - 'a'][r] - odd[s[l] - 'a'][l - 1]) != len / 2 + 1 || 
            (even[s[r - 1] - 'a'][r] - even[s[r - 1] - 'a'][l - 1] != len / 2))) {
                ll x = len % 2 == 1 ? len - 2 : len - 1;
                if(x >= 3)
                    ans += (x + 3) * ((x - 3) / 2 + 1) / 2;
            }
            if(l % 2 == 0 && l > 0 && ((even[s[l] - 'a'][r] - even[s[l] - 'a'][l - 1]) != len / 2 + 1 || 
            (odd[s[r - 1] - 'a'][r] - odd[s[r - 1] - 'a'][l - 1] != len / 2))) {
                ll x = len % 2 == 1 ? len - 2 : len - 1;
                if(x >= 3)
                    ans += (x + 3) * ((x - 3) / 2 + 1) / 2;
            }
            if(l == 0 && (even[s[l] - 'a'][r]  != len / 2 + 1 || odd[s[r - 1] - 'a'][r] != len / 2)) {
                ll x = len % 2 == 1 ? len - 2 : len - 1;
                if(x >= 3)
                    ans += (x + 3) * ((x - 3) / 2 + 1) / 2;                  
            }
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1; cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}