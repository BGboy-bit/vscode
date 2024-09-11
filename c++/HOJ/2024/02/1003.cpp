#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
typedef struct {
    char data[9][12];
} Cube;

Cube rotateTopClockwise(Cube c) { // 顶面逆时针
    Cube result = c;
    char temp;
    temp = result.data[0][3];
    result.data[0][3] = result.data[2][3];
    result.data[2][3] = result.data[2][5];
    result.data[2][5] = result.data[0][5];
    result.data[0][5] = temp;
    temp = result.data[0][4];
    result.data[0][4] = result.data[1][3];
    result.data[1][3] = result.data[2][4];
    result.data[2][4] = result.data[1][5];
    result.data[1][5] = temp;
    char edgeTop[3] = {result.data[3][2], result.data[3][1], result.data[3][0]};
    for (int i = 0; i < 3; i++) {
        result.data[3][i] = result.data[3][11-i];
        result.data[3][11-i] = result.data[3][8-i];
        result.data[3][8-i] = result.data[3][5-i];
        result.data[3][5-i] = edgeTop[i];
    }
    return result;
}

Cube rotateFrontClockwise(Cube c) { // 正面顺时针
    Cube result = c;
    char temp = result.data[3][3];
    result.data[3][3] = result.data[5][3];
    result.data[5][3] = result.data[5][5];
    result.data[5][5] = result.data[3][5];
    result.data[3][5] = temp;
    temp = result.data[3][4];
    result.data[3][4] = result.data[4][3];
    result.data[4][3] = result.data[5][4];
    result.data[5][4] = result.data[4][5];
    result.data[4][5] = temp;
    char topRow[3] = {result.data[2][3], result.data[2][4], result.data[2][5]};
    char rightCol[3] = {result.data[3][6], result.data[4][6], result.data[5][6]};
    char bottomRow[3] = {result.data[6][5], result.data[6][4], result.data[6][3]};
    char leftCol[3] = {result.data[5][2], result.data[4][2], result.data[3][2]};
    for (int i = 0; i < 3; i++) {
        result.data[2][3+i] = leftCol[2-i];
        result.data[3+i][6] = topRow[i];     
        result.data[6][5-i] = rightCol[i];  
        result.data[5-i][2] = bottomRow[2-i];
    }
    return result; 
}

Cube rotateLeftFaceClockwise(Cube c) { // 左边顺时针
    Cube result = c; 
    char temp = result.data[3][0];
    result.data[3][0] = result.data[5][0];
    result.data[5][0] = result.data[5][2];
    result.data[5][2] = result.data[3][2];
    result.data[3][2] = temp;
    temp = result.data[3][1];
    result.data[3][1] = result.data[4][0];
    result.data[4][0] = result.data[5][1];
    result.data[5][1] = result.data[4][2];
    result.data[4][2] = temp;
    char topCol[3] = {result.data[0][3], result.data[1][3], result.data[2][3]};
    char frontCol[3] = {result.data[3][3], result.data[4][3], result.data[5][3]};
    char bottomCol[3] = {result.data[6][3], result.data[7][3], result.data[8][3]};
    char backCol[3] = {result.data[5][11], result.data[4][11], result.data[3][11]};
    for (int i = 0; i < 3; i++) {
        result.data[i][3] = backCol[i];    
        result.data[3+i][3] = topCol[i];   
        result.data[6+i][3] = frontCol[i];  
        result.data[5-i][11] = bottomCol[i];
    }
    return result;
}

Cube rotateRightFaceClockwise(Cube c) {
    Cube result = c;  // 创建一个魔方的副本

    // 旋转右面的角块
    char temp = result.data[3][6];
    result.data[3][6] = result.data[5][6];
    result.data[5][6] = result.data[5][8];
    result.data[5][8] = result.data[3][8];
    result.data[3][8] = temp;

    // 旋转右面的边块
    temp = result.data[3][7];
    result.data[3][7] = result.data[4][6];
    result.data[4][6] = result.data[5][7];
    result.data[5][7] = result.data[4][8];
    result.data[4][8] = temp;

    // 调整与右面相邻的顶部、底部、正面和后面的边块
    char topRight[3] = {result.data[0][5], result.data[1][5], result.data[2][5]};
    char frontRight[3] = {result.data[3][5], result.data[4][5], result.data[5][5]};
    char bottomRight[3] = {result.data[6][5], result.data[7][5], result.data[8][5]};
    char backLeft[3] = {result.data[3][9], result.data[4][9], result.data[5][9]};

    // 更新相邻面的边块
    for (int i = 0; i < 3; i++) {
        result.data[i][5] = frontRight[i];       // 顶面的右边界接收正面的右边界
        result.data[3+i][5] = topRight[2-i];    // 正面的右边界接收顶面的右边界（顶部向下，所以逆序）
        result.data[6+i][5] = backLeft[2-i];    // 底面的右边界接收后面的左边界（后面向前，所以逆序）
        result.data[5-i][9] = bottomRight[i];   // 后面的左边界接收底面的右边界
    }   

    return result; 
}


void printCube(Cube cube) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 12; j++) {
            printf("%c ", cube.data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    string s;
    s.find("s");
    Cube cube = {
        .data = {
            {'*', '*', '*', '1', '1', '1', '*', '*', '*', '*', '*', '*'},
            {'*', '*', '*', '1', '1', '1', '*', '*', '*', '*', '*', '*'},
            {'*', '*', '*', '1', '1', '1', '*', '*', '*', '*', '*', '*'},
            {'2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5'},
            {'2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5'},
            {'2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5'},
            {'*', '*', '*', '6', '6', '6', '*', '*', '*', '*', '*', '*'},
            {'*', '*', '*', '6', '6', '6', '*', '*', '*', '*', '*', '*'},
            {'*', '*', '*', '6', '6', '6', '*', '*', '*', '*', '*', '*'}
        }
    };

    //cube = rotateTopClockwise(cube);
    //cube = rotateFrontClockwise(cube);
    // cube = rotateLeftFaceClockwise(cube);
    cube = rotateRightFaceClockwise(cube);
    printCube(cube);

    return 0;
}
/*
* * * 1 1 1 * * * * * *
* * * 1 1 1 * * * * * *
* * * 1 1 1 * * * * * *
2 2 2 3 3 3 4 4 4 5 5 5
2 2 2 3 3 3 4 4 4 5 5 5
2 2 2 3 3 3 4 4 4 5 5 5
* * * 6 6 6 * * * * * *
* * * 6 6 6 * * * * * *
* * * 6 6 6 * * * * * *
*/