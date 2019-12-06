#include <stdio.h>

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

int
main()
{
	fahr_celsius();
	return 0;
}
