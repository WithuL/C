//��ת�������С����
#include<stdio.h>
int minArray(int* numbers, int numbersSize) {
    if (numbersSize == 0) {
        return 0;
    }
    for (int i = 1; i < numbersSize; i++) {
        if (numbers[i] < numbers[i - 1]) {
            return numbers[i];
        }
    }
    return numbers[0];
}
int main() {
    int arr[3] = { 1,3,5 };
    int numsSize = sizeof(arr) / sizeof(int);
    printf("��ת�������С����Ϊ��%d",minArray(arr, numsSize));
    return 0;
}