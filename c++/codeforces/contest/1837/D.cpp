#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int MAX = 2e5 + 10;
ll n, pos;
char str[MAX];

void Color(ll f, vector<ll> &cnt1, vector<ll> &cnt2, vector<ll> &color) {
    if(f == 1) {
        while(cnt1[pos] > cnt2[pos]) {
            color[pos] = 1;
            pos ++;
        }
    }
    else {
        while(cnt1[pos] < cnt2[pos]) {
            color[pos] = 2;
            pos ++;
        }
    }
    if(f == 1) color[pos] = 1;
    else color[pos] = 2;
    pos ++;
}

void Solve() {
    cin >> n >> (str + 1);
    vector<ll> cnt1(n + 1, 0), cnt2(n + 2, 0);
    vector<ll> color(n + 1, 0); 
    ll cnt = 0, sum = 0;
    for(ll i = 1; i <= n; i ++ ) {
        if(str[i] == '(') cnt1[i] = cnt1[i - 1] + 1;
        else cnt1[i] = cnt1[i - 1];
    }
    for(ll i = 1; i <= n; i ++ ) {
        if(str[i] == ')') cnt2[i] = cnt2[i - 1] + 1;
        else cnt2[i] = cnt2[i - 1];
    } 
    if(cnt1[n] != cnt2[n]) {
        cout << "-1" << "\n";
        return;
    }
    pos = 1;
    ll sum1 = 0, sum2 = 0;
    while(pos <= n) {
        if(str[pos] == '(') {
            Color(1, cnt1, cnt2, color);
            sum1 ++;
        }
        else {
            Color(2, cnt1, cnt2, color);
            sum2 ++;
        }
    }
    if(sum1 > 0 && sum2 > 0) cnt = 2;
    else cnt = 1;
    cout << cnt << "\n";
    for(ll i = 1; i <= n; i ++ ) {
        if(cnt == 1) color[i] = 1;
        cout << color[i] << " "; 
    }
    cout << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}