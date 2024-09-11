#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

typedef __int128 i128;

inline i128 read() {
    i128 x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x;
}

inline void print(i128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) {
        print(x / 10);
    }
    putchar(x % 10 + '0');
}

void Solve() {
    ll n; cin >> n;
    string L, R;
    cin >> L >> R;
    ll half = n / 2;
    string l1_str = L.substr(0, half);
    string l2_str = L.substr(half);
    string r1_str = R.substr(0, half);
    string r2_str = R.substr(half);
    i128 l1 = 0, l2 = 0, r1 = 0, r2 = 0, top = 0;
    for (char c : l1_str) {
        l1 = l1 * 10 + (c - '0');
    }
    for (char c : l2_str) {
        l2 = l2 * 10 + (c - '0');
    }
    for (char c : r1_str) {
        r1 = r1 * 10 + (c - '0');
    }
    for (char c : r2_str) {
        r2 = r2 * 10 + (c - '0');
    }
    for(ll i = 1; i <= half; i ++ ) {
        top = top * 10 + 9;
    }
    
    i128 summ = sqrtl(top) + 1;
    i128 sql1 = sqrtl(l1), sql2 = sqrtl(l2), sqr1 = sqrtl(r1), sqr2 = sqrtl(r2);
    i128 ans = 0;
    if(r1 == l1) {
    	if(sqr1 * sqr1 == r1) {
	        ans = sqr2 - sql2;
	        if(sql2 * sql2 == l2) ans ++ ; 
	    } 
		print(ans); return ;
    }

    if(sqr1 * sqr1 == r1) {
        ans += sqr2 + 1;
        sqr1 -- ;
    }
    if(sql1 * sql1 == l1) {
        ans += sqrtl(top) - sql2;
        if(sql2 * sql2 == l2) ans ++ ;
    }
    ans += (sqr1 - sql1) * summ;
    print(ans);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
