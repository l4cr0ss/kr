#include <stdio.h>
#include <assert.h>

/* print Fahrenheit-Celsius table
 *  for fahr = 0, 20, ..., 300 */
void
fahr_celsius()
{
	float 	fahr,
	      	celsius;
	int 	lower,
		upper,
		step;

	lower = 0;	// lower limit
	upper = 300;	// upper limit
	step  = 20;	// step size

	printf("fahr|celsius\n"); // print header line
	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}


}

/* print Celsius-Fahrenheit table
 *  for celsius = 0, 20, ..., 300 */
void
celsius_fahr()
{
	float 	fahr,
	      	celsius;
	int	lower,
		upper,
		step;
	lower = 0;
	upper = 300;
	step  = 20;
	printf("celsius|fahr\n"); // print header line
	celsius = lower;
	while (celsius <= upper) {
		fahr = (celsius/(5.0/9.0)) + 32;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}

#define IN  1	/* inside a word */
#define OUT 0	/* outside a word */

/* 1.5.4 Word Counting
 * poor man's wc
 * */
int
main()
{
	int c,
	    nl,
	    nw,
	    nc,
	    state;
	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) { 
			state = IN;
			++nw;
		}
		printf("%d %d %d\n", nl, nw, nc);
	}
}
