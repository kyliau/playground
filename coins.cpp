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

//double denominations[] { 100, 50, 20, 10, 5, 1, 0.25, 0.10, 0.05, 0.01 };
unsigned int denominations[] { 1, 5, 10, 25, 100, 500, 1000, 2000, 5000, 10000 };
const unsigned int DENOM_LEN = 10;
const unsigned int MAX_VAL = 100000;
unsigned int ways[MAX_VAL / 5][DENOM_LEN];

unsigned int getNumWays(unsigned int amount, unsigned int indexOfMaxDenom) {
  if (amount == 0) {
    return 1;
  }
  return ways[amount / 5][indexOfMaxDenom];
}

void printWays(unsigned int arbVal) {
  printf(" Amount |  0.01  |  0.05  |  0.10  |  0.25  |  1.00  |  5.00  |  10.00 |  20.00 |  50.00 | 100.00 \n");
  printf("--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------\n");
  for (int i = 0; i <= arbVal / 5; ++i) {
    printf(" %6d ", i * 5); 
    unsigned int numWays = 0;
    for (int j = 0; j < DENOM_LEN; ++j) {
      numWays += ways[i][j];
      printf("| %6d ", ways[i][j]);
    }
    printf("\n");
  }
}

unsigned int sumOfRow(unsigned int row) {
  unsigned int sum = 0;
  for (int i = 0; i < DENOM_LEN; i++) {
    sum += ways[row][i];
  }
  return sum;
}

void findWays(unsigned int arbVal) {
  for (unsigned int amount = 0; amount <= arbVal; amount += 5) {
    for (unsigned int denomIndex = 1; denomIndex < DENOM_LEN; denomIndex++) {
      unsigned int denom = denominations[denomIndex];
      if (amount >= denominations[denomIndex]) {
        ways[amount / 5][denomIndex] = 1 + getNumWays(amount - denom, denomIndex - 1);
        cout << "ways[" << amount / 5 << "][" << denomIndex << "] = " << getNumWays(amount - denom, denomIndex) << endl;
      }
    }
  }
}

int main() {
  ways[0][0] = 1;
  double input;
  cout << "Enter an arbitrary value: $";
  cin >> input;
  findWays(input * 100);
  printWays(input * 100);
  return 0;
}
