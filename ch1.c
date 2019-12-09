#include <stdio.h>
#include <assert.h>

#define IN  1	/* inside a word */
#define OUT 0	/* outside a word */

#define WLMAX 32 /* max word size */
#define WLMOD  1 /* histogram modulus */

/* 1.6 Arrays
 *
 * 	ex 1-13
 * */
int
main()
{
	/* Declarations */
	int c,
		i,			// iterator i
		j,			// iterator j
	    nl,			// num letters
	    nw,			// num words
	    nc,			// num characters
		wl,			// word length
	    state;		// in or out of word
	int wlens[32];	// histogram

	/* Initializations */
	for (i = 0; i < WLMAX; i++)
		wlens[i] = 0;
	state = OUT;
	nl = nw = nc = wl = 0;

	/* Calculations */
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
		} else if (state == OUT) {
			if (wl != 0 && wl < WLMAX)
				++wlens[wl];
			wl = 0;
			state = IN;
			++nw;
		} else {
			++wl;
		}
	}

	for (i = 0; i < WLMAX; i++) {
		if (wlens[i] > 0) {
			printf("[%2d] (%d) ", i, wlens[i]);
			for (j = 0; j < wlens[i]; j++) 
				if (j % WLMOD == 0 )
					printf("*");
			printf("\n");
		}
	}
}
