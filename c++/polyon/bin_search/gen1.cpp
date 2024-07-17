#include "testlib.h"
#include <iostream>
#include <vector>

using namespace std;

int maxn = 1e5, maxm = 1e5, maxq = 1e5;

// Function to generate a test case
void generate_testcase(int& total_n, int& total_m, int& total_q, int t) {
    int n = rnd.next(1, maxn - total_n - t * 600);
    total_n += n; // Update the total n used so far

    int m = rnd.next(1, maxm - total_m - t * 60);
    cout << n << " " << m << endl;

    for (int i = 0; i < m; ++i) {
        int l = rnd.next(1, n);
        int r = rnd.next(l, n); // ensure l <= r
        cout << l << " " << r << endl;
    }
    int q = rnd.next(1, maxq - total_q - t * 60);
    cout << q << endl;

    for (int i = 0; i < q; ++i) {
        int u = rnd.next(1, n);
        int v = rnd.next(u, n); // ensure u <= v
        cout << u << " " << v << endl;
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int total_n = 0; 
    int total_m = 0;
    int total_q = 0;
    int T = 10;
    cout << T << endl;
    for (int i = 0; i < T; ++i) {
        generate_testcase(total_n, total_m, total_q, T - i); 
    }
    return 0;
}
