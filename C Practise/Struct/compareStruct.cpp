#include<stdio.h>


struct A {
	int a;
	int b;
	int c;
	int d;
};
struct B {
	char a;
	char b;
	char c;
	char d;
};

struct C {
	char a;
	int b;
	char c;
	int d;
};




int main(int argc, char* argv[]) {




{
printf("==========全体成员为int=============\n");

		struct A i;
		char s[] = "a";

	printf("sizeof(A)=%d\n", sizeof(A));
	printf("sizeof(%c.a)=%d\n",*s,sizeof(i.a));
	printf("sizeof(%c.b)=%d\n",*s,sizeof(i.b));
	printf("sizeof(%c.c)=%d\n",*s,sizeof(i.c));
	printf("sizeof(%c.d)=%d\n",*s,sizeof(i.d));
	printf("&%c.a=%p\t", *s, &i.a);
	printf("&%c.b=%p\t", *s, &(i.b));
	printf("&%c.c=%p\t", *s, &(i.c));
	printf("&%c.d=%p\t", *s, &(i.d));
	printf("\n");
	printf("两成员地址之差：");
	printf("b-a=%d\t", &i.b - &i.a);
	printf("c-b=%d\t", &(i.c) - &(i.b));
	printf("d-c=%d\t", &(i.d) - &(i.c));
	printf("\n");
}
{
printf("==========全体成员为double=============\n");
	struct B i;
	char s[] = "b";
	printf("sizeof(B)=%d\n", sizeof(B));
	printf("sizeof(%c.a)=%d\n", *s, sizeof(i.a));
	printf("sizeof(%c.b)=%d\n", *s, sizeof(i.b));
	printf("sizeof(%c.c)=%d\n", *s, sizeof(i.c));
	printf("sizeof(%c.d)=%d\n", *s, sizeof(i.d));
	printf("&%c.a=%p\t", *s, &(i.a));
	printf("&%c.b=%p\t", *s, &(i.b));
	printf("&%c.c=%p\t", *s, &(i.c));
	printf("&%c.d=%p\t", *s, &(i.d));
	printf("\n");
	printf("两成员地址之差：");
	printf("b-a=%d\t", &i.b - &i.a);
	printf("c-b=%d\t", &(i.c) - &(i.b));
	printf("d-c=%d\t", &(i.d) - &(i.c));
	printf("\n");
}
{
	printf("==========全体成员为混合=============\n");
	struct C i;
	char s[] = "c";
	printf("sizeof(C)=%d\n", sizeof(C));
	printf("sizeof(%c.a)=%d\n", *s, sizeof(i.a));
	printf("sizeof(%c.b)=%d\n", *s, sizeof(i.b));
	printf("sizeof(%c.c)=%d\n", *s, sizeof(i.c));
	printf("sizeof(%c.d)=%d\n", *s, sizeof(i.d));
	printf("&%c.a=%p\t", *s, &(i.a));
	printf("&%c.b=%p\t", *s, &(i.b));
	printf("&%c.c=%p\t", *s, &(i.c));
	printf("&%c.d=%p\t", *s, &(i.d));
	printf("\n");

}

	
}
	
