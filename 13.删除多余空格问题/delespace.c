/* shell运行 ./a.out < text.txt */ 
#include <stdio.h>

int get_input_type(char c)
{
	if (c == ' ')
		return 1;

	return 0;
}

int main(void)
{
	char buf[] = "  This is     a book.   This   is a bag.\n";
	// input      11000010011111010000011100001110010100000
	// state 	 012000010012222010000012200001220010100000	
	// print	  p pppppppp    pppppppp  ppppp  pppppppppp
	// 0 0 -> 0
	// 1 1 -> 1
	// 1 0 -> 0
	// 1 1 -> 2
	// 2 0 -> 0 
	// 2 1 -> 2
	int state = 0;
	int i = 0;
	int words = 0;
	char *p = NULL; 
	int counter = 0;

	//printf("buf = %s\n", buf);
	
	i = 0;
	while (1)
	{
		char c;
		int input = 0;
		
		//c = buf[i];
		c = getchar(); 
		input = get_input_type(c);

		//printf("c = %c, input = %d\n", c, input);
		
		//if (c == '\0')
		if (c == EOF)
			break;
		
		if (state == 0 && input == 0)
		{	
			state = 0;
			printf("%c", c);
		}
		else if (state == 0 && input == 1)
		{	
			state = 1;
			printf("%c", c);
		}
		else if (state == 1 && input == 0)
		{
			state = 0;	
			printf("%c", c);
		}
		else if (state == 1 && input == 1)
		{	
			state = 2;
			// do nothing, don't output
		}
		else if (state == 2 && input == 0)
		{	
			state = 0;
			printf("%c", c);
		}
		else if (state == 2 && input == 1)
		{	
			state = 2;
			// do nothing, don't output
		}

		i++;
	}

	printf("there is %d words found!\n", words);

	return 0;
}
