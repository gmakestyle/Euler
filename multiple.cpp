/* Written by Maajid Nazrulla.
Last updated 24/10/2013. Project Euler Problem 1.
*/

#include <stdio.h>
#include <stdlib.h>

void usage() {
	printf("Please rerun the program with a number as an input.\n");
	printf("The program computes the sum of all multiples of 3 or 5 below the supplied number.");
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		usage();
		return 0;
	}
	
	int limit = atoi(argv[1]); //parse the number passed in
	printf("The limit is: %d.\n", limit);
	int sum = 0;
	
	for (int i = 0; i < limit; i++) {
		if (i % 3 ==0 || i % 5 == 0) {
			sum += i;
		}
	}
	printf("The number of multiples of 3 or 5 less than %d is %d\n", limit, sum);

	return 0;
}
