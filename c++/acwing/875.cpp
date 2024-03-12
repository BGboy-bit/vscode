#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    int N;
    cin >> N;
    while(N -- ) {
        ll a, b, p;
        cin >> a >> b >> p;
        ll res = 1;
        while(b) {  
            if(b & 1) {
                res = res * a % p;
                b --;
            }
            b >>= 1;
            a = a * a % p; 
        }
        cout << res << "\n";
    }
    return 0;
}