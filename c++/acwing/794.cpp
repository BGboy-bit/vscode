#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string a;
ll b;
vector<ll> A, C;
ll r;//ÓàÊý

void div() {
    for(ll i = A.size() - 1; i >= 0; i -- ) {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    //Ç°µ¼Áã
    while(C.size() > 1 && C.back() == 0) C.pop_back();
}

int main() {
    cin >> a >> b;
    for(ll i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
    div();
    for(ll i = C.size() - 1; i >= 0; i --) cout << C[i];
    cout << "\n" << r << "\n";
    return 0;
}