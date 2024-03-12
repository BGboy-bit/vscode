#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

string s1,s2;
ll l1,l2;
vector<ll> v1,v2;

bool cmp(vector<ll> &A, vector<ll> &B) {
    if(A.size() != B.size()) return A.size() > B.size();
    for(ll i = A.size() - 1; i >= 0; i --) {
        if(A[i] != B[i]) return A[i] > B[i];
    } 
    return 1;
}

vector<ll> sub(vector<ll> &v1, vector<ll> &v2)
{
    vector<ll> v3;
    ll t = 0;
    for(ll i = 0; i < v1.size(); i ++) {
        t = v1[i] - t;
        if(i < v2.size()) t -= v2[i];
        v3.push_back((t + 10) % 10);
        if(t < 0) t = 1;
        else t = 0;
    }
    //È¥µôÇ°µ¼Áã
    while(v3.size() > 1 && v3.back() == 0) v3.pop_back();
    return v3;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll t = 1;
//	cin >> t;
	while(t--)
	{
		cin >> s1 >> s2;
        l1 = s1.length(),l2 = s2.length();
        for(ll i = l1 - 1;i >= 0;i--) v1.push_back(s1[i] - '0');
        for(ll i = l2 - 1;i >= 0;i--) v2.push_back(s2[i] - '0');
        if(cmp(v1, v2)) {
            auto v3 = sub(v1, v2);
            for(ll i = v3.size() - 1; i >= 0; i --) cout << v3[i];
        }
        else {
            auto v3 = sub(v2, v1);
            cout << "-";
            for(ll i = v3.size() - 1; i >= 0; i --) cout << v3[i];
        }              
	}
	return 0;
}