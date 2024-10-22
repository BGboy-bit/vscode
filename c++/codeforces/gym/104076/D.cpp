#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;

struct Node {
    ll x, y;
    ll ti, cn, nu;
};

// bool fff = 0;

void Solve() {
    ll a, b; cin >> a >> b;
    cin.get();

    // if(a == 1 && b == 19917 && n == 999) {
    //     fff = 1;
    // }

    ll sum = 0, cnt = 0;
    vector<string> s(m + 1);
    vector<Node> ss;
    for(ll i = 1; i <= m; i ++ ) {
        getline(cin, s[i]);
    }

    // if(fff && n == 812) {
    //     cout << a << " " << b << "\n";
    //     for(ll i = 1; i <= m; i ++ ) {
    //         cout << s[i] << '\n';
    //     }
    // }
    // if(fff) return;

    bool ac = 0;
    for(ll i = 1; i <= m; i ++ ) {
        if(s[i][0] == '+') {
            cnt ++ ;
            ll x = 0;
            for(ll j = 2; j < s[i].size(); j ++ ) {
                if(s[i][j] == '/') {
                    sum += (x - 1) * 20;
                    x = 0;
                } else {
                    x = x * 10 + (ll)(s[i][j] - '0');
                }
            }
            sum += x;
        } else if(s[i][0] == '?') {
            ll x = 0, y = 0;
            bool ff = 0;
            for(ll j = 2; j < s[i].size(); j ++ ) {
                if(!ff) {
                    if(s[i][j] == ' ') {
                        ff = 1;
                    } else {
                        x = x * 10 + s[i][j] - '0';
                    }
                } else {
                    y = y * 10 + s[i][j] - '0';
                }
            }
            ss.push_back({x, y, 0, y - x, i});
        }
    }
    if(cnt == a && sum == b) {
        ac = 1;
    }
    ll maxx = (1 << ss.size());
    bitset<14> bt; unsigned long val;
    if(!ac && !ss.empty() && a - cnt <= ss.size()) {
        do {
            bool f = 0;
            while(bt.count() != a - cnt) {
                val = bt.to_ulong(); val ++ ; bt = bitset<14>(val);
                if(val >= maxx) f = 1;
            }
            if(f) break;
            ll summ = 0, summ1 = 59 * (a - cnt), summ2 = 0;
            for(ll i = 0; i < ss.size(); i ++ ) {
                if(!bt[i]) continue;
                summ += 240 + (ss[i].y - ss[i].x) * 20;
                summ2 += 20 * (ss[i].x - 1);                   
            }
            if(b - sum >= summ && b - sum <= summ + summ1 + summ2) {
                sum += summ;
                for(ll i = 0; i < ss.size(); i ++ ) {
                    if(!bt[i]) continue;
                    ss[i].cn ++ ;
                    while(b - sum >= 20 && ss[i].cn < ss[i].y) {
                        ss[i].cn ++ ;
                        sum += 20;
                    }
                    if(b - sum >= 59) {
                        ss[i].ti = 299;
                        sum += 59;
                    } else {
                        ss[i].ti = 240 + b - sum;
                        sum = b;
                    }
                } 
                ac = 1; break;
            }
            // cout << bt << "\n";
            val = bt.to_ulong(); val ++ ; bt = bitset<14>(val);
        } while(val < maxx);
    }

    if(ac) {
        cout << "Yes\n";
        for(ll i = 1; i <= m; i ++ ) {
            if(s[i][0] == '?') {
                for(ll j = 0; j < ss.size(); j ++ ) {
                    if(ss[j].nu == i) {
                        if(ss[j].ti == 0) {
                            cout << "- " << ss[j].y << "\n";
                        } else {
                            cout << "+ " << ss[j].cn << "/" << ss[j].ti << "\n";
                        }
                        break;
                    }
                }
            } else {
                cout << s[i] << "\n";
            }
        }
    } else {
        cout << "No\n"; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    while(n -- ) {
        Solve();
    }
    return 0;
}
