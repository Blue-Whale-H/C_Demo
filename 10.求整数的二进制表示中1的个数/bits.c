#include <stdio.h>

int main(void)
{
	/*
	1 | 1 = 1		1 & 1 = 1
	1 | 0 = 1		1 & 0 = 0
	0 | 0 = 0		0 & 0 = 0
	*/
	int num = 0;
	int ret = 0;
	int sum = 0;
	int i = 0;

	printf("input a number:");
	scanf("%d", &num);

/*	
	// 0xff = 1111 1111
	// 0x55 = 0101 0101
	// & 1  = 0101 0101
	// 0xff>>1
	//      = 0111 1111
	// 0x55 = 0101 0101
	// & 2  = 0101 0101
	// 1+2  = 1010 1010
	// 0x33 = 0011 0011
	// &    = 0010 0010
	// >>2  = 0010 1010
	// &0x33= 0010 0010
	// +    = 0100 0100
	// 0x0f = 0000 1111
	// &    = 0000 0100
	// >>4  = 0000 0100
	// &2   = 0000 0100
	// 1+2  = 0000 1000 = 8 */

	#define M1 0x55555555
	#define M2 0x33333333
	#define M3 0x0F0F0F0F
	#define M4 0x00FF00FF
	#define M5 0x0000FFFF

	num = (num & M1) + ((num >> 1) & M1);
	printf("num = 0x%x\n", num);

	num = (num & M2) + ((num >> 2) & M2);
	printf("num = 0x%x\n", num);

	num = (num & M3) + ((num >> 4) & M3);
	printf("num = 0x%x\n", num);
	
	num = (num & M4) + ((num >> 8) & M4);
	printf("num = 0x%x\n", num);

	num = (num & M5) + ((num >> 16) & M5);
	printf("num = 0x%x\n", num);
	sum = num;

#if 0	
	// 0x64 = 0110 0100	
	// 1 << n == 2^n
	// 0x4 = 0100
	// 0x3 = 0011
	// & = 0000
	// n & (n - 1) -> clear most-right bit 1

	while (num != 0)
	{
		num = num & (num - 1);
		printf("num = 0x%x\n", num);
		sum++;
	}
#endif

#if 0	
	for (i = 0; i < 32; i++)
	{
		if (num & (1<<i))
		{
			printf("bit %d is 1\n", i);
			sum++;
		}
	}
#endif	

	printf("num %d(0x%x) has %d bit 1!\n", num, num, sum);

#if 0
	ret = num & 1;
	printf("ret = %d\n", ret);

	ret = num & 2;  // b10
	printf("ret = %d\n", ret);

	ret = num & 4;  // b100
	printf("ret = %d\n", ret);
#endif

	return 0;
}
