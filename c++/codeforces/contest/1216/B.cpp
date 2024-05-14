#include<bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 10;
int a[MAX];

void Solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    int minn = INT_MAX, ans = 0;
    for(int i = n - 1; i >= 0; i -- ) {
        if(minn < a[i]) ans ++;
        minn = min(minn, a[i]);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    int T = 1;
    cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}