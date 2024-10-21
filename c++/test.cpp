#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    vector<string> s;
    s.push_back("+"); s.push_back("-"); s.push_back("?");
    sort(s.begin(), s.end());
    for(auto ss : s) {
        cout << ss << " ";
    }
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