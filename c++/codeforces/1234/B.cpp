#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 2e5 + 10;
ll n, k, x, cnt;
// unordered_map<ll, bool> mp;
set<ll> s;
deque<ll> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> x;
        if(!s.count(x)) {
            s.insert(x);
            q.emplace_front(x);
            if(cnt == k) {
                s.erase(q.back());
                q.pop_back();
            }
            else cnt ++;
        }
    }
    cout << cnt << "\n";
    // while(!q.empty()) {
    //     cout << q.front() << " ";
    //     q.pop_front();
    // }
    for(auto i : q) cout << i << " ";
    return 0;
}