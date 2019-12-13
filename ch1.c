#include <stdio.h>
#include <assert.h>

#define IN  1	/* inside a word */
#define OUT 0	/* outside a word */

#define WLMAX 255 /* max word size */
#define WLMOD  1 /* histogram modulus */

/* 1.7 Functions
 *
 * A function provides a convenient way to encapsulate some computation,
 * which can then be used without worrying about its implementation.
 * */

int power (int m, int n);

/* test power function */
int
main()
{
	int i;

	for (i = 0; i < 10; ++i)
		printf("%d %d %d\n", i, power(2,i), power(-3,i));
	return 0;
}

/* power: raise base to n-th power; n >= 0 */
int
power (int base, int n)
{
	int i,
		p;

	p = 1;
	for (i = 1; i <= n; ++i)
		p = p * base;
	return p;
}

// vim:ts=4 sw=4
