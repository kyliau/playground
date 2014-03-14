#include <iostream>
using namespace std;

// a small program to recursively solve the Tower of Hanoi problem

void moveDisk(unsigned int n, char source, char temp, char dest, int& count)
{
  if (n == 1)
  {
    cout << "move disk from " << source << " to " << dest << endl;
    count++;
  }
  else
  {
    moveDisk(n-1, source, dest, temp, count);
    //moveDisk(1, source, temp, dest, count);
    cout << "move disk from " << source << " to " << dest << endl;
    count++;
    moveDisk(n-1, temp, source, dest, count);
  }
}

int TowerOfHanoi(unsigned int n)
{
  int numOfMoves = 0;
  moveDisk(n, 'A', 'B', 'C', numOfMoves);
  return numOfMoves;
}

int main()
{
  cout << "Enter number of disks to solve: ";
  unsigned int n;
  cin >> n;
  int numOfMoves = TowerOfHanoi(n);
  cout << numOfMoves << " moves required to solve Tower of Hanoi with " << n
       << " disks." << endl;
       
  // the number of moves is given by the recurrence relation
  // T(n) = 2T(n-1) + 1
  // this solves to 2^n - 1
  // the runtime is exponential in n
  
  return 0;
}
