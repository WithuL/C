#include<stdio.h>
main()
{
	float sn = 100.0, hn = sn / 2;
	int n;
	for (n = 2; n <= 10; n++)
	{
		sn = sn + 2 * hn; 
		hn = hn / 2;
	}
	printf("总路程为 % f\n", sn);
	printf("反弹高度为 % f m\n", hn);
	return 0;
}