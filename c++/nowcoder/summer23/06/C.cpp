// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// typedef double db;

// const ll inf = 2e18 + 10;
// const int mod = 998244353;
// const int MAX = 2e5 + 10;



// ll ce(ll x){
//     if(x%2==1){
//         ll sum=0;
//             for(int j=1;j<=x;j+=2){
//                 ll k = j;
//                 while(k%5==0){
//                     sum++ ; k /= 5;
//                 }
                
//             }
//         return sum;
//     }
//     else {
//         ll sum=0;
//             for(int j=2;j<=x;j+=2){
//                 ll k = j;
//                 while(k%5==0){
//                     sum++ ; k /= 5;
//                 }
//             }
//         return sum;
//     }
// }


// void Solve() {
//     ll n, ans = 0;
//     // cin >> n;
//     ll cntt = 0;
//     for(ll n = 1; n <= 1000; n ++ ) {
//         ans = 0;
//         for(ll k = 1, po = 5; po <= n; k ++, po = po * 5) {
//         ll si = (n - po) / (po * 2) + 1;
//         //ans += si * ((n - po + 2) / 2) - (si - 1) * si * po / 2;

//             if(si % 2 == 1) {
//                 ans += si * ((n - po + 2) / 2 - (si - 1) * po / 2);
//                 //ans += si * ((n - po + 2) / 2) - (si - 1) * si * po / 2;

//             }
//             else {
//                 if((n - po + 2) % 2 == 1) ans += si / 2 * (n - po + 1 - (si - 1) * po);
//                 else ans += si / 2 * (n - po + 2 - (si - 1) * po);
//                 //ans += si * ((n - po + 2) / 2) - (si - 1) * si * po / 2;

//             }

//         if(2 * po <= n) {
//             si = (n - po * 2) / (po * 2) + 1; 
//             //ans += si * ((n - po * 2 + 2) / 2) - (si - 1) * si * po / 2;

//             if(si % 2 == 1) {
//                 ans += si * ((n - po * 2 + 2) / 2 - (si - 1) * po / 2);
//                 //ans += si * ((n - po * 2 + 2) / 2) - (si - 1) * si * po / 2;

//             }
//             else {
//                 if((n - po * 2 + 2) % 2 == 1) ans += si / 2 * ((n - po * 2 + 1) - (si - 1) * po);
//                 else ans += si / 2 * ((n - po * 2 + 2) - (si - 1) * po);
//                 //ans += si * ((n - po * 2 + 2) / 2) - (si - 1) * si * po / 2;

//             }
//         }
//     }


//         int sum=0;
//         for(int i=1;i<=n;i++){
//             sum+=ce(i);
//         }

//         if(sum != ans) {
//             cntt ++ ;
//             cout << n << " \n";
//             cout << ans << " " << sum << "\n";
//         }
//     }
//     // cout << ans << "\n";
//     // cout << sum << "\n";
//     cout << cntt << "\n";
// }


// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     ll T = 1;
//     // cin >> T;
//     while(T --) {
//         Solve();
//     }
//     return 0;
// }
#include<iostream>
using namespace std;
__int128 C[100][100];
__int128 quick(__int128 a,__int128 b) {
	__int128 res=1,k=a;
	while(b) {
		if(b&1)res*=k;
		k=k*k,b>>=1;
	}
	return res;
}
inline __int128 read(){
    __int128 x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
inline void print(__int128 x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

__int128 make_odd(__int128 n) {
	if(n%2==0)n=n-1;
	__int128 len=(n+1)/2,num,t=1;
	__int128 ans=0;
	__int128 max_id=0,q;
	__int128 rongchi[100];
	for(int i=1; i<=64; i++)
		rongchi[i]=0;
	for(__int128 k=5; k<=n; k*=5,t++) {
		num=n/k;
		num=(num+1)/2;//5(len-3+1) 15(len-8+1) ;25(len-13+1) 75(len-28+1) ,q=t^k
		q=quick(t,k);
		max_id=((k+(num-1)*k*2)+1)/2;
		rongchi[t]=((len-max_id+1)+len-(k+1)/2+1)*num/2;
		//if(q==1)rongchi[t]=num;//sum=a1(q^n-1)/q-1,a1=t^(len-max_id+1),n=num
		//	else rongchi[t]=(quick(q,num)-1)/(q-1)*quick(t,len-max_id+1);
	}
	__int128 xi_rongchi=1;
	ans=0;
	__int128 this_ans;
	for(int i=1; i<t; i++) {
		this_ans=rongchi[i];
		for(int pt=2; i+pt-1<t; pt++) {
			if(pt&1)xi_rongchi=1;
			else xi_rongchi=-1;
			for(int j=i+pt-1; j<t; j++) {
			//	cout<<"haha"<<endl;
			//	cout<<"this,this_ans="<<this_ans<<endl;
				this_ans+=xi_rongchi*C[j-i-1][pt-2]*rongchi[j];
			//	cout<<"now,this_ans="<<this_ans<<endl;
			}
		}
	//	cout<<"this_ans="<<this_ans<<endl;
		ans+=this_ans*i;
	}
	return ans;
}
__int128 make_even(__int128 n) {

	if(n%2==1)n=n-1;
	__int128 len=(n)/2,num,t=1;
	__int128 ans=0;
	__int128 max_id=0,q;
	__int128 rongchi[100];
	for(int i=1; i<=64; i++)
		rongchi[i]=0;
	for(__int128 k=5; k<=n; k*=5,t++) {
		num=n/k;
		num=(num)/2;//10(len-5+1) 20(len-10+1) ;50(len-25+1) 100(len-50+1) ,q=t^k
		q=quick(t,k);
		max_id=k*num;
		rongchi[t]=((len-max_id+1)+len-(k)+1)*num/2;
		//if(q==1)rongchi[t]=num;//sum=a1(q^n-1)/q-1,a1=t^(len-max_id+1),n=num
		//	else rongchi[t]=(quick(q,num)-1)/(q-1)*quick(t,len-max_id+1);
	}
	__int128 xi_rongchi=1;
	ans=0;
	__int128 this_ans;
	for(int i=1; i<t; i++) {
		this_ans=rongchi[i];
		for(int pt=2; i+pt-1<t; pt++) {
			if(pt&1)xi_rongchi=1;
			else xi_rongchi=-1;
			for(int j=i+pt-1; j<t; j++) {
				this_ans+=xi_rongchi*C[j-i-1][pt-2]*rongchi[j];
			}
		}
	//	cout<<"this_ans="<<this_ans<<endl;
		ans+=this_ans*i;
	}
	return ans;
}
int main() {
	for(int i=0; i<=64; i++) {
		C[i][0]=C[i][i]=1;
		for(int j=1; j<i; j++)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	__int128 n;
	n=read();
	__int128 ans1=make_odd(n),ans2=make_even(n);
	print(ans1+ans2);
	return 0;
}
