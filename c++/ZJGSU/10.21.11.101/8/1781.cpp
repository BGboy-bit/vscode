#include<bits/stdc++.h>
using namespace std;

char str[21];
int m,c,l;
char n;   

void dec(int i) {
	int cnt = 0;
	for(int k = i; k < l; k ++) {
		if(str[k] != str[i]) break;
		else cnt ++;
	}
	for(int j = i; j < l - cnt; j ++) {
        str[j] = str[j + cnt];
    }
    l -= cnt;
    str[l] = '\0';
    for(int j = 0; j < l - 2; j ++) {
    	if(str[j + 2] == str[j] && str[j + 1] == str[j]) dec(j);
	}
}

void Solve() {
    scanf("%s",str);
    l = strlen(str);
    while(l) {
        scanf("%d %d",&c,&m);
      	n = c + '0';
        m = m --;
        for(int j = l - 1; j >= m; j--) {
            str[j + 1] = str[j];
        }
        str[m] = n;
        l ++;
        str[l] = '\0';
        for(int i = 0; i < l - 2; i ++) { 
                if(str[i + 2] == str[i] && str[i + 1] == str[i]) {
                  dec(i);
                  break;
            	}
        }
        if(l) printf("%s\n\n",str);   
    }
    printf("You win!\n\n");
}


int main() {
    Solve();
    return 0;
}



#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
 char data[10000];
 int size;
}NODE,*List;
List s;
void InitList(List *s)
{
 List p=(List)malloc(sizeof(NODE));
 if(!p) exit(0);
 p->size=0;
 *s=p;
}
void CreateList(List s)
{
 char t[10000];
 gets(t);
 strcpy(s->data,t);
 s->size=strlen(t);
}
void InsertList(List s,int pos,char element)
{
 for(int i=s->size;i>=pos;i--)
 {
  s->data[i]=s->data[i-1];
 }
 s->data[pos-1]=element;
 s->size++;
}
void PrintList(List s)
{
 if(s->size==0)
 {
  printf("You win!");
  exit(0);
 }
 for(int i=0;i<s->size;i++)
 {
  printf("%c",s->data[i]);
 }
 printf("\n\n");
}
void DeleteList(List s,int pos,int num)
{
 for(int i=pos;i<s->size-num+pos;i++)
 {
  s->data[i]=s->data[i+num];
 }
 s->size-=num;
}
int EraseList(List s)
{
 for(int i=0;i<s->size-2;i++)
 {
  if(s->data[i]==s->data[i+1]&&s->data[i]==s->data[i+2])
  {
   int cnt=3,j=i+3;
   while(1)
   {
    if(j>=s->size) break;
    if(s->data[j]==s->data[i])
    {
     cnt++;
     j++;
    }
    else break;
   }
   DeleteList(s,i,cnt);
   PrintList(s);
   EraseList(s);
   return 1;
  }
 }
 return 0;
}
int main()
{
 InitList(&s);
 CreateList(s);
 int x,y;
 while(scanf("%d %d",&x,&y))
 {
  InsertList(s,y,x+'0');
  if(EraseList(s)==0)
  {
   PrintList(s);
  }
 }
 return 0;
}