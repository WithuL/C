#include<stdio.h>
double myPow(double x, int n) {
    double res = 1.0;
    int flag = 1;
    long long i = n;
    if (i < 0) flag = -1, i *= flag, x = 1 / x;
    while (i != 0) {
        if (i & 1) res *= x;
        x *= x;
        i = i >> 1;
    }
    return res;
}
int main() {
    double x = 2.0;
    int n = -2;
    double res = myPow(x, n);
    printf("%f", res);
    return 0;
}