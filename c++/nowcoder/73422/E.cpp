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


namespace prime_fac {

    const int S = 10; // 随机算法判定次数，8~10 就够了

// 龟速乘
    long long mult_mod(long long a, long long b, long long c) {
        a %= c, b %= c;
        long long ret = 0;
        long long tmp = a;
        while (b) {
            if (b & 1) {
                ret += tmp;
                if (ret > c) ret -= c;
            }
            tmp <<= 1;
            if (tmp > c) tmp -= c;
            b >>= 1;
        }
        return ret;
    }

    // 快速幂
    long long qow_mod(long long a, long long n, long long _mod) {
        long long ret = 1;
        long long temp = a % _mod;
        while (n) {
            if (n & 1) ret = mult_mod(ret, temp, _mod);
            temp = mult_mod(temp, temp, _mod);
            n >>= 1;
        }
        return ret;
    }

    // 是合数返回true，不一定是合数返回false
    bool check(long long a, long long n, long long x, long long t) {
        long long ret = qow_mod(a, x, n);
        long long last = ret;
        for (int i = 1; i <= t; i++) {
            ret = mult_mod(ret, ret, n);
            if (ret == 1 && last != 1 && last != n - 1) return true;
            last = ret;
        }
        if (ret != 1) return true;
        return false;
    }

    // 是素数返回true，不是返回false
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    bool Miller_Rabin(long long n) {
        if (n < 2) return false;
        if (n == 2) return true;
        if ((n & 1) == 0) return false;
        long long x = n - 1;
        long long t = 0;
        while ((x & 1) == 0) { x >>= 1; t++; }

        for (int i = 0; i < S; i++) {
            long long a = rng() % (n - 1) + 1;
            if (check(a, n, x, t))
                return false;
        }

        return true;
    }

    long long factor[100];// 存质因数
    int tol; // 质因数的个数，0~tol-1

    long long gcd(long long a, long long b) {
        long long t;
        while (b) {
            t = a;
            a = b;
            b = t % b;
        }
        if (a >= 0) return a;
        return -a;
    }

    long long pollard_rho(long long x, long long c) {
        long long i = 1, k = 2;
        long long x0 = rng() % (x - 1) + 1;
        long long y = x0;
        while (1) {
            i++;
            x0 = (mult_mod(x0, x0, x) + c) % x;
            long long d = gcd(y - x0, x);
            if (d != 1 && d != x) return d;
            if (y == x0) return x;
            if (i == k) { y = x0; k += k; }
        }
    }
    // 对n质因数分解，存入factor，k一般设置为107左右
    void findfac(long long n, int k) {
        if (n == 1) return;
        if (Miller_Rabin(n)) {
            factor[tol++] = n;
            return;
        }
        long long p = n;
        int c = k;
        while (p >= n) p = pollard_rho(p, c--);
        findfac(p, k);
        findfac(n / p, k);
    }
    vector<int> fac(long long n) {
        tol = 0;
        vector<int>ret;
        findfac(n, 107);
        for (int i = 0; i < tol; i++)ret.push_back(factor[i]);
        return ret;
    }
}

ll quick_pow(ll x, ll p, ll mod) {  // 快速幂
  ll ans = 1;
  while (p) {
    if (p & 1) ans = (__int128)ans * x % mod;
    x = (__int128)x * x % mod;
    p >>= 1;
  }
  return ans;
}

bool isPrime(ll p) {  // 判断素数
  if (p < 2) return 0;
  if (p == 2) return 1;
  if (p == 3) return 1;
  ll d = p - 1, r = 0;
  while (!(d & 1)) ++r, d >>= 1;  // 将d处理为奇数
  for (ll k = 0; k < 10; ++k) {
    ll a = rand() % (p - 2) + 2;
    ll x = quick_pow(a, d, p);
    if (x == 1 || x == p - 1) continue;
    for (int i = 0; i < r - 1; ++i) {
      x = (__int128)x * x % p;
      if (x == p - 1) break;
    }
    if (x != p - 1) return 0;
  }
  return 1;
}


void Solve() {
    ll n; cin >> n;
    unordered_map<ll, ll> mp;
    vector<ll> v;

    //特判
    if(isPrime(n)) {
        cout << "1" << "\n" << n << "\n"; return ;
    }
    ll sum = 0, cnt = 0, max = 0, maxx = 0;
    if(n == 1) {
        cout << "-1" << "\n"; return ;
    }

    vector<int>fac = prime_fac::fac(n);
    for(auto i : fac) {
        mp[i] ++ ; if(mp[i] == 1) v.push_back(i);
    }
    for(auto i : v) {
        sum += mp[i];
        if(mp[i] > max) {
            max = mp[i];
            maxx = i;
        }
    }

    //不可能的情况
    if(2 * max - 1 > sum) {
        cout << "-1" << "\n"; return ;
    } 
    ll c[max + 1][sum + 1];
    ll d[max + 1]; for(ll i = 1; i <= max; i ++ ) d[i] = 1;
    for(ll i = 1; i <= max + 1; i ++ ) c[i][1] = maxx;
    ll res = 1;
    for(ll i = 0; i < v.size(); i ++ ) {
        if(v[i] != maxx) {
            for(ll j = 1; j <= mp[v[i]]; j ++ ) {
                ll e = (res ++ ) % max;
                if(e == 0) e = max;
                c[e][++ d[e]] = v[i]; 
            }
        }
    }
    cout << sum << "\n";
    for(ll i = 1; i <= max; i ++ ) {
        for(ll j = 1; j <= d[i]; j ++ ) {
            cout << c[i][j] << " ";
        }
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