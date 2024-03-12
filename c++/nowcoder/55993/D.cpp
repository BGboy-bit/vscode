#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s1,s2;
    cin >> s1 >> s2;
    ll sum1,sum2;
    sum1 = ((s1[0] - '0') * 10 + s1[1] - '0') * 3600 + ((s1[3] - '0') * 10 + s1[4] - '0') * 60 + (s1[6] - '0') * 10 + s1[7] - '0';
    sum2 = ((s2[0] - '0') * 10 + s2[1] - '0') * 3600 + ((s2[3] - '0') * 10 + s2[4] - '0') * 60 + (s2[6] - '0') * 10 + s2[7] - '0';
    cout << abs(sum2 - sum1) << "\n";
    return 0;
}