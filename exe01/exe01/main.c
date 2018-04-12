/*
 * exe01.c
 *
 * Created: 2018-04-12 09:28:46
 * Author : Dell
 */ 

#include <math.h>
#include <stdio.h>

int power(int *x, int *y);
void multiSwap(int *x, int *y, int *z);

int main(void)
{
	int a = 3, b = 2, c = 1;
	
	printf("value of a = %d, value of b = %d, value of c = %d\n", a, b, c);
    printf("a to the power of b = %d\n", power(&a, &b));
    multiSwap(&a, &b, &c);
    printf("value of a = %d, value of b = %d, value of c = %d\n", a, b, c);
    	
}

int power(int *x, int *y)
{
	return pow(*x, *y);
}

void multiSwap(int *x, int *y, int *z) 
{
	int temp = *x;
	*x = *y;
	*y = *z;
	*z = temp;
}