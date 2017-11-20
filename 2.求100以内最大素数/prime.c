#include <stdio.h>
#include <math.h>

int main(void)
{
	int i = 0;
	int num = 0;
	int max;

	printf("max prime from 1 to 100!\n");
	//scanf("%d", &num);

	for (num=1; num <=100; num += 2)
	{
		int tmp = sqrt(num);
		for (i = 2; i <= tmp; i++)
		{
			if (num % i == 0)
			{
#if DEBUG
				//printf("i = %d\n", i);
				printf("num %d is NOT a prime!\n", num);
#endif
				break;
			}		
		}

		//printf("i = %d\n", i);
		if (i == tmp + 1)
		{
			max = num;	
#if DEBUG
			printf("num %d is a prime!\n", num);
#endif
		}
	}

	printf("max prime is %d\n", max);

	return 0;
}
