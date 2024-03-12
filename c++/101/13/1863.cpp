#include<bits/stdc++.h>
using namespace std;

int n;
int cnt;
int a[1000][1000];
vector<int> v1, v2;
bool f[1000];

void dfs(int st, int sum) {
    if(sum >= n) {
        if(sum == n) v1.insert(v1.end(), v2.begin(), v2.end());
        return;
    }
    for(int i = st; i >= 1; i -- ) {
        if(f[i]) continue;
        v2.push_back(i);
        f[i] = 1;
        dfs(i, sum + i);
        v2.pop_back();
        f[i] = 0;
    }
}

int main() {
    cin >> n;
    dfs(n, 0);
    int sum = 0;
    for(int i = 0; i < v1.size(); i ++ ) {
        sum += v1[i];
        cout << v1[i];
        if(sum == n) {
            cout << "\n" << "\n";
            sum = 0;
        }
        else cout << " ";
    }
    return 0;
}