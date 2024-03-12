#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a <= c && b <= d || a <= d && b <= c) cout << "YES";
    else cout << "NO";
    return 0;
}