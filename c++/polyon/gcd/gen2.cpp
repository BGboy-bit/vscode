#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    
    // 获取选项参数
    int test_count = opt<int>("test-count");
    int sum_n = opt<int>("sum-n");
    int min_a_lower = opt<int>("min-a-lower"); // min_a 的下限
    int min_a_upper = opt<int>("min-a-upper"); // min_a 的上限
    int A_lower = opt<int>("A-lower"); // A 的下限
    int A_upper = opt<int>("A-upper"); // A 的上限
    int max_K = opt<int>("max-K");

    auto lengths = rnd.partition(test_count, sum_n);
    cout << test_count << '\n';
    for (auto n: lengths) {
        int K = rnd.next(1, max_K);
        vector<int> a(n);

        // 在指定范围内生成 min_a 和 A
        int min_a = rnd.next(min_a_lower, min_a_upper);
        int A = rnd.next(A_lower, A_upper);

        // 生成排序后的数组 a，所有元素之间相差固定的值 A
        int start = rnd.next(min_a, min_a + A * (n - 1));
        for (int i = 0; i < n; ++i) {
            a[i] = start + i * A;
            if(a[i] > 100000) a[i] = 100000;
        }

        // 打乱数组 a 的顺序
        shuffle(a.begin(), a.end());

        cout << n << ' ' << K << '\n';
        println(a);     // println 不会在行末打印额外的空格
    }
    
    return 0;
}
