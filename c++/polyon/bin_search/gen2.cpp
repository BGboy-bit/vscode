#include "testlib.h"
#include <iostream>
#include <vector>

using namespace std;

int maxn = 1e5, maxm = 1e5, maxq = 1e5;

// Function to generate a test case
void generate_testcase() {
    int n = maxn;
    int m = maxm;
    cout << n << " " << m << endl;

    for (int i = 0; i < m; ++i) {
        int l = rnd.next(1, n);
        int r = rnd.next(l, n); // ensure l <= r
        cout << l << " " << r << endl;
    }
    int q = maxq;
    cout << q << endl;

    for (int i = 0; i < q; ++i) {
        int u = rnd.next(1, n);
        int v = rnd.next(u, n); // ensure u <= v
        cout << u << " " << v << endl;
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int T = 1;  cout << T << endl;
    generate_testcase();
    return 0;
}
