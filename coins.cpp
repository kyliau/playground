#include <iostream>
#include <stdio.h>
using namespace std;

/* 
 * Question
 * Assume the US dollar is available in denominations of 
 * $100, $50, $20, $10, $5, $1, $0.25, $0.10, $0.05 and $0.01. 
 * Write a function to return the number of different ways to exactly 
 * represent an arbitrary value less than $1,000.00 using any number 
 * or combination of these denominations.
 */

// DO ALL CALCULATIONS IN CENTS

unsigned int denominations[] = { 1, 5, 10, 25, 100, 500, 1000, 2000, 5000, 10000 };
const unsigned int DENOM_LEN = 10;
const unsigned int MAX_VAL = 100000;
unsigned long int ways[MAX_VAL / 5][DENOM_LEN - 1];

// returns the number of ways to represent 'amount' using denominations 
// up to (and including) denominations[indexOfMaxDenom]
unsigned long int getNumWays(unsigned int amount, unsigned int indexOfMaxDenom) {
  if (amount == 0 || indexOfMaxDenom == 0) {
    return 1;
  }
  return ways[amount / 5][indexOfMaxDenom - 1];
}

void printWays(unsigned int arbVal) {
  printf(" Amount |  0.01  |  0.05  |  0.10  |  0.25  |  1.00  |  5.00  |  10.00 |  20.00 |  50.00 | 100.00 \n");
  printf("--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------\n");
  for (unsigned int i = 0; i <= arbVal / 5; ++i) {
    printf(" %6d ", i * 5); 
    //unsigned int numWays = 0;
    for (int j = 0; j < DENOM_LEN - 1; ++j) {
      //numWays += ways[i][j];
      //printf("| %6d ", ways[i][j]);
      cout << "| " << ways[i][j] << " ";
    }
    printf("\n");
  }
}

void findWays(unsigned int arbVal) {
  for (unsigned int amount = 5; amount <= arbVal; amount += 5) {
    unsigned long int numWays = 1;
    for (unsigned int denomIndex = 1; denomIndex < DENOM_LEN; denomIndex++) {
      unsigned int denom = denominations[denomIndex];
      if (denom <= amount) {
        numWays += getNumWays(amount - denom, denomIndex);
      }
      ways[amount / 5][denomIndex - 1] = numWays;
    }
  }
}

int main() {
  ways[0][0] = 1;   // this is the base case
  double input = 0;
  while (true) {
    cout << "Enter an arbitrary value: $";
    cin >> input;
    unsigned int inputInCents = input * 100;
    findWays(inputInCents);
    cout << "Number of ways = " << ways[inputInCents / 5][DENOM_LEN - 2] << endl << endl; 
    printWays(inputInCents);
  }
  return 0;
}
