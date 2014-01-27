/* Written by Maajid Nazrulla.
Last updated 26/1/2014. Project Euler Problem 54.

This program takes a text file as input that provides,
line by line, a set of 10 poker cards. The first five
belong to player 1, and the second five belong to player 2.
Each line is considered one head-to-head matchup. The program
will then print the number of head-to-head matchups that
were won by player 1. The winrate, total number of matches,
and other basic statistics are also provided.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>

//Global int array holding booleans for each head-to-head.
//If an entry is true, then player 1 won that matchup.
int* A = (int *) calloc(1000, sizeof(int));

void usage() {
  printf("Please rerun the program with a text file as an input.\n");
  printf("The input text file should be comprised of lines that \n");
  printf("contain, in order, 5 cards for player 1 and 5 cards for \n");
  printf("player 2. The cards should be space delimited and of the form \n");
  printf(" 'VS' where 'V' is the value of the card from 2 to A and \n");
  printf(" 'S' is the suit of the card. The set of possible values for V is: \n");
  printf("{2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A} \n");
  printf("The set of possible suits for S is:\n");
  printf("{H, D, C, S}.\n");
  printf("An example of a valid line is:\n");
  printf("2S 5S 5D 6H 9C 3D 7H KC 3C 4H\n");
  printf("In this example player 1 wins with a pair of 5s beating player 2's\n");
  printf("pair of 3s.");
}

class Card {
public:
  char value, suit;
};

int same_value(card c1, card c2) {
  return (c1.value == c2.value);
}

int same_suit(card c1, card c2) {
  return (c1.suit == c1.suit);
}

class Hand {
  vector<Card> cards;
public:
  void insert_card(card c) {
    cards.push_back(c);
  }
  int high;
  int one_pair;
  int two_pair;
  int three_kind;
  int straight;
  int flush;
  int full_house;
  int four_kind;
  card assoc_card;
  char second_assoc_card;

  void pairs() {
    for (int i = 0; i < 4; i++) {
      for (int j = i+1; j < 5; j++) {
	if (same_value(cards[i], cards[j]) && !one_pair) {
	  one_pair = 1;
	  assoc_card = cards[i];
	}
	else if (same_value(cards[i], cards[j]) && one_pair) {
	  if (same_value(assoc_card, cards[i])) {
	    three_kind = 1;
	  }
	  else {
	    two_pair = 1;
	    second_assoc_card = cards[i];
	  }
	  one_pair = 0;
	}
	else if (same_value(cards[i], cards[j]) && two_pair) {
	  full_house = 1;
	  two_pair = 0;
	  if (same_value(second_assoc_card, cards[i])) {
	    second_assoc_card = assoc_card;
	    assoc_card = cards[i];
	    }
	}
	else if (same_value(cards[i], cards[j]) && three_kind) {
	  if (same_value(assoc_card, cards[i])) {
	    four_kind = 1;
	  }
	  else {
	    full_house = 1;
	    second_assoc_card = cards[i];
	  }
	  three_kind = 0;
	}
      }
    }
  }

  void is_flush() {
    flush = 1;
    for (int i = 1; i < 5; i++) {
      flush = (cards[0] == cards[i]) && flush;
    }
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
