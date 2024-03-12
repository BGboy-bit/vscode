#include<bits/stdc++.h>
using namespace std;

string s;
int a;
vector<int> v1, v2;

void mul() {
    int t = 0; 
    for(int i = 0; i < v1.size() || t; i ++ ) {
        if(i < v1.size()) t += v1[i] * a;
        v2.push_back(t % 10);
        t /= 10; 
    }
    while(v2.size() > 1 && v2.back() == 0) v2.pop_back();
}

int main() {
    cin >> s >> a;
    for(int i = s.size() - 1; i >= 0; i -- ) v1.push_back(s[i] - '0');
    mul();
    for(int i = v2.size() - 1; i >= 0; i -- ) cout << v2[i];
    return 0;
} 