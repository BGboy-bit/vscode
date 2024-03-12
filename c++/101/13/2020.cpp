#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int MAX = 1e4 + 10;
struct Edge{
    db x, y;
}edges[MAX];

bool AC;
db r = 0;

void Prime(db x, db y, db z) {
    if(x >= y + z) AC = 0;
    else AC = 1;
}

void prime() {
    if((edges[0].x - edges[1].x) * (edges[1].y - edges[2].y) == (edges[0].y - edges[1].y) * (edges[1].x - edges[2].y)) AC = 0;
}

db S(db x, db y, db z) {
    db L = (x + y + z) / 2;
    return sqrt(L * (L - x) * (L - y) * (L - z));
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++ ) {
        // cin >> edges[i].x >> edges[i].y;
        scanf("%lf,%lf", &edges[i].x, &edges[i].y);
    }
    for(int i = 0; i < n - 2; i ++ ) {
        for(int j = i + 1;j < n - 1; j ++ ) {
            for(int k = j + 1; k < n; k ++ ) {
                db x = (edges[i].x - edges[j].x) * (edges[i].x - edges[j].x) + (edges[i].y - edges[j].y) * (edges[i].y - edges[j].y);
                db y = (edges[i].x - edges[k].x) * (edges[i].x - edges[k].x) + (edges[i].y - edges[k].y) * (edges[i].y - edges[k].y);
                db z = (edges[j].x - edges[k].x) * (edges[j].x - edges[k].x) + (edges[j].y - edges[k].y) * (edges[j].y - edges[k].y);
                if(x >= y && x >= z) {
                    Prime(x, y, z);
                    prime();
                    if(!AC) r = max(sqrt(x) / 2, r);
                }
                else if(y >= x && y >= z) {
                    Prime(y, x, z);
                    prime();
                    if(!AC) r = max(sqrt(y) / 2, r);
                } 
                else if(z >= x && z >= y) {
                    Prime(z, x, y);
                    prime();
                    if(!AC) r = max(sqrt(z) / 2, r);
                }
                if(AC) {
                    x = sqrt(x);
                    y = sqrt(y);
                    z = sqrt(z);
                    r = max(x * y * z / (4 * S(x, y, z)), r);
                }
            }
        }
    }
    printf("以上4个点的覆盖圆的最小半径为%.4lf\n", r);
    return 0;
}