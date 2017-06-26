#include<stdio.h>

int main() {
	int number = 0;
	int count = 1;
	scanf_s("%d", &number);
	if (number >= 0 && number <= 9999) {

		if ((number / 1000) != 0) {
			count++;
			number = number % 1000;
		}
		if (number / 100 != 0) {
			count++;
			number = number % 100;
		}
		if (number / 10 != 0) {
			count++;
			number = number % 10;
		}
	}
	printf("%d\n", count);
}