#include <stdio.h>
#include <string.h>
#include <assert.h>

char s1[16];

#define CONTAIN_OF_ZERO_BYTE(n)	\
			( ((n-0x01010101) & (~n)) & 0x80808080 ) 

/* n = 0x12340078 */

#define TEST(n)		   ( ((n-1) & (~n)) & 0x80 )

#if 0
n = 0  -> 0xFF & 0xFF = 0xFF
n = 1  -> 0x00 & 0xFE = 0x0
n = 2  -> 0x01 & 0xFD = 0x1

n = FF ->             = 0b 0xxx xxxx

#endif

char *mystrcpy3(char *dest, const char *src)
{
	int * s;
	int * d;

	s = (int *)src;
	d = (int *)dest;
	char *p = dest;

	while (1)
	{
		if (!CONTAIN_OF_ZERO_BYTE(*s))
		{
			printf("*S is copied %x\n", *s);
			*d = *s;
			s++;
			d++;
			continue;
		}
		
		src = (char *)s;
		dest = (char *)d;

		while (*dest++ = *src++);
		break;
	}
	return 0;
}

char *mystrcpy(char *dest, const char *src)
{
	char *p = dest;
	long int delta = dest - src;

#if 0	
	if(dest == NULL || src == NULL)
	{
		printf("must be not NULL\n");
		return dest;
	}
#endif
	
	assert(dest != NULL && src != NULL);

	//while (*dest++ = *src++);
	while (*(char *)(src + delta) = *src++);
	
	return p;
}

int main(void)
{
	char s2[16] = "hello123456789";

	printf("1) s1 = %s\n", s1);
	mystrcpy(s1, s2);
	printf("2) s1 = %s\n", s1);

	return 0;
}
