#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int reverse(int x) {
	long long sum = 0;
	for (; x != 0; sum = sum * 10 + x % 10, x = x / 10);
	if (sum<INT_MIN || sum>INT_MAX) return 0;
	return (int)sum;
}
int main() {
	int i = 900;
	int j = 0;
	j = reverse(i);
	printf("%d", j);
	return 0;
}