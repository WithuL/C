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
	printf("С���10�����ʱ��������%f�ף���10�η���%f��\n", s, h);
	system("pause");
	return 0;
}