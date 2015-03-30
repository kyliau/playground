#include <iostream>
using namespace std;

// find three numbers in an array that sum to value N
// if such numbers exist, print the numbers and return true
// else return false

// ----------------------------------------------------

// A much better O(N^2) solution
// vector A must be sorted
bool find2SumToN(const vector<int>& A, int N) {
  int left = 0, right = A.size() - 1;
  while (left <= right) {
    int sum = A[left] + A[right];
    if (sum == N) {
      return true;
    } else if (sum < N) {
      ++left;
    } else { // sum > N
      --right;
    }
  }
  return false;
}

bool find3SumToN(const vector<int>& A, int sum) {
  sort(A.begin(), A.end());
  for (int a : A) {
    if (find2SumToN(A, sum - a)) {
      return true;
    }
  }
  return false;
}

// ----------------------------------------------------

// Brute force O(N^3) solution
bool find3SumToN(const double input[], unsigned int size, double N)
{
  //int count = 0;
  for (int i = 0; i < size-2; i++)
  {
    for (int j = i+1; j < size-1; j++)
    {
      for (int k = j+1; k < size; k++)
      {
        //count++;
        if (input[i] + input[j] + input[k] == N)
        {
          cout << input[i] << " + " << input[j] << " + " << input[k] 
               << " = " << N << endl;
          return true;
        }
      }
    }
  }
  //cout << "count = " << count << endl;
  return false;
}

int main()
{
  double N = 0;
  double input[] = { 3, 2, 7, 18, 6, 0, 10, 5, -1, 9 };
  cout << "Enter value for N: ";
  while (cin >> N)
  {
    bool result = find3SumToN(input, 10, N);
    if (!result)
    {
      cout << "There are no three numbers that sum to N = " << N << endl;
    }
    cout << "Enter value for N: ";
  }
  return 0;
}
