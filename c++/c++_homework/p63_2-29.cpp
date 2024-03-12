#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 0;//∂‡◊È ‰»Î

bool isPrime(ll x) {
    if(x == 1) return false;
    if(x == 2) return true;
    for(ll i = 2; i * i <= x; i ++ ) {
        if(x % i == 0) return false;
    }
    return true;
}

void for_prime() {
    for(ll i = 1; i <= 100; i ++ ) {
        if(isPrime(i)) cout << i << " ";
    }
}

void do_while_prime() {
    ll i = 0;
    while( ++ i <= 100) {
        if(isPrime(i)) cout << i << " "; 
        //test
        // if(i == 1) cout << i << " ";
        // if(i == 100) cout << i << " ";
    }
}

void while_prime() {
    ll i = 0;
    do {
        if(isPrime(++ i)) cout << i << " ";
        //test
        // if(i == 1) cout << i << " ";
        // if(i == 100) cout << i << " ";
    }while(i < 100);
}

void Solve() {
    for_prime();
    // do_while_prime();
    // while_prime();
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