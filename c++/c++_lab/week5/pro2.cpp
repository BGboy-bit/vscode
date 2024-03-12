	#include<bits/stdc++.h>
	using namespace std;
	typedef __int128 i128;
	typedef long long ll;
	typedef double db;
	
	const db PI = acos(-1);
	const ll inf = 2e18 + 10;
	const int mod = 998244353;
	const int MAX = 2e5 + 10;
	bool multi = 0;//多组输入
	
	class book {
	private :
	    ll num, price;
	public :
	    book(ll n, ll p) : num(n), price(p) {}
	    ll get_num() {return num;}
	    ll get_price() {return price;}
	};
	
	void Solve() {
	    book b[5] = {book(1, 1), book(2, 2), book(3, 3), book(4, 4), book(5, 5)};
	    book *bk = b;
	    ll k = 4;
	    for(bk += k;k >= 0; bk --, k -- ) {
	        cout << "第" << k + 1 << "本书的num * price = " << bk->get_num() * bk->get_price() << "\n";
	    }
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