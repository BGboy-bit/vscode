#include<stdio.h>
#include<math.h>
#include<string.h> 
int main()
{
	char m[100],n[100]; 
	int lm,ln,i,j,ls,t;
	int s[120];
	while(scanf("%s%s",&m,&n)!=EOF)
	{
		memset(s,0,sizeof(s));
		lm=strlen(m);
		ln=strlen(n);
		ls=0;
		t=0;
		for(i=lm-1;i>=0;i--)
		{
			ls=t;
			for(j=ln-1;j>=0;j--)
			{
				s[ls]+=(m[i]-'0')*(n[j]-'0');
				ls++;
			}
			t++;
		}
		for(i=0;i<ls-1;i++)
		{
			s[i+1]=s[i+1]+s[i]/10;
			s[i]%=10;
		}
		for(i=ls-1;i>=0;i--)
		  printf("%d",s[i]);    
		if((m[lm-1]-'0')%2&&(n[ln-1]-'0')%2)
		  printf(".41\n");
		else
		  printf(".00\n");
	}
	
	return 0;
 } 