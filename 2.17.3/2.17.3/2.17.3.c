#include<stdio.h>
#include<stdbool.h>
bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    int row = matrixSize - 1; //行
    int col = 0;              //列
    while ((row >= 0) && (col < *matrixColSize)) {
        if (target > matrix[row][col]) {
            col++;
        } else if (target < matrix[row][col]) {
            row--;
        } else {
            return true;
        }
    }
    return false;
}
int main() {
    int matrix[3][3] = { 1,2,3,4,5,6,7,8,9 };
    int matrixSize = 3;//行数
    int matrixColSize = 3;//列数
    int target = 6;
    return findNumberIn2DArray((int**)matrix, matrixSize, &matrixColSize, target);
}