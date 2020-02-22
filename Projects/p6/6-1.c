#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define N 4

typedef int array_t[N][N];

int dim() {
    return N;
}

void f(array_t a, int x, int y)
{
    for (int i = 0; i < dim(); ++i) {
	for (int j = 0; j < dim(); ++j) {
	    a[i][j] = i * x * y + j;
	}
    }
}

void f2(array_t a, int x, int y)
{
    /* Perform the initial multiplication of x and y
       no need for it to be done within the double for loop */
    int sum = x * y;

    /* Assign the function call of dim() to a variable
       Unecessary to call it in the condition */
    int length = dim();

    for (int i = 0; i < length; ++i) {
	/* Scale the x,y value by index to perform the operation
	   before entering the inner for loop */
	int scale = sum * i;

	for (int j = 0; j < length; ++j) {
	    a[i][j] = scale + j;
	}
    }
}

void printer(array_t a)
{
    int len = dim();
    printf("{");

    for (int i = 0; i < len; ++i) {
	printf("{");

	for (int j = 0; j < len; ++j) {
	    printf("%d, ", a[i][j]);
	}
	
	printf("}");
    }

    printf("}\n");
}

int main()
{
    array_t a = {{0, 1, 2, 3}, {2, 3, 4, 5}, {4, 5, 6, 7}, {6, 7, 8, 9}};
    array_t b = {{0, 1, 2, 3}, {2, 3, 4, 5}, {4, 5, 6, 7}, {6, 7, 8, 9}};

    printf("Initial array\n");
    printer(a);

    f(a, 1, 2);
    printf("\nArray after passing through unoptimized function 'f'\n");
    printer(a);

    f2(b, 1, 2);
    printf("\nArray after passing through optimized function 'f2'\n");
    printer(b);

    return 0;
}
