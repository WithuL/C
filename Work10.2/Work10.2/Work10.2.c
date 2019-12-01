#include<stdio.h>
#include<stdlib.h>
int main() {
	int killer;
	for (killer = 'a'; killer <= 'd'; killer++) {
		if(((killer!='a')+(killer=='c')+(killer=='d')+(killer!='d'))==3){
			printf("%c是凶手！\n", killer);
			break;
		}
	}
	system("pause");
	return 0;
}