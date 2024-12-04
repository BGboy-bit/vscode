#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    
    // 获取选项参数
    int test_count = opt<int>("test-count");
    int sum_n = opt<int>("sum-n");
    int min_a = opt<int>("min-a");
    int max_a = opt<int>("max-a");
    int max_K = opt<int>("max-K");

    auto lengths = rnd.partition(test_count, sum_n);
    cout << test_count << '\n';
    for (auto n: lengths) {
        int K = rnd.next(1, max_K);
        vector<int> a(n);
        for (auto& i: a) {
            i = rnd.next(min_a, max_a);
        }
        cout << n << ' ' << K << '\n';
        println(a);     // println 不会在行末打印额外的空格
    }
    
    return 0;
}
