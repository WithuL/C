#include <stdio.h>
int main()
{
	int a;
	printf("�������ַ�\n");
	while ((a = getchar()) != EOF)
	{
		if (a >= 'a' && a <= 'z')
		{
			printf("%c\n", a - 32);
		}
		if (a >= 'A' && a <= 'Z')
		{
			printf("%c\n", a + 32);
		}
		if (a >= '0'&& a <= '9')
		{
			continue;
		}
	}
	return 0;
}