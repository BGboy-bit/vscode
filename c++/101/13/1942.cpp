#include<bits/stdc++.h>
using namespace std;

string Date[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
int f[7];
char g;//�����ַ�

int main() {
    char c;
    scanf("%c", &c);
    int cnt = 0;//��¼�����ڼ����ַ�
    int sum = 0;//��¼���ַ����ֵ����ڵĸ���
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