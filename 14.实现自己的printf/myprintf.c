#include <stdio.h>

#include <stdarg.h>
// va_list xxx;
// va_start;
// va_arg()
// va_end()

char buf[32];

void itoa(int num, char *buf, int base)
{
	char * hex = "0123456789ABCDEF";
	int i = 0; 
	int j = 0;

	do
	{
		int rest;
		
		rest = num % base;
		buf[i++] = hex[rest];  // *(hex + rest)
		num /= base;
	} while (num != 0);

	buf[i] = '\0';

#define SWAP(a, b) \
		do		   \
		{						\
			a = (a) ^ (b);		\
			b = (a)	^ (b);		\
			a = (a) ^ (b);      \
		} while(0)					    

	for (j = 0; j < i/2; j++)
	{
		SWAP(buf[j], buf[i-1-j]);
	}

	return;
} 

void myputs(char *buf)
{
	while (*buf)
		putchar(*buf++);

	return;
}

int myprintf(const char * format, ...)
{
	va_list ap;
	char c;
 	int value;
	
	va_start(ap, format);
	printf("<1> ap = %p\n", ap);

	while ((c = *format++) != '\0')
	{
		if (c != '%')
		{
			putchar(c);
			continue;
		}
		else
		{
			//get next char arter %
			c = *format++;
			switch (c)
			{
				case 's':
					myputs(va_arg(ap, char *));
					break;
				case 'c':
					putchar(va_arg(ap, int));
					break;
				case 'd':
					value = va_arg(ap, int);
					itoa(value, buf, 10);
					myputs(buf);
					break;
				case 'x':
					value = va_arg(ap, int);
					itoa(value, buf, 16);
					myputs(buf);
					break;
				default:
					va_end(ap);
					printf("ap = %p\n", ap);
			}
		}
	}

	va_end(ap);
	printf("<end> ap = %p\n", ap);
	
	return 0;
}

int main(void)
{
	myprintf("a = %d, b = 0x%x, c = %c, d = %s\n", 100, 200, 'C', "This is a book");

	return 0;
}
