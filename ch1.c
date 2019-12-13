#include <stdio.h>
#include <assert.h>

#define IN  1	/* inside a word */
#define OUT 0	/* outside a word */

#define WLMAX 255 /* max word size */
#define WLMOD  1 /* histogram modulus */

/* 1.6 Arrays
 *
 * 	ex 1-14
 * */
int
main()
{
	/* Declarations */
	int c,
		i,			// iterator i
		j,			// iterator j
	    nc;			// num characters
	int wl[WLMAX];	// histogram

	/* Initializations */
	nc = 0;
	for (i = 0; i < WLMAX; i++)
		wl[i] = 0;

	/* Calculations */
	while ((c = getchar()) != EOF) {
		++nc;
		++wl[c];
	}

	for (i = 0; i < WLMAX; i++) {
		if (wl[i] > 0) {
			printf("[%3d] (%3d) ", i, wl[i]);
			for (j = 0; j < wl[i]; j++) 
				if (j % WLMOD == 0 )
					printf("*");
			printf("\n");
		}
	}
}

// vim:ts=4 sw=4
