//��С��������
#include<stdio.h>
#include<stdlib.h>
//�˺���Ϊһ��ð������������Ϊ�����򲿷ֺ�δ���򲿷�
void BubbleSort(int arr[],int size) {
	//ѭ���������δ���򲿷ֵı߽磬����������鷶ΧΪ[0,Bound],δ��������鷶ΧΪ[Bound,size-1]
	for (int bound = 0; bound < size; bound++) {
		//��ʱ��δ���򲿷ֱȽϴ�С�������һ������Ԫ�ؿ�ʼ����ǰһ��Ԫ����ȣ��Ѹ�С���滻Ϊǰһλ��ֱ���Ƚϵ��߽�
		for (int cur = size-1; cur > bound; cur--) {
			if (arr[cur - 1] > arr[cur]) {
				int tmp = arr[cur - 1];
				arr[cur - 1] = arr[cur];
				arr[cur] = tmp;
			}
		}
	}
	
}
int main() {
	int arr[7] = { 8,4,6,1,3,9,5 };
	int size = 7;
	BubbleSort(arr,size);
	for (int i = 0; i < size; i++) {
		printf("%d  ", arr[i]);
	}
	system("pause");
	return 0;
}