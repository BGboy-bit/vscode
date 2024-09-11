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

class Mammal {
public : 
    virtual void speak() {
        cout << "Mammal speak" << "\n";
    }
};
class Dog : public Mammal {
public : 
    void speak() {
        cout << "Dog speak" << "\n";
    }
};

void Solve() {
    Dog d;
    d.speak();
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