#include<stdio.h>
#define mode 2

int main(int argc, char *argv[])
{
#if mode == 1
	char a = 34;
	char b = 114;
	printf("a:%d b:%d\n",a,b);
	a = a^b;
	b = a^b;
	a = a^b;
	printf("a:%d b:%d\n",a,b);
#endif
#if mode == 2
int a = 741;
for (int i = 0; i<4; i++){
	a = (a + i) << (~i|1);
}
printf("a:%d\n", a);
#endif
}
