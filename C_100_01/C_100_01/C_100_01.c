//��1��2��3��4���ĸ����֣�����ɶ��ٸ�������ͬ�����ظ����ֵ���λ�������Ƕ���?
#include<stdio.h>
#include<stdlib.h>
int main() {
	int i,j,k,count=0;
	for (i = 1; i < 5; i++) {
		for (j = 1; j < 5; j++) {
			for (k = 1; k < 5; k++) {
				if (i != j && j != k) {
					printf("%d%d%d\n", i, j, k);
					count += 1;
				}
			}
		}
	}
	system("pause");
	return 0;
}