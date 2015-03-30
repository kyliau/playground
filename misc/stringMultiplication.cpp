#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

// Given two arbitrary string of numbers, compute the product of the two

string multiplyTwoStrings(const string& num1, const string& num2)
{
  string row1, row2;
  //cout << num1.length() << "  " << num2.length() << endl;
  
  int carry = 0;
  for (int i = num1.length() - 1; i >= 0; i--)
  {
    //cout << "i = " << i << endl;
    int x = num1[i] - '0'; cout << "x = " << x << endl;
    for (int j = num2.length() - 1; j >= 0; j--)
    {
      //cout << "j = " << j << endl;
      int y = num2[j] - '0'; cout << "y = " << y << endl;
      int temp = x * y + carry; cout << "temp = " << temp << endl;
      int val = temp % 10; cout << "val = " << val << endl;
      carry = temp / 10; cout << "carry = " << carry << endl;
      //cout << val;
    }
  }
  if (carry != 0) cout << carry << endl;
  return row1;
}

int main()
{
  string num1, num2;
  cout << "Enter the first number : ";
  cin >> num1;
  cout << "Enter the second number: ";
  cin >> num2;
  multiplyTwoStrings(num1, num2);
  //cout << num1 << " x " << num2 << " = " << multiplyTwoStrings(num1, num2)
  //     << endl;
}
