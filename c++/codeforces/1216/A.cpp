#include<bits/stdc++.h>
using namespace std;

int a[110];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    int n, cnt1 = 0, cnt2 = 0;
    cin >> n;
    for(int i = 0; i < n; i ++ ) {
        cin >> a[i];
        if(a[i] % 2 != 0) cnt1 ++;
        else cnt2 ++;
    }
    cout << min(cnt1, cnt2) << "\n";
    return 0;
}