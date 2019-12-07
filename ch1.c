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

/* 1.5.4 Word Counting poor man's wc
 *
 * ex 1-11: How would you test this program? What kinds of input are
 * most likely to uncover bugs if there are any?
 *
 * 	The intended purpose of the program is to count characters and
 * 	words. The ability of the program to accomplish this behavior
 * 	depends on at least one assumption: that the EOF is in fact the
 * 	final character of the string of characters being counted. 
 *	
 * 	If input here is taken to be restricted to the ASCII codes only,
 * 	then I believe providing non-printable codes (i.e. tty control
 * 	codes, extended ASCII codes, etc.) as input to the program will
 * 	be most likely to uncover bugs, should they exist.
 *
 *	If we expand our definition of input to include supersets of the
 *	ASCII encoding, like the Unicode standard, then I think the
 *	likelihood of discovering bugs increases significantly.
 *
 *	Given that the first edition of this book was released in 1978,
 *	I think that K&R intended this exercise to provoke discussion
 *	about the 7-bit nature of the ASCII encoding. 
 *
 *	Regardless, I think sending bit-strings of arbitrary shape and
 *	size as input is the best way to find hidden bugs in a program
 *	like this, and today (Dec 2019) I would use a fuzzing† tool like
 *	AFL to exercise the program.
 *
 * 	†AFL (american fuzzy lop) - http://lcamtuf.coredump.cx/afl/
 *
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
			if (nc != 1) 		/* exercise 1-12 */
				printf("\n"); 	/* exercise 1-12 */
			state = IN;
			++nw;
		}
		printf("%c",c); /* exercise 1-12 */
	}
}
