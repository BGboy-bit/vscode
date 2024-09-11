//��С������mst
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 5010;
const int inf = 0x3f3f3f3f;
int graph[MAX][MAX];
int lowcost[MAX], closest[MAX];
int sum;
int n, m;
bool AC = 1;

void Prim(int st) {
    for(ll i = 1; i <= n; i ++) {
        if(i == st) lowcost[i] = 0;
        else lowcost[i] = graph[st][i];
        closest[i] = st;        
    }
    ll Min, pos;
    sum = 0;
    for(ll i = 1; i < n; i ++) {
        Min = inf;
        for(int j  = 1; j <= n; j ++) {
            if(lowcost[j] != 0 && lowcost[j] < Min) {
                Min = lowcost[j];
                pos = j;
            }
        }
        if(Min == inf) {
            AC = 0;
            break;
        }
        sum += Min;
        lowcost[pos] = 0;
        for(ll j = 1; j <= n; j ++) {
            if(lowcost[j] != 0 && graph[pos][j] < lowcost[j]) {
                lowcost[j] = graph[pos][j];
                closest[j] = pos;
            }
        }
    }
    if(AC) cout << sum << "\n";
    else cout << "orz" << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(graph,inf,sizeof(graph));
    ll x, y, z;
    cin >> n >> m;
    for(ll i = 1; i <= m; i ++) {
        cin >> x >> y >> z;
        if(graph[x][y] > z) graph[x][y] = graph[y][x] = z;
    }
    Prim(1);
    return 0;
}