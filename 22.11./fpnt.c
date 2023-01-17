#include<stdio.h>

void drawarray(int*, int);
void countingSort(int*, int);


int main()
{
	int t[12] = {1,3,5,2,6,4,7,5,9,7,8,6};
	drawarray(t,12);
	countingSort(t,12);
	printf("\n\n");
	drawarray(t,12);	
	return 0;
}


/*
Aufgabe 1:

*/

void drawarray(int *arr, int s)
{
	for(int i = 0; i < s; i++)
	{
		for(int j = 0; j < arr[i]; j++)
		{
			printf("#");
		}
		printf("\n");
	}
}

void countingSort(int *arr, int s)
{
	//maximum finden
	int max = 0;
	for(int i = 0; i < s; i++)
	{
		max = arr[i]*(arr[i] > max) + max*(arr[i] <= max);//if ohne if
	}
	//Einträge zählen
	int vorkommen[max+1];
	for(int i = 0; i < max; i++) vorkommen[i] = 0;//array leeren
	drawarray(vorkommen,max);
	printf("\n\n");

	for(int i = 0; i < s; i++)
	{
		vorkommen[arr[i]]++;
	}
	drawarray(vorkommen,max);
	printf("\n\n");
	//Sortiert Rekonstruieren
	int vi = 0;
	for(int i = 0; i < s; i++)
	{
		if(vorkommen[vi] > 0)
		{
			arr[i] = vi;
			vorkommen[vi]--;
		}
		else vi++;
	}

}
