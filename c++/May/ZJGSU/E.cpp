#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int MAX = 2010;
int graph[MAX][MAX];
int sx, sy, ex, ey;
char c;
int d;
int sum;

void Solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) {
        for(int j = 1; j <= m ; j ++ ) {
            cin >> c;
            if(c == '.') graph[i][j] = 1; 
            else if(c == 'A') {
                sx = i;
                sy = j;
                graph[i][j] = 1;
            }
            else if(c == 'B') {
                ex = i;
                ey = j;
                graph[i][j] = 1;
            }
        }
    }
    if(sx == 1) d = 1;
    else if(sx == n) d = 3;
    else if(sy == 1) d = 2;
    else d = 4;
    while(sx != ex || sy != ey) {
        if(d == 1) {
            if(graph[sx - 1][sy + 1] == 0) {
                if(graph[sx][sy + 1] == 1) {
                    sy ++;
                    sum ++;
                    d = 2;
                    continue;
                }  
            } 
            if(graph[sx + 1][sy] == 0) {
                if(graph[sx][sy - 1] == 1) {
                    sy --;
                    sum ++;
                    d = 4;
                }
                else {
                    sx --;
                    sum += 2;
                    d = 3;
                }
            }
            else if(graph[sx][sy + 1] == 0) {
                if(graph[sx + 1][sy] == 1) {
                    sx ++;
                    sum ++;
                }
            }
        }

        else if(d == 2) {
            if(graph[sx - 1][sy - 1] == 0) {
                if(graph[sx - 1][sy] == 1) {
                    sx --;
                    sum ++;
                    d = 3;
                    continue;
                }  
            } 
            if(graph[sx][sy + 1] == 0) {
                if(graph[sx + 1][sy] == 1) {
                    sx ++;
                    sum ++;
                    d = 1;
                }
                else {
                    sy --;
                    sum += 2;
                    d = 4;
                }
            }
            else if(graph[sx - 1][sy] == 0) {
                if(graph[sx][sy + 1] == 1) {
                    sy ++;
                    sum ++;
                }
            }
        }

        else if(d == 3) {
            if(graph[sx + 1][sy - 1] == 0) {
                if(graph[sx][sy - 1] == 1) {
                    sy --;
                    sum ++;
                    d = 4;
                    continue;
                }  
            } 
            if(graph[sx - 1][sy] == 0) {
                if(graph[sx][sy + 1] == 1) {
                    sy ++;
                    sum ++;
                    d = 2;
                }
                else {
                    sx ++;
                    sum += 2;
                    d = 1;
                }
            }
            else if(graph[sx][sy - 1] == 0) {
                if(graph[sx - 1][sy] == 1) {
                    sx --;
                    sum ++;
                }
            }
        }

        else if(d == 4) {
            if(graph[sx + 1][sy + 1] == 0) {
                if(graph[sx + 1][sy] == 1) {
                    sx ++;
                    sum ++;
                    d = 1;
                    continue;
                }  
            } 
            if(graph[sx][sy - 1] == 0) {
                if(graph[sx - 1][sy] == 1) {
                    sx --;
                    sum ++;
                    d = 3;
                }
                else {
                    sy ++;
                    sum += 2;
                    d = 2;
                }
            }
            else if(graph[sx + 1][sy] == 0) {
                if(graph[sx][sy - 1] == 1) {
                    sy --;
                    sum ++;
                }
            }
        }
    }
    cout << sum + 1 << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
//  cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}