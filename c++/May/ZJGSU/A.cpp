#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int MAX = 3e5 + 10;
int a[MAX];

void Solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    sort(a, a + n - 1);
    if(a[n - 1] < a[0]) cout << "0" << "\n";
    else {
        for(int i = 0; i < n - 1; i ++ ) {
            if(a[n - 1] <= a[i + 1] && a[n - 1] >= a[i]) {
                cout << i + 1 << "\n";
                break;
            }
        }
    } 
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
//  cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}