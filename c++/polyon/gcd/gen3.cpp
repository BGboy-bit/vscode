#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    
    // 获取选项参数
    int test_count = opt<int>("test-count");
    int sum_n = opt<int>("sum-n");
    int min_a_min = opt<int>("min-a-lower");  // 最小值的最小范围
    int min_a_max = opt<int>("min-a-upper");  // 最小值的最大范围
    int A_min = opt<int>("A-lower");          // A 的最小值
    int A_max = opt<int>("A-upper");          // A 的最大值
    int max_K = opt<int>("max-K");

    auto lengths = rnd.partition(test_count, sum_n);
    cout << test_count << '\n';
    for (auto n: lengths) {
        int K = rnd.next(1, max_K);
        vector<int> a(n);

        // 随机生成 min_a 和 A
        int min_a = rnd.next(min_a_min, min_a_max);
        int A = rnd.next(A_min, A_max);

        // 生成排序后的数组 a，第一组之间相差 A，第二组之间相差 2A，依此类推
        int start = rnd.next(min_a, min_a + A * (n - 1));
        a[0] = start;
        for (int i = 1; i < n; ++i) {
            int gap = ((i + 1) / 2) * A;  // 每两组递增差值
            a[i] = a[i - 1] + gap;
            if(a[i] > 100000) a[i] = 100000;
        }

        // 打乱数组 a 的顺序
        shuffle(a.begin(), a.end());

        cout << n << ' ' << K << '\n';
        println(a);     // println 不会在行末打印额外的空格
    }
    
    return 0;
}
