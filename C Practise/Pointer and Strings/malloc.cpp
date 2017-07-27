/*
动态申请内存（C99之前，ANSI C标准）
1.格式：
		int* a=(int *)malloc(n*sizeof(int));
	malloc()函数定义：
		void* malloc(size_t size);
		从定义可以知道：
			1.向malloc申请的空间的大小是以字节为单位的，固申请前需自己通过n*sizeof()进行类型转换获得自己需要的字节空间。
			2.返回的结果为void*,固需要自己根据需要进行类型转换。
 若自己定义了一个结构体BTNode，则格式如下：
	BTNode* BT=(BTNode* )malloc(n*sizeof(BTNode));
2.申请失败
若果申请失败，则返回0，下面的例子为演示
3.记得用完free()养成良好的习惯
*/


#include<stdio.h>
#include<stdlib.h>


int main(void) {
	void* p;
	int cnt = 0;
	while (p = malloc(100 * 1024 * 1024)) {
		cnt++;
	}
	printf("分配了%d00MB的空间\n", cnt);
	free(p);





	return 0;
}