#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int x[12],sg[1050];
bool vis[1050];
void init(){
	for(int i=0;i<11;i++){
		x[i]=1<<i;
	}
	sg[0]=0;
	for(int i=1;i<1002;i++){
		memset(vis,0,sizeof(vis));
		for(int j=0;x[j]<=i;j++){
			vis[sg[i-x[j]]]=true;
		}
		for(int j=0;;j++){
			if(!vis[j]){
				sg[i]=j;
				break;
			}
		}
	}
	return ;
}
int main(){
	int n;
	init();
    for(int i = 0; i <= 100; i ++ ) {
        cout << i << " " << sg[i] << "\n";
    }
	// while(~scanf("%d",&n)){
	// 	if(sg[n])printf("Kiki\n");
	// 	else printf("Cici\n");
	// }
	return 0;
} 