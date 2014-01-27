/* Written by Maajid Nazrulla.
Last updated 24/10/2013. Project Euler Problem 2.
*/

#include <stdio.h>
#include <stdlib.h>

//global int array holding fibonacci numbers
int* A = (int *) calloc(1000, sizeof(int));

void usage() {
	printf("Please rerun the program with a number as an input.\n");
	printf("The program computes the sum of all even Fibonacci numbers\n");
	printf("up to Fibonacci numbers of value equal to the supplied number.\n");
	printf("Be advised that the values are limited to 32 bit integers, so\n");
	printf("numbers on the order of 2^31 may cause segmentation faults--larger\n");
	printf("numbers certainly will.\n");
}
	
int fibonacci(int n) {
	int a = 1;
	int b = 1;
	if (A[n] != 0) {
		return A[n];
	}
	
	else {
		for (int i = 3; i <= n; i++) {
			int c = a + b;
			a = b;
			b = c;
			A[i] = b;
		}
		return b;
	}
} 

int fibsum(int i, int n, int sum) {
	if (fibonacci(i) % 2 != 0) {
		return fibsum(i+1, n, sum);
	}
	if (fibonacci(i) > n) {
		return sum;
	}
	if (fibonacci(i) % 2 == 0) {
		sum += fibonacci(i);
		return fibsum(i+1, n, sum);
	}
}
	
int main(int argc, char* argv[]) {
	if (argc != 2) {
		usage();
		return 0;
	}
	int limit = atoi(argv[1]); //parse the number passed in
	printf("The limit is: %d.\n", limit);
	int sum = fibsum(0, limit, 0);
	printf("The sum of the even valued terms of the Fibonacci sequence\n");
	printf("whose values do not exceed %d is %d.\n", limit, sum);
	return 0;
}
