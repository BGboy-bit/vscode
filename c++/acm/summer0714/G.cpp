#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int inf = 0x3f3f3f3f;
const int MAX = 1e5 + 10;
string str;
ll ans;
vector<ll> v;
stack<ll> L_num;
stack<ll> v_num;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> str;
    ll l = str.length();
    for(ll i = 0; i < l; i ++ ) {
        if(str[i] == '\\') {
            L_num.push(i);
        }
        else if(str[i] == '/') {
            if(!L_num.empty()) {
                ll l = L_num.top();
                L_num.pop();
                ll summ = i - l;
                if(!v.empty()) {
                    ll rec = v_num.top();
                    while(l < rec) {
                        summ += v.back();
                        v.pop_back();
                        v_num.pop();
                        if(v_num.empty()) break;
                        rec = v_num.top();
                    }
                }
                v.push_back(summ);
                v_num.push(l);
            }
        }
    }  
    for(auto i : v) ans += i; 
    cout << ans << "\n" << v.size() << " ";
    for(auto i : v) cout << i << " ";
    cout << "\n";  
    return 0;
}