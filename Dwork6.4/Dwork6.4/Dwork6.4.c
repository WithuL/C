#include<stdlib.h>
#include<stdio.h>
void reverse_string(char string[])
{
	if (*string != '\0') {
		reverse_string(string + 1);
		printf("%c ", *string);
	}
}

int main()
{
	char string[]= "abcde";
	reverse_string(string);
	printf("\n");
	system("pause");
	return 0;
}