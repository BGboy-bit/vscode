#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 0;//多组输入

class Student {
public:
    db score;
    static db total_score, count;
    void account(db sc) {
        score = sc;
        total_score += score;
        count++;
    }
    static db sum() {
        return total_score;
    }
    static db average() {
        if (count == 0) {
            return 0;
        }
        return total_score / count;
    }
};

// 初始化静态成员变量
db Student::total_score = 0;
db Student::count = 0;

void Solve() {
    Student stu;
    ll sum;
    cout << "Enter student's count: ";
    cin >> sum;
    cout << "Enter student's score: ";
    vector<db> st(sum + 1);
    for(ll i = 0; i < sum; i ++ ) {
        cin >> st[i];
        stu.account(st[i]);
    }
    // 输出结果
    cout << "Total score: " << stu.sum() << endl;
    cout << "Average score: " << stu.average() << endl;
}

signed main() {
    ll T = 1;
    if (multi) cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
