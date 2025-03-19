#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 0;//��������


void transposeMatrix(int** matrix, int rows, int cols) {
    // ����һ����ʱ�������洢ת�ú�Ľ��
    int** tempMatrix = new int*[cols];
    for (int i = 0; i < cols; ++i) {
        tempMatrix[i] = new int[rows];
    }

    // ִ�о���ת�ò���
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            tempMatrix[j][i] = matrix[i][j];
        }
    }

    // ��ת�ú�ľ����ƻ�ԭ����
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            matrix[i][j] = tempMatrix[i][j];
        }
    }

    // �ͷ���ʱ������ڴ�
    for (int i = 0; i < cols; ++i) {
        delete[] tempMatrix[i];
    }
    delete[] tempMatrix;
}


void Solve() {
    const int rows = 3;
    const int cols = 3;

    // ʹ�ö�̬�ڴ���䴴��3x3����
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    // ��ʼ������
    int num = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = num++;
        }
    }

    // ��ӡԭʼ����
    std::cout << "Original Matrix:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    // ִ�о���ת��
    transposeMatrix(matrix, rows, cols);

    // ��ӡת�ú�ľ���
    std::cout << "\nTransposed Matrix:" << std::endl;
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    // �ͷž�����ڴ�
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

