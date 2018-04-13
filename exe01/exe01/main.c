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
void swap_values(int *x, int *y);

int combine_arrays(int *a, int *b, int size_a, int size_b)
{
    int c[size_a+size_b];
    int total = 0;
    int *pa = a, *pb = b, *pc = c;
    
    for(int i = 0; i < size_a; i++)
    {
        *pc++ = *pa++;
    }
    
    for(int i = 0; i < size_b; i++)
    {
        *pc++ = *pb++;
    }
    
    pc = c;
    
    int remaining_size = (size_a+size_b)-1;
    
    for(int i = 0; i <= (size_a+size_b); i++)
    {
        pc = c+i;
        printf("value considered: c[i] = %d\n", c[i]);
        int min = *pc;
        for(int j = 0; j <= remaining_size; j++)
        {
            printf("*pc = %d\n", *pc);
            if(*(++pc) < min)
            {
                printf("min = %d\n", min);
                printf("*pc = %d\n", *pc);
                swap_values(min, *pc);
                break;
            }
        }
        printf("i equals %d\n", i);
        printf("value considered after loop: c[i] = %d\n", c[i]);
        remaining_size--;
    }
    
    return &c;
}

void swap_values(int *x, int *y) 
{
    int temp = *x;
	*x = *y;
	*y = temp;
}

int main(void)
{
	int a = 3, b = 2, c = 1;
	
	printf("value of a = %d, value of b = %d, value of c = %d\n", a, b, c);
    printf("a to the power of b = %d\n", power(&a, &b));
    multi_swap(&a, &b, &c);
    printf("value of a = %d, value of b = %d, value of c = %d\n", a, b, c);
    
    int d[4] = {1, 2, 3, 4}, e[4] = {3, 2, 3, 1};
    printf("total of both arrays = %d\n", sum_arrays(&d, &e, sizeof(d) / sizeof(d[0]), 4));
    
    int *g = combine_arrays(&d, &e, 4, 4);
    
    for(int i = 0; i < 8; i++) 
    {
        printf("value no. %d = %d\n", i, g++);
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
    int total;
    int *pa = a, *pb = b;
    
    for(int i = 0; i < size_a; i++)
    {
        total += *pa++;
    }
    
    for(int i = 0; i < size_b; i++)
    {
        total += *pb++;
    }
    
    return total;
}