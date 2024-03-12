	#include<bits/stdc++.h>
	using namespace std;
	typedef long long ll;
	
	const int MAX = 50;
	ll a[MAX];
	ll n, m; 
	
	ll v[MAX];
	ll cnt;
	bool ac = false;
	
	void dfs(ll resv, ll resa, ll resn, ll resm) {
		if(ac == true) return ;
		if(resv == 0) {
			if(resm == 0) {
				ac = true;
				for(ll i = cnt; i >= 0; i -- ) {
					
					if(v[i] == 0) continue;
					
					if(v[i] == 1) {
						if(i == 1) cout << "x";
						else if(i == 0) cout << "1";
						else cout << "x^" << i;
					} 
					
					else if(v[i] > 1) {
						if(i == 1) cout << v[i] << "x";
						else if(i == 0) cout << v[i];
						else cout << v[i] << "x^" << i;
					}
					
					bool ff = false;
					for(ll j = i - 1; j >= 0; j -- ) {
						if(v[j] != 0) {
							cout << "+"; ff = true; break;
						}
					}
					if(!ff) return ;
				}
			}  
			return ;
		}
		
		if(resv == 1) {
			v[0] = resn;
			dfs(0, resn, 0, resm - resn); 
			v[0] = 0; 
			return ;
			 
		}
		for(ll i = resn; i >= 0; i -- ) {
			ll sum = i * a[resv - 1];
			if(resm >= sum) {
				v[resv - 1] = i; 
				dfs(resv - 1, i, resn - i, resm - sum);
				v[resv - 1] = 0; 
			}
		}
	}
	
	int main() {
		cin >> n >> m;
		
		a[0] = 1;
		for(ll k = n + 1; k <= m; k *= n + 1) {
			if(k <= m) a[ ++ cnt] = k;
		}
		for(ll i = n; i >= 0; i -- ) {
			if(ac == true) return 0;
			ll sum = i * a[cnt];
			
			if(m >= sum) {
				v[cnt] = i; 
				dfs(cnt, i, n - i, m - sum);
				v[cnt] = 0;
			}
		} 
		
		
		return 0; 
	}
	

