#include <stdio.h>

/*
a in %rdi, b in %rsi, result in %rax, mask in %rdx:

loop:				// intial function of long loop
	movq	%rsi,	%rcx	// temporary variable (4th) to hold b
	movl	$1,	%edx	// mask = 1 (32 bit)
	movl	$0,	%eax	// result = 0 (32 bit)
.L2:				// for loop
	testq	%rdx,	%rdx	// test mask
	je	.L4		// if mask = 0 goto .L4
	movq	%rdx,	%r8	// temporary variable (5th) = mask
	andq	%rdi,	%r8	// temp variable (5th) = temp variable (5th) & a
	orq	%r8,	%rax	// result = result | temp variable (5th)
	salq	%cl,	%rdx	// mask = mask << temporary variable (4th) to hold b (8 bits)
	jmp	.L2		// goto .L2
.L4:				// goto return
	ret			// return %rax
*/

long loop (long a, long b)
{
	long result = 0;
	for (long mask = 1; mask != 0; mask <<= (b & 0xff)) {
		result |= (a & mask);
	}

	return result;
}

int main()
{
	loop(1, 5);	// 1
	loop(2, 4);	// 0
	loop(3, 3);	// 1
	loop(4, 2);	// 4
	loop(5, 1);	// 5
}
