#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 0;//∂‡◊È ‰»Î

class Document {
private :
    string name;
public :
    void SetName(string n) {
        name = n;
    }
    string GetName() {
        return name; 
    }
};

class Book : public Document {
private :
    ll pageCount;
public :
    void SetPage(ll page) {
        pageCount = page;
    }
    ll GetPage() {
        return pageCount;
    }
};

void Solve() {
    Book b;
    cout <<  "book's name: ";
    string s; cin >> s;
    b.SetName(s);
    cout << "book's page: ";
    ll p; cin >> p;
    b.SetPage(p);
    cout << b.GetName() << "'s page: " << b.GetPage() << "\n"; 
}


signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}