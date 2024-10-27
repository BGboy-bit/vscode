#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, k; cin >> n >> k;
    string s; cin >> s; s = "!" + s;
    ll sum = 1, pos = 0;
    char res = s[1];
    bool ff = 0;
    for(ll i = 2; i <= n; i ++ ) {
        if(s[i] != res) {
            if(sum == k) {
                res = s[i]; sum = 1;
            } else {
                if(sum < k) 
                    pos = i - 1; 
                else {
                    ff = 1; pos = i - k - 1;
                }
                break;
            }
        } else {
            sum ++ ;
        }     
    }
    if(sum > k & !ff)  pos = n - k;
    if(pos == 0) {
        cout << n << "\n"; return ;
    }
    string s1 = s.substr(1, pos), s2 = s.substr(pos + 1, n - pos);
    reverse(s1.begin(), s1.end());
    s = "!" + s2 + s1;
    sum = 1, res = s[1];
    for(ll i = 2; i <= n; i ++ ) {
        if(s[i] != res) {
            if(sum == k) {
                res = s[i]; sum = 1;
            } else {
                cout << "-1\n"; return ;
            }
        } else {
            sum ++ ; 
            if(sum > k) {
                cout << "-1\n"; return ;
            }
        }
    }
    cout << pos << "\n";
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
