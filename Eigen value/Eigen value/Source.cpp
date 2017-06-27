#include<stdio.h>

int main() {
	int number = 0;
	int count = 1;
	int bin = 1;
	int total = 0;

	scanf_s("%d", &number);
	do {

		if (((number % 10) - count) % 2 == 0) {
			total += bin;
		}
		number = number / 10;
		bin *= 2;
		count++;
	} while (number > 0);


	printf("%d\n", total);

}