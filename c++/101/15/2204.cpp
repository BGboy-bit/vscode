#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double db;

ll n, m;

struct Stu{
    string name;
    ll grade;
};

bool cmp(Stu x, Stu y) {
    if(x.grade < y.grade) return false;
    else if(x.grade > y.grade) return true;
    else return x.name < y.name;
}

void Print(vector<Stu> &stu) {
    for(ll i = 0; i < n; i ++ ) {
        cout << stu[i].name <<"\n";
    }
    // cout << "\n";
}

void Solve() {
    ll cnt = 0;
    cin >> n >> m;
    vector<ll> add(m);
    vector<Stu> stu(n);
    for(ll i = 0; i < m; i ++ ) {
        cin >> add[i];
        cnt += add[i];
    }
    for(ll i = 0; i < n; i ++ ) {
        cin >> stu[i].name;
        stu[i].grade = 0;
        for(ll j = 0; j < m; j ++ ) {
            ll x;
            cin >> x;
            stu[i].grade += x * add[j];
        }
    }
    sort(stu.begin(), stu.end(), cmp);
    Print(stu);
}


int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}