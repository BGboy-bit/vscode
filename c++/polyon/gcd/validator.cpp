#include "testlib.h"
using namespace std;

const int max_testcount = 100000;
const int max_n = 100000;
const int max_val = 100000;
const int max_K = 1'000'000'000;

int main(int argc, char** argv) {
    registerValidation(argc, argv);
    int testcount = inf.readInt(1, max_testcount, "t");
    inf.readEoln();
    int sum_n = 0;
    for (int testcase = 1; testcase <= testcount; ++testcase) {
        setTestCase(testcase);
        int n = inf.readInt(1, max_n, "n");
        inf.readSpace();
        int K = inf.readInt(1, max_K, "K");
        inf.readEoln();
        sum_n += n;
        ensuref(sum_n <= max_n, "sum of n over all cases should not exceed %d", max_n);
        for(int nn = 1; nn <= n; nn ++ ) {
            inf.readInt(1, max_val, "a");
            if(nn == n) inf.readEoln();
            else inf.readSpace();
        }
    }
    inf.readEof();
    return 0;
}
