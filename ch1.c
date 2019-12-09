#include <stdio.h>

/* 1.6 Arrays
 *
 * Count the # of occurrences of each digit, of white space characters,
 * and of all other characters. 
 *
 * */

int
main()
{
	int c, i, nwhite, nother;
	int ndigit[10] = {0};

	nwhite = nother = 0;

	while ((c = getchar()) != EOF) 
		if (c >= '0' && c <= '9')
			++ndigit[c-'0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else 
			++nother;

		printf("digits =");
		for (i = 0; i < 10; ++i)
			printf(" %d", ndigit[i]); 
		printf(", white space = %d, other = %d\n",
			nwhite, nother);
}
