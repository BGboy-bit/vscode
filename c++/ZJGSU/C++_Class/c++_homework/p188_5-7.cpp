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

class Cat {
    public : 
        static int numOfCats;
        static int getNumOfCats() {
            return numOfCats;
        }
};

int Cat::numOfCats = 1;

void Solve() {
    Cat cat1;
    int num = cat1.getNumOfCats();
    cout << "cat1's number = " << num << "\n";
    cat1.numOfCats ++ ;
    num = cat1.getNumOfCats();
    cout << "cat1's number = " << num << "\n";
    Cat cat2;
    num = cat2.getNumOfCats();
    cout << "cat2's number = " << num << "\n";
    cat2.numOfCats ++ ;
    num = cat2.getNumOfCats();
    cout << "cat2's number = " << num <<  "\n";
    num = cat1.getNumOfCats();
    cout << "cat1's number = " << num << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}