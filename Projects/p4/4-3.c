#include <stdio.h>

/*
The annotations below are based off of the unoptimized version of transpose and naming
conventions provided on the homework.

N is in %rdi, a[i][j] is in %rax, t2 is in %rsi, a[j][i] is in %rdx, t1 is in %rcx

.L3:				// Inner most for loop:
	movq	(%rax), %rcx	// t1 = a[i][j]
	movq	(%rdx), %rsi	// t2 = a[j][i]
	movq	%rsi,	(%rax)	// a[i][j] = t2
	movq	%rcx,	(%rdx)	// a[j][i] = t1
	addq	$8,	%rax	// shift a[i][j] by 8 bits (1 byte)
	addq	$32,	%rdx	// shift a[j][i] by 32 bits (4 bytes)
	cmpq	%r9,	%rax	// compares a[i][j] < i
	jne	.L3		// if < is true, goto .L3

--------------------------------------------------------------------------------------

The annotations below are based off of my optimized version of transpose and naming
conventions.

*t1 is in %rax, *t2 is in rdx, tmp is in %rcx, tmp2 is in %rsi

.L3:				// Inner most for loop:
	movq	(%rax), %rcx	// tmp (temporary holder 1) = *t1
	movq	(%rdx), %rsi	// tmp2 (temporary holder 2) = *t2
	movq	%rsi,	(%rax)	// *t1 = tmp2
	movq	%rcx,	(%rdx)	// *t2 = tmp
	addq	$8,	%rax	// shift t1 by 8 bits (1 byte)
	addq	$32,	%rdx	// shift t2 by 32 bits (4 bytes)
	cmpq	%r9,	%rax	// compares *t1 < i
	jne	.L3		// if < is true, goto .L3
*/

#define N 4
typedef long array_t[N][N];

void transpose(array_t a)
{
    for (long i = 0; i < N; ++i) {
	/* Initialize column and row pointers respectively */
	long *t1 = &a[i][0];	// row
	long *t2 = &a[0][i];	// column

	for (long j = 0; j < i; ++j) {
	    /* Create a temporary holder for the column pointer */
	    long tmp = *t1;
	    /* If I follow the x86-64 code exactly, then there is another
	       variable: long tmp2 = *t2. But I chose to simplify the code
	       by just placing the value of *t2 immediately into *t1.

	       Swap the values of the pointers */
	    *t1 = *t2;
	    *t2 = tmp;
	    /* Shift the pointers */
	    t1 += 1;	// shift column pointer by 4 indicies
	    t2 += 4;	// shift row pointer by 1 index
	}
    }
}

void printer(array_t a)
{
    printf("{");

    for (int i = 0; i < N; ++i) {
        printf("{");

        for (int j = 0; j < N; ++j) {
            printf("%ld, ", a[i][j]);
        }

        printf("}");
    }
    printf("}\n");
}

int main() {
    array_t arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    transpose(arr);
    printer(arr);
    return 0;
}
