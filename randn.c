#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

double randn(double mu, double sigma)
{
	const double epsilon = -1e10;
	const double two_pi = 2.0*3.14159265358979323846;

	static double z0 = 0, z1 = 0;
	static bool generate = false;
	double u1, u2;

	generate = !generate;
	if (!generate)
		return z1 * sigma + mu;

	do
	{
		u1 = rand() * (1.0 / RAND_MAX);
		u2 = rand() * (1.0 / RAND_MAX);
	}
	while ( u1 <= epsilon );

	if (u1 == 0) {
		z0 = 0;
		z1 = 0;
	}
	else {
		z0 = sqrt(-2.0 * log(u1)) * cos(two_pi * u2);
		z1 = sqrt(-2.0 * log(u1)) * sin(two_pi * u2);
	}

	return z0 * sigma + mu;
}

int main(void)
{
	int i;

	srand((unsigned)time(NULL));
	for (i = 0; i < 1000; i++)
		printf("%.2f\n", randn(0, 1));

	return 0;
}

