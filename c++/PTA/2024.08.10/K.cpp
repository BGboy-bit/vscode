    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;

    struct Node {
        ll x, y;
    };
    
    bool cmp(Node u, Node v) {
        if(u.x == v.x) 
            return u.y > u.y;
        else 
            return v.x > v.y;
    }

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        ll n; cin >> n;
        vector<Node> nd(n + 1);
        for(ll i = 1; i <= n; i ++ ) {
            ll x, y; cin >> x >> y;
            nd[i].x = x, nd[i].y = y;
        }
        sort(nd.begin() + 1, nd.end(), cmp);
        cout << "YES\n";
        for(ll i = 1; i < n; i ++ ) {
            cout << nd[i].x << " " << nd[i].y << "\n";
        }
        return 0;
    }