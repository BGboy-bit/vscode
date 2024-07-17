#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    
    int T = inf.readInt(1, 10000, "T");
    inf.readEoln();
    int total_n = 0;
    for (int t = 0; t < T; ++t) {
        cout << "t = " << t << "\n";
        int n = inf.readInt(1, 100000, "n");
        total_n += n;  // Add current n to total sum
        cout << "totel_n = " << total_n << "\n";
        if (total_n > 100000) {
            quitf(_wa, "Sum of all n values across test cases exceeds 100000.");
        }
        inf.readSpace();
        int m = inf.readInt(1,100000, "m");
        inf.readEoln();
        
        for (int i = 0; i < m; ++i) {
            int l = inf.readInt(1, n, "l");
            inf.readSpace();
            int r = inf.readInt(l, n, "r");
            inf.readEoln();
        }
        
        int q = inf.readInt(1, 100000, "q");
        inf.readEoln();
        
        for (int i = 0; i < q; ++i) {
            int l = inf.readInt(1, n, "l");
            inf.readSpace();
            int r = inf.readInt(l, n, "r");
            inf.readEoln();
        }
    }
    
    inf.readEof();
    return 0;
}
