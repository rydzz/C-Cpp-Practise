#include<stdio.h>
#include "array.h"




int main(int argc, char* argv[]) {
	Array a = array_creat(2);
	int cnt = 0;
	int num = 0;
	while (num != -1) {

		scanf("%d", &num);
		if (num != -1)
			*array_at(&a, cnt++) = num;
	}
	printf("所输入的数组为：\n");
	printf("%d\n", array_size(&a));
	printf("{");
	for (num = 0; num < array_size(&a); num++) {

		printf("%d ", a.array[num]);
	}printf("}");

	array_free(&a);
}