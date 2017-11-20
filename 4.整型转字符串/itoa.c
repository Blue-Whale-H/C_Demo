#include <stdio.h>

char *itoa(int num);
char *reverse(char *s);

int main(void)
{
	int  num = 0;
	int  j = 0;
	char buf[10];

	printf("please input a number:");
	scanf("%d", &num);
	printf("num = %d\n", num);

	printf("buf = %s\n", itoa(num) );
	
	return 0;
}

char *itoa(int num)
{
	int  i = 0;
	char buf[10];

	/* num 123 to string "321" */
	do
	{
		buf[i] = num % 10 + '0';
		i++;

		num /= 10;
	} while (num != 0);
	buf[i] = '\0';

	return reverse(buf);
}

//reverse string 
char *reverse(char *s)  
{  
    char temp;  
    char *p = s;    //p指向s的头部  
    char *q = s;    //q指向s的尾部  
    while(*q)  
        ++q;  
    q--;  
  
    //交换移动指针，直到p和q交叉  
    while(q > p)  
    {  
        temp = *p;  
        *p++ = *q;  
        *q-- = temp;  
    }  
    return s;  
}  
