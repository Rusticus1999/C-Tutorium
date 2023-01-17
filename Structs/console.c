#include<stdio.h>


int main()
{

int x, y;
while(1)
{
	printf("x mal y:");
	scanf("%d%d", &x, &y);
	for(int i = 0; i<y; i++)
	{
		printf("\n");
		for(int j = 0; j<x; j++)
		{
			printf("#");
		}
	}
}



return 0;
}
