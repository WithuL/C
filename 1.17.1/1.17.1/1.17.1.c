#include <stdio.h>
#include<stdlib.h>
int main()
{
    int i, num;
    num = 2;
    for (i = 0; i < 3; i++)
    {
        printf("num ����Ϊ %d \n", num);
        num++;
        {
            auto int num = 1;
            printf("����ģ�� num ����Ϊ %d \n", num);
            num++;
        }
    }
    system("pause");
    return 0;
}