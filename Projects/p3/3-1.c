#include <stdio.h>
#include <stdlib.h>

struct IntArray
{
	int length;
	int *dataPtr;
};

struct IntArray* mallocIntArray(int length)
{
	/* Allocates, initializes and returns a pointer to a new 'struct IntArray' */
	struct IntArray *arrPtr = (struct IntArray *)malloc(sizeof(struct IntArray));
	arrPtr->length = length;
	int *dPtr = (int *)malloc(length * sizeof(int));
	/* Example taken from lab */
	arrPtr->dataPtr = dPtr;
	return arrPtr;
}

void freeIntArray(struct IntArray *arrayPtr)
{
	/* Frees the instance's dataPtr and frees the instance */
	free(arrayPtr->dataPtr);
	free(arrayPtr);
}

void readIntArray(struct IntArray *array)
{
	/* Prompts and reads ints from the user to fill the array */
	/* https://stackoverflow.com/questions/26583717/how-to-scanf-only-integer */
	char *endptr;		// pointer for strtol function
	char buffer[10];	// long int can only be 10 digits long
	long int value;		// hold long int value that is extracted
	int count = 0;
	
	printf("Enter int: ");

	for (int i = 0; i < array->length; i++)
	{
		while (count != array->length)
		{
			fgets(buffer, sizeof(buffer), stdin);
			value = strtol(buffer, &endptr, 10);
			if (((*endptr < 48) || (*endptr > 57)) && (*endptr != 10))
			{
				printf("Invalid input\n");
				count--;
			}
		
			printf("Enter int: ");
			count++;
		}
		
		(array->dataPtr)[i] = value;
	}
}

void swap(int *xp, int *yp)
{
	/* Swaps the int values stored at the xp and yp pointers */
	/* Copied from lecture slides */
	int t0 = *xp;
	int t1 = *yp;
	*xp = t1;
	*yp = t0;
}

void sortIntArray(struct IntArray *array)
{
	/* Sorts the input array in ascending order using Selection Sort by repeatedly
	 * calling 'swap' function as appropriate. */
	int l = array->length;

	for (int i = 0; i < l - 1; i++)
	{
		for (int j = i + 1; j < l; j++)
		{
			int min_ind = i;
			if (array->dataPtr[j] < array->dataPtr[min_ind])
				min_ind = j;
		}
		
		swap(&array->dataPtr[i], &array->dataPtr[j]);
	}
}

void printIntArray(struct IntArray *array)
{
	/* Prints the array (e.g. "[1, 3, 5, 7]") */
	int len = array->length;

	printf("[");
	
	for (int k = 0; k < len; k++)
	{
		if (k == len - 1)
			printf("%d", (array->dataPtr)[k]);
		else
			printf("%d ,", (array->dataPtr)[k]);
	}
	
	printf("]\n");
}

int main()
{
	/* Prompt the user to input a positive int length from the user (print an error
	 * message and prompt again if the input cannot be parsed as a positive int) */
	char s[100];
	char *p;
	int n;

	printf("Enter length: ");

	while (fgets(s, sizeof(s), stdin))
	{
		n = strtol(s, &p, 10);
		if (((*p < 48) || (*p > 57)) && (*p != 10))
		{
			printf("Invalid input\n");
			printf("Enter length: ");
		}	
	}
	

	/* Call 'mallocIntArray' to create an array */
	struct IntArray *array = mallocIntArray(n);

	/* Call 'readIntArray' to prompt the user to fill the array */
	readIntArray(array);
	
	/* Call 'sortIntArray' to sort it */
	sortIntArray(array);
		
	/* Call 'printArray' to print the resulting sorted array */
	printIntArray(array);

	/* Call 'freeIntArray' to free the heap memory used by the array */
	freeIntArray(array);
}
