#include<stdio.h>

int main() {
	int number = 0;
	int count = 1;
	scanf_s("%d", &number);
		while((number / 10)!=0) {
			count++;
			number = number /10;
		}
		
	printf("%d\n", count);

}