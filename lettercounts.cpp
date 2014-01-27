/* Written by Maajid Nazrulla.
Last updated 26/1/2014. Project Euler Problem 17.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//global int array holding number of letters in each number from 1 to 1000
int* A = (int *) calloc(1000, sizeof(int));

void usage() {
	printf("Please rerun the program with a number as an input.\n");
	printf("The program computes the number of letters in the British usage \n");
	printf("of the inputted number.\n");
}
	
//Converts the number from an int into an English string
int calculate(int n) {
  int ones = n % 10;
  int tens = 0;
  int hundreds = 0;
  int thousands = 0;
  int sum = 0;
  char thousand[12];
  char hund[11];
  char one[7];
  char ten[10];
  char tot[28];
  int an = 0;

  if (n >= 10) {
    tens = (n / 10) % 10;
  }
  if (n >= 100) {
    hundreds = (n / 100) % 10;
  }
  if (n >= 1000) {
    thousands = (n / 1000) % 10;
  }

  if (thousands != 0) {
    strcpy(thousand, "onethousand");
  }

  switch (hundreds) {
  case 1 :
    strcpy(hund, "onehundred");
    break;
  case 2 :
    strcpy(hund,"twohundred");
    break;
  case 3 :
    strcpy(hund,"threehundred");
    break;
  case 4 :
    strcpy(hund,"fourhundred");
    break;
  case 5 :
    strcpy(hund,"fivehundred");
    break;
  case 6 :
    strcpy(hund, "sixhundred");
    break;
  case 7 :
    strcpy(hund, "sevenhundred");
    break;
  case 8 :
    strcpy(hund, "eighthundred");
    break;
  case 9 :
    strcpy(hund, "ninehundred");
    break;
  default :
    break;
  }
  if (hundreds != 0 && (tens != 0 || ones != 0)) {
    an = 1;
    sum += 3; //for "and"
  }
  switch (tens) {
  case 1 :
    switch (ones) {
    case 0 :
      strcpy(ten, "ten");
      break;
    case 1 :
      strcpy(ten, "eleven");
      break;
    case 2 :
      strcpy(ten, "twelve");
      break;
    case 3 :
      strcpy(ten, "thirteen");
      break;
    case 4 :
      strcpy(ten, "fourteen");
      break;
    case 5 :
      strcpy(ten, "fifteen");
      break;
    case 6 :
      strcpy(ten, "sixteen");
      break;
    case 7 :
      strcpy(ten, "seventeen");
      break;
    case 8 :
      strcpy(ten, "eighteen");
      break;
    case 9 :
      strcpy(ten, "nineteen");
      break;
    }
    break;
  case 2 :
    strcpy(ten, "twenty");
    break;
  case 3 :
    strcpy(ten, "thirty");
    break;
  case 4 :
    strcpy(ten, "forty");
    break;
  case 5 :
    strcpy(ten, "fifty");
    break;
  case 6 :
    strcpy(ten, "sixty");
    break;
  case 7 :
    strcpy(ten, "seventy");
    break;
  case 8 :
    strcpy(ten, "eighty");
    break;
  case 9 :
    strcpy(ten, "ninety");
    break;
  }

  if (tens != 1) {
    switch (ones) {
    case 1 :
      strcpy(one, "one");
      break;
    case 2 :
      strcpy(one, "two");
      break;
    case 3 :
      strcpy(one, "three");
      break;
    case 4 :
      strcpy(one, "four");
      break;
    case 5 :
      strcpy(one, "five");
      break;
    case 6 :
      strcpy(one, "six");
      break;
    case 7 :
      strcpy(one, "seven");
      break;
    case 8 :
      strcpy(one, "eight");
      break;
    case 9 :
      strcpy(one, "nine");
      break;
    }
  }

  if (thousands != 0) {
    sum += strlen(thousand);
  }
  if (hundreds != 0) {
    sum += strlen(hund);
  }
  if (tens != 0) {
    sum += strlen(ten);
    if (n > 10 && n < 20) {
      printf("string is: %s.\n", ten);
    }
    if (tens == 1) {
      ones = 0;
    }
  }
  if (ones != 0) {
    sum += strlen(one);
    if (n > 10) {
      printf("ones: %s\n", one);
    }
  }
  printf("The number of letters in %d is: %d\n", n, sum);
  return sum;
}

void setupArr(int* arr, int max) {
  for (int i = 1; i <= max; i++) {
    arr[i] = calculate(i);
  }
}
    
int calculate_sum(int* arr, int size) {
  int sum = 0;
  for (int i = 1; i <= size; i++) {
    sum += arr[i];
  }
  return sum;
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		usage();
		return 0;
	}
	int limit = atoi(argv[1]); //parse the number passed in
	printf("The number passed in is: %d.\n", limit);
	//setupArr(A, limit); //setup the global array
	//int sum = calculate_sum(A, limit);
	setupArr(A, limit);
	int sum = calculate_sum(A, limit);
	printf("The number of letters in all of the numbers from 1 to %d is %d.\n", limit, sum);
	free(A);
	return 0;
}
