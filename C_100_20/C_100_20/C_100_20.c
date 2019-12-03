#include <stdio.h>
#include<stdlib.h>
int main(void)
{
	int i;
	float s = 0;
	float h = 100;
	for (i = 0; i < 10; i++)
	{
		s = s + h; 
		h = h / 2.0;
		if (i != 9)
		{
			s = s + h;
		}
	}
	printf("小球第10次落地时，共经过%f米，第10次反弹%f米\n", s, h);
	system("pause");
	return 0;
}