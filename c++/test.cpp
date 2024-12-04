#include<cstdio>
#include<iostream>
#include<vector>
#include<cctype>
#define RI register int
#define CI const int&
#define Tp template <typename T>
using namespace std;
typedef long long LL;
const int N=200005;
int t,n,k,len[10]; char s[N];
class FileInputOutput
{
    private:
        static const int S=1<<21;
        #define tc() (A==B&&(B=(A=Fin)+fread(Fin,1,S,stdin),A==B)?EOF:*A++)
        #define pc(ch) (Ftop!=Fend?*Ftop++=ch:(fwrite(Fout,1,S,stdout),*(Ftop=Fout)++=ch))
        char Fin[S],Fout[S],*A,*B,*Ftop,*Fend; int pt[30];
    public:
        inline FileInputOutput(void) { Ftop=Fout; Fend=Fout+S; }
        Tp inline void read(T& x)
        {
            x=0; char ch; while (!isdigit(ch=tc()));
            while (x=(x<<3)+(x<<1)+(ch&15),isdigit(ch=tc()));
        }
        Tp inline void write(T x,const char ch='\n')
        {
            RI ptop=0; while (pt[++ptop]=x%10,x/=10);
            while (ptop) pc(pt[ptop--]+48); pc(ch);
        }
        inline void read_char(char& ch)
        {
        	while (!isdigit(ch=tc()));
        }
        inline void put_char(const char& ch)
        {
        	pc(ch);
        }
        inline void flush(void)
        {
            fwrite(Fout,1,Ftop-Fout,stdout);
        }
        #undef tc
        #undef pc
}F;
struct BigInt
{
	const static LL S=1e18;
	vector <LL> num;
	BigInt(CI l=-1,CI r=-1,CI res=0)
	{
		num.reserve(res);
		num.clear(); if (l!=-1)
		{
			for (RI i=r,j;i>=l;i-=18)
			{
				LL x=0; for (j=max(i-17,l);j<=i;++j) x=x*10LL+s[j]-'0';
				num.push_back(x);
			}
		}
	}
	inline int size(void) const { return num.size(); }
	inline LL& operator [](CI x) { return num[x]; }
	inline const LL& operator [](CI x) const { return num[x]; }
	friend inline BigInt operator + (const BigInt& A,const BigInt& B)
	{
		BigInt C; RI i; LL carry=0;
		if (A.size()<=B.size())
		{
			for (i=0;i<A.size();++i)
			{
				LL val=A[i]+B[i]+carry;
				C.num.push_back(val%S); carry=val/S;
			}
			for (i=A.size();i<B.size();++i)
			{
				LL val=B[i]+carry;
				C.num.push_back(val%S); carry=val/S;
			}
			if (carry) C.num.push_back(carry);
		} else
		{
			for (i=0;i<B.size();++i)
			{
				LL val=A[i]+B[i]+carry;
				C.num.push_back(val%S); carry=val/S;
			}
			for (i=B.size();i<A.size();++i)
			{
				LL val=A[i]+carry;
				C.num.push_back(val%S); carry=val/S;
			}
			if (carry) C.num.push_back(carry);
		}
		return C;
	}
	friend inline bool operator < (const BigInt& A,const BigInt& B)
	{
		if (A.size()<B.size()) return 1;
		if (A.size()>B.size()) return 0;
		for (RI i=A.size()-1;i>=0;--i)
		{
			if (A[i]<B[i]) return 1;
			if (A[i]>B[i]) return 0;
		}
		return 0;
	}
	inline void print(void)
	{
		RI i,j; vector <LL> vec; LL x=num.back();
		while (x) vec.push_back(x%10),x/=10;
		for (j=vec.size()-1;j>=0;--j) F.put_char(vec[j]+'0');
		for (i=(int)num.size()-2;i>=0;--i)
		{
			LL x=num[i]; vec.clear();
			for (j=0;j<18;++j) vec.push_back(x%10),x/=10;
			for (j=vec.size()-1;j>=0;--j) F.put_char(vec[j]+'0');
		}
	}
}ans; LL rans;
inline void check(void)
{
	if (n>18)
	{
		int lst=1; BigInt ret;
		for (RI i=1;i<=k+1;++i)
		ret=ret+BigInt(lst,lst+len[i]-1,n/k+5),lst+=len[i];
		if (ret<ans) ans=ret;
	} else
	{
		int lst=1; LL ret=0;
		auto getint=[&](CI l,CI r)
		{
			LL ret=0; for (RI i=l;i<=r;++i) ret=ret*10LL+s[i]-'0'; return ret;
		};
		for (RI i=1;i<=k+1;++i)
		ret=ret+getint(lst,lst+len[i]-1),lst+=len[i];
		if (ret<rans) rans=ret;
	}
}
inline void DFS(CI now,CI lst,CI sum,CI mn,CI mx)
{
	if (sum>n) return;
	if (mx-mn>=3) return;
	if (now>k+1)
	{
		if (sum==n) check(); return;
	}
	for (RI i=-1;i<=1;++i) if (1<=lst+i&&lst+i<=n)
	len[now]=lst+i,DFS(now+1,len[now],sum+len[now],min(mn,len[now]),max(mx,len[now]));
}
int main()
{
	for (F.read(t);t;--t)
	{
		F.read(n); F.read(k); ans.num.resize(n+1); rans=1e18;
		RI i; for (i=1;i<=n;++i) F.read_char(s[i]);
		int L=(2*n-k*(k+1)+2*k+1)/(2*k+2),R=(2*n+k*(k+1))/(2*k+2);
		for (i=max(1,L);i<=min(n,R);++i) len[1]=i,DFS(2,i,i,i,i);
		if (n>18) ans.print(),F.put_char('\n'); else F.write(rans);
	}
	return F.flush(),0;
}
