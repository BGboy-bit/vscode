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


void transposeMatrix(int** matrix, int rows, int cols) {
    // 创建一个临时矩阵来存储转置后的结果
    int** tempMatrix = new int*[cols];
    for (int i = 0; i < cols; ++i) {
        tempMatrix[i] = new int[rows];
    }

    // 执行矩阵转置操作
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            tempMatrix[j][i] = matrix[i][j];
        }
    }

    // 将转置后的矩阵复制回原矩阵
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            matrix[i][j] = tempMatrix[i][j];
        }
    }

    // 释放临时矩阵的内存
    for (int i = 0; i < cols; ++i) {
        delete[] tempMatrix[i];
    }
    delete[] tempMatrix;
}


void Solve() {
    const int rows = 3;
    const int cols = 3;

    // 使用动态内存分配创建3x3矩阵
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    // 初始化矩阵
    int num = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = num++;
        }
    }

    // 打印原始矩阵
    std::cout << "Original Matrix:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    // 执行矩阵转置
    transposeMatrix(matrix, rows, cols);

    // 打印转置后的矩阵
    std::cout << "\nTransposed Matrix:" << std::endl;
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    // 释放矩阵的内存
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}


signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}

