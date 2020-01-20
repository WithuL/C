#include <stdbool.h>
#include<stdlib.h>
#include<Stdio.h>
#include<malloc.h>
struct Arr {
	int* pBase;
	int len;
	int cnt;
};
void init_arr();
bool is_full();
bool is_empyty();

void init_arr(struct Arr* pArr,int length) {
	pArr->pBase = (int*)malloc(sizeof(int) * length);
	if (NULL == pArr->pBase) {
		printf("��̬�ڴ����ʧ�ܣ�\n");
		exit(-1);
	}
	else {
		pArr->len = length;
		pArr->cnt = 0;
	}
	return;
}
bool append_arr(struct Arr* pArr,int val) {
	if (is_full(pArr) == true) {
		return false;
	}
	else {
		pArr->pBase[pArr->cnt] = val;
		(pArr->cnt)++;
		return true;
	}
}
bool insert_arr(struct Arr* pArr,int pos,int val) { //pos ���㿪ʼ
	if (is_full(pArr) == true) {
		printf("����ʧ�ܣ�\n");
		return false;
	}
	if (pos<1 || pos>pArr->cnt + 1) {
		printf("����ʧ�ܣ�\n");
		return false;
	}
	else {
		for (int i = pArr->cnt - 1; i >= pos - 1; i--) {
			pArr->pBase[i + 1] = pArr->pBase[i];
		}
		pArr->pBase[pos - 1] = val;
		pArr->cnt++;
		return true;
	}
}
bool delete_arr(struct Arr* pArr, int pos,int* pVal) {
	int i;
	if(is_empyty(pArr)==true){
		return false;
	}
	if (pos<1 || pos>pArr->cnt) {
		return false;
	}
	*pVal = pArr->pBase[pos - 1];
	for (i = pos; i < pArr->cnt; i++) {
		pArr->pBase[i - 1]= pArr->pBase[i];
	}
	pArr->cnt--;
	return true;
}
int get() {

}
bool is_empyty(struct Arr* pArr) {
	if (pArr->cnt == 0) {
		return true;
	}
	else {
		return false;
	}
}
bool is_full(struct Arr* pArr) {
	if (pArr->cnt == pArr->len) {
		printf("��������!\n");
		return true;
	}
	else {
		return false;
	}
}
void sort_arr(struct Arr* pArr) {   //����
	int i, j, tmp;
	for (i = 0; i < pArr->cnt; i++) {
		for (j = i + 1; j < pArr->cnt; j++) {
			if (pArr->pBase[i] > pArr->pBase[j]) {
				tmp = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = tmp;
			}
		}
	}
}
void show_arr(struct Arr* pArr) {
	if (is_empyty(pArr) == true) {
		printf("����Ϊ�գ�\n");
	} 
	else {
		for (int i = 0; i < pArr->cnt; i++) {
			printf("%d  ", pArr->pBase[i]);
		}
		printf("\n");
	}
}
void inversion_arr(struct Arr* pArr) {
	int i=0;
	int j = pArr->cnt-1;
	int tmp = 0;
	while (i < j) {
		tmp = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = tmp;
		i++;
		j--;
	}
}
int main() {
	struct Arr arr;
	int val;
	init_arr(&arr,6);
	printf("��ʼ��:\n");
	show_arr(&arr);
	printf("׷�����1��2��3��4��5:\n");
	append_arr(&arr, 1);
	append_arr(&arr, 2);
	append_arr(&arr, 3);
	append_arr(&arr, 4);
	append_arr(&arr, 5);
	show_arr(&arr);
	printf("�ڵ�����λ�ò�������4:\n");
	insert_arr(&arr,6,4);
	show_arr(&arr);
	printf("��С��������õ�:\n");
	sort_arr(&arr);
	show_arr(&arr);
	printf("����Ԫ�ص��õõ�:\n");
	inversion_arr(&arr);
	show_arr(&arr);
	printf("ɾ��������λ�õ�Ԫ��:\n");
	if (delete_arr(&arr, 3, &val)) {
		printf("ɾ���ɹ�����ɾ������Ϊ��%d\n", val);
	}
	else {
		printf("ɾ��ʧ��!\n");
	}
	show_arr(&arr);
	return 0;
}	