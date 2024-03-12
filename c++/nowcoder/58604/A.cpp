#include<bits/stdc++.h>
using namespace std;
typedef int ll;

ll n;
char c;
ll cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> c >> n;
    if(c == '*' || c == '=' || c == ',') cnt = n * (n + 1) / 2;
    else {
        for(ll i = 1; i <= n; i ++ ) {
            for(ll j = 1; j <= i; j ++ ) {
                char str[10];
                sprintf(str, "%d", i * j); 
                for(ll k = 0; k < strlen(str); k ++ ) {
                    if(str[k] == c) cnt ++ ;
                }
                sprintf(str, "%d", i); 
                for(ll k = 0; k < strlen(str); k ++ ) {
                    if(str[k] == c) cnt ++ ;
                }
                sprintf(str, "%d", j); 
                for(ll k = 0; k < strlen(str); k ++ ) {
                    if(str[k] == c) cnt ++ ;
                }
            }
        }
    } 
    
    cout << cnt << "\n";
    return 0;
}