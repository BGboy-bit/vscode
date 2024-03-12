#include<bits/stdc++.h>
using namespace std;


vector<int> v1, v2;
int main() {
    int a;
    while(scanf("%d", &a) == 1) {
        if(a % 2 != 0) v1.push_back(a);
        else v2.push_back(a);
        char c = getchar();
        if(c == '\n') break;   
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for(int i = v1.size() - 1; i >= 0; i -- ) {
        printf("%d", v1[i]);
        if(v2.size() != 0) printf(" ");
    }
    for(int i = 0; i < v2.size(); i ++ ) {
        printf("%d", v2[i]);
        if(i != v2.size() - 1) printf(" ");
    }
}