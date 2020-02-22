#include <stdio.h>
#include <stdlib.h>

int main() {
	char a[5];

	char *endptr;
	char buff[10];
	long int value;
	int count = 0;

	printf("Enter int: ");
	
	while (count != sizeof(a)) {
		fgets(buff, sizeof(buff), stdin);
		value = strtol(buff, &endptr, 10);
		if (((*endptr < 48) || (*endptr > 57)) && (*endptr != 10)) {
			printf("Invalid input\n");
			count--;
		}
			
		printf("Enter int: ");
		count++;
	}
	
	for (int i = 0; i < sizeof(a); i++) {
		a[i] = value;
	}
}
