#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int MAX = 3e5 + 10;
ll a[MAX];

void Solve() {
    ll n, cnt = 0;
    int f = 2;//f = 0 表示递减，f = 1 表示递增
    cin >> n;
    for(ll i = 1; i <= n;i ++) {
        cin >> a[i];

        if(f == 2) {
            if(i == 1){
                if(n == 1) cnt ++;
                continue;
            } 
            if(a[i] > a[i - 1]) {
                f = 1;
                cnt ++;
            }
            else if(a[i] < a[i - 1]) {
                f = 0;
                cnt ++;  
            }
        }

        else if(a[i] > a[i - 1]) {
            if(f == 0) {
                f = 1;
                cnt ++;
            }
        }
        else if(a[i] < a[i - 1]) {
            if(f == 1) {
                f = 0;
                cnt ++;
            }
            
        }
        if(i == n) cnt ++;
    }
    cout << cnt << "\n";
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