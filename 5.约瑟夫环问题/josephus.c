#include <stdio.h>

#define ALL		10		// all people in the ring
#define OUT     3		// if count to 3 

/* global array for all people in the ring */
int people[ALL];
/* record the next people's index */
int next[ALL];

void init_ring(void)
{
	int i = 0;

	/* init ring */
	for (i = 0; i < ALL; i++)
		people[i] = i + 1;
	
	for (i = 0; i < ALL; i++)
		next[i] = (i + 1) % ALL;
	return;
}

void print_ring(void)
{
	int i = 0;

	/* print ring */
	for (i = 0; i < ALL; i++)
		printf("%d ", people[i]);
	printf("	(people)\n");

	for (i = 0; i < ALL; i++)
		printf("%d ", next[i]);
	printf("	(next)\n");
}

int main(void)
{
	int left;		// how many people in the ring
	int counter;
	int i;
	int prev;

	printf("demo josephus ring problem!\n");
	
	init_ring();

	print_ring();

	left = ALL;		// left = all people
	counter = 0;	// counter = 1, 2, 3
	i = 0;          // begin from [0]
	prev = ALL - 1; // 0's prev = 5;

	while (1)
	{
		if (people[i] > 0)
			counter++;

		// if count to 3, then someone is out
		if (counter == OUT)
		{
			left--;				// someone is out
			printf("%d is out\n", i + 1);
			people[i] = 0;		// set this people out

			/* set the next[] */
			next[prev] = next[i];

			print_ring();
			counter = 0;		// set counter = 0
		}

#if DEBUG
		printf("i = %d, counter = %d, left = %d\n", i, counter, left);
#endif

		if (left < 1)
			break;
		
		prev = i;
		i = next[i];					// get next i
		//if (i == ALL)
		//	i = 0;

		//getchar();
	}
	
	printf("problem is finished\n");

	return 0;
}
