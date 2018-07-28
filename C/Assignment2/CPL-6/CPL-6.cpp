#include<stdio.h>
#include<stdlib.h>


int main() {

	double x, max, min, average;
	printf("Please input ten numbers:\n");
	scanf("%lf", &x);
	max = x;
	min = x;
	average = x;
	int i;
	for (i = 1; i < 10; i++) {
		scanf("%lf", &x);
		if (x > max) max = x;
		if (x < min) min = x;
		average = average + x;
	}

	printf("Max is %g\n", max);
	printf("Min is %g\n", min);
	printf("Average is %g\n", average / 10);

	system("pause");
	return 0;
}
