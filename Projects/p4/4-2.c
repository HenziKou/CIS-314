#include <stdio.h>

/*
int sum(int from, int to)
{
	int result = 0;
	do {
		result += from;
		++from;
	} while (from <= to);
	
	return result;
}
*/

long sum(long from, long to)
{
	long result = 0;

	// Ensure that argument *from* is in %rdi,
	// argument *to* is in %rsi, *result* is in %rax - do not modify.
	__asm__ ("movq %0, %%rdi # from in rdi;" :: "r" ( from ));
	__asm__ ("movq %0, %%rsi # to in rsi;" :: "r" ( to ));
	__asm__ ("movq %0, %%rax # result in rax;" :: "r" ( result ));
	// Your x86-64 code goes below - commment each instruction...
	//__asm__("movq %rsi, %rax # For example, this sets result = to;");
	__asm__ (".L2: # Do-While loop;");
	__asm__ ("addq %rdi, %rax # result = result + from;");
	__asm__ ("addq $1, %rdi # increment from by 1;");
	__asm__ ("cmpq %rsi, %rdi # compare from : to;");
	__asm__ ("jle .L2 # if <= goto loop;");

	// Ensure that *result* is in %rax for return - do not modify.
	__asm__ ("movq %%rax, %0 #result in rax;" : "=r" ( result ));
	return result;

}

int main()
{
	printf("%ld\n", sum(1, 6));	// 21
	printf("%ld\n", sum(3, 5));	// 12
}

