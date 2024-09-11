/*
´úÂë²¿¶Ó
http://10.21.15.91/contest/1018/problem/J
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int MAX = 1e5 + 10;
db p[MAX], r[MAX];
ll n, m;
db sumr, sump;

ll fa[MAX];
ll num[MAX];
void init() {
	for(ll i = 1; i <= n; i ++ ) {
		fa[i] = i;
		num[i] = 1;
	} 
}


ll find(ll x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]); 
}

void merge(ll fx, ll fy) {
	sump -= p[fx] * num[fx] + p[fy] * num[fy];
	p[fx] = max(p[fx], p[fy]);
	p[fy] = max(p[fx], p[fy]);
	sump += p[fx] * num[fx] + p[fy] * num[fy];
	fa[fx] = fy;
	num[fy] += num[fx];
}

int main() {
	scanf("%lld %lld",&n , &m);
	for(ll i = 1; i <= n; i ++ ) {
		scanf("%lf", &p[i]);
		sump += p[i];
		r[i] = p[i];
	}
	sumr = sump;
	init();
	
	
	while(m -- ) {
		ll x, y;
		scanf("%lld %lld", &x, &y);
		
		ll fx = find(x), fy = find(y);
		if(fx != fy) merge(fx, fy);
		//²»ÐèÒªÎ¬»¤¡°sumr¡±µÄ°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡
		// db sum1 = 0, sum2 = 0;
		// for(ll i = 1; i <= n; i ++ ) {
		// 	sum1 += r[i];
		// 	r[i] = p[find(i)] / sump * sumr; 
		// 	sum2 += r[i];
 		// }
 		// sumr = sumr + sum2 - sum1;
		r[1] = p[find(1)] / sump * sumr; 
		printf("%.2lf\n", r[1]);
	}
	return 0;
}



