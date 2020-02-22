#include <stdio.h>
#include <time.h>

#define N 4

typedef int array_t[N][N];

void inner(float *u, float *v, int length, float *dest)
{
    int i;
    float sum = 0.0f;

    for (i = 0; i < length; ++i) {
	sum += u[i] * v[i];	// sum = sum + u[i] * v[i];
    }

    *dest = sum;
}

void inner2(float *u, float *v, int length, float *dest)
{
    int i;
    float sum = 0.0f;

    /* Four parallel acumulators */
    float x, y, w, z;

    /* Four-way loop unrolling */
    for (i = 0; i < length; i+=4) {
	x += u[i] * v[i];
	y += u[i+1] * v[i+1];
	w += u[i+2] * v[i+2];
	z += u[i+3] * v[i+3];
    }

    /* Finish any remaining elements */
    for (; i < length; i++) {
	x += u[i] * v[i];
    }

    *dest = x + y + w + z;
}

int main()
{
    /* Input various length sizes (10, 1000, 1000000) to test speedup */
    int length = 1000000;

    /* Create two float arrays with a for loop and input the values into the functions */
    float a[length];
    float b[length];

    for (int i = 0; i < length; i++) {
	a[i] = i;
	b[i] = i;
    }

    float *u = a;
    float *v = b;
    float d = 0.0f;
    float *dest = &d;

    /* Timer code taken from the example provided by Trevor */
    clock_t start = 0, end = 0;
    double total;
    int i;

    printf("Length size = %d\n", length);

    /* Running and timing the inner function (original function) */ 
    start = clock();
    printf("\nStarting the inner function, start = %ld\n", start);

    inner(u, v, length, dest);
    printf("inner function sum = %f\n", *dest);

    end = clock();
    printf("Ending the inner function, end = %ld\n", end);

    total = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", total);

    /* Run times:
	- length = 10		--->	0.000022
	- length = 1000		--->	0.000039
	- length = 1000000	--->	0.003178
    */


    /* Running and timing the inner2 function (loop unrolled function) */
    start = clock();
    printf("\nStarting the inner2 function, start = %ld\n", start);

    inner2(u, v, length, dest);
    printf("inner2 function sum = %f\n", *dest);

    end = clock();
    printf("Ending the inner2 function, end = %ld\n", end);

    total = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n\n", total);

    /* Run times:
	- length = 10		--->	0.000017
	- length = 1000		--->	0.000026
	- length = 1000000	--->	0.001662
    */
}
