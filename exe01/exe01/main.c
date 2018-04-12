/*
 * exe01.c
 *
 * Created: 2018-04-12 09:28:46
 * Author : Barbara
 */ 

#include <math.h>
#include <stdio.h>

int power(int *x, int *y);
void multi_swap(int *x, int *y, int *z);
int sum_arrays(int *a, int *b, int size_a, int size_b);


int main(void)
{
	int a = 3, b = 2, c = 1;
	
	printf("value of a = %d, value of b = %d, value of c = %d\n", a, b, c);
    printf("a to the power of b = %d\n", power(&a, &b));
    multi_swap(&a, &b, &c);
    printf("value of a = %d, value of b = %d, value of c = %d\n", a, b, c);
    
    int d[4] = {1, 2, 3, 4}, e[4] = {3, 2, 3, 1};
    printf("total of both arrays = %d\n", sum_arrays(&d, &e, 4, 4));
    	
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
    int total;
    int *pa = a, *pb = b;
    
    for(int i = 0; i < size_a; i++)
    {
        total += *pa;
        pa++;
    }
    
    for(int i = 0; i < size_b; i++)
    {
        total += *pb;
        pb++;
    }
    
    return total;
}
