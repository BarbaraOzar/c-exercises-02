/*
 * exe01.c
 *
 * Created: 2018-04-12 09:28:46
 * Author : Barbara
 */ 

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int power(int *x, int *y);
void multi_swap(int *x, int *y, int *z);
int sum_arrays(int *a, int *b, int size_a, int size_b);
int* combine_arrays(int *a, int *b, int size_a, int size_b);
void swap_values(int *x, int *y);

int main(void)
{
	int a = 3, b = 2, c = 1;
	int d[5] = {6, 2, 1, 4, 3}, e[4] = {3, 2, 3, 1};
	int *combined_array;
	int i, combined_array_size = sizeof(d) / sizeof(d[0]) + sizeof(e) / sizeof(e[0]);

	printf("value of a = %d, value of b = %d, value of c = %d\n", a, b, c);
	printf("a to the power of b = %d\n", power(&a, &b));
	multi_swap(&a, &b, &c);
	printf("value of a = %d, value of b = %d, value of c = %d\n", a, b, c);

	printf("total of both arrays = %d\n", sum_arrays(&d[0], &e[0], sizeof(d) / sizeof(d[0]), sizeof(e) / sizeof(e[0])));

	combined_array = combine_arrays(&d[0], &e[0], sizeof(d) / sizeof(d[0]), sizeof(e) / sizeof(e[0]));

	printf("combined array: ");

	for(i = 0; i < combined_array_size; i++)
	{
		printf("%d, ", *(combined_array+i));
	}
}

int power(int *x, int *y)
{
	return pow(*x, *y);
}

void multi_swap(int *x, int *y, int *z)
{
	int temp = *x;
	*x = *y;
	*y = *z;
	*z = temp;
}

int sum_arrays(int *a, int *b, int size_a, int size_b)
{
	int total = 0, i;
	int *pa = a, *pb = b;

	for(i = 0; i < size_a; i++)
	{
		total += *pa++;
	}

	for(i = 0; i < size_b; i++)
	{
		total += *pb++;
	}

	return total;
}

int* combine_arrays(int *a, int *b, int size_a, int size_b)
{
	int *array_p;
	int array_size = size_a+size_b;
	array_p = calloc(array_size, sizeof(int));
	int *array_beginning_p = array_p;
	int i, j;

	for(i = 0; i < size_a; i++)	// copy first array to combined array
	{
		*(array_p++) = *(a++);
	}

	for(i = 0; i < size_b; i++)	// copy second array to combined array
	{
		*(array_p++) = *(b++);
	}

	array_p = array_beginning_p;

	for(i = 0; i < array_size; i++)	// sort combined array
	{
		int *min = &array_p[i];
		for(j = i+1; j < array_size; j++)	// find minimum integer in the remainder of the combined array and swap it with integer at i
		{
			if(array_p[j] < *min)
			{
				min = &array_p[j];
			}
			swap_values(min, &array_p[i]);
		}
	}

	array_p = array_beginning_p;
	return array_p;
}

void swap_values(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}