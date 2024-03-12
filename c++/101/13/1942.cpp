#include<bits/stdc++.h>
using namespace std;

string Date[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
int f[7];
char g;//错误字符

int main() {
    char c;
    scanf("%c", &c);
    int cnt = 0;//记录读到第几个字符
    int sum = 0;//记录有字符出现的星期的个数
    while(c != 'Y') {
        for(int i = 0; i < 7; i ++ ) {
            if(Date[i][cnt] == c && f[i] == cnt) {
                sum ++;
                f[i] ++;
            }
        }
        cnt ++;
        if(sum == 1 || sum == 0) {
            if(sum == 0 && g != c || sum == 0 && cnt > 1) {
                cout << "Wrong data" << "\n";
                g = c;
            }
            else if(sum == 0 && g == c) {
                g = '\0';
                scanf("%c", &c);
            }
            else {
                for(int i = 0; i < 7; i ++ ) {
                    if(f[i] == cnt) cout << Date[i] << "\n"; 
                }
                scanf("%c", &c);
            }
            sum = 0;
            cnt = 0;
            memset(f, 0, sizeof(f));
        }
        else {
            scanf("%c", &c);
            sum = 0;
        } 
    }
    return 0;
}