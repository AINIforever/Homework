#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main() {
	int n;
	printf("Please input a number:\n");
	scanf("%d",&n);
	if (n == 1) {
		printf("No sense to discuss whether 1 is a prime.\n");
		system("pause");
		return 0;
	}
	int a[100];
	int k = 0;
	int i = 0;
	for (i=1; i <= (int)(pow(n, 0.5)); i++) {
		if (n%i == 0) {
			a[k] = i;
			k++;
			a[k] = n / i;
			k++;
		}
	}
	if (k > 2) {
		printf("It is not a prime.\nIts divisors are:");
		for (i = 0; i < k; i++) {
			printf("%d ", a[i]);
		}
	}
	else printf("It is a prime.\n");
	system("pause");
	return 0;
}
