#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

unsigned ctoi(char c) {
  return c - '0';
}

string multiplyByDigit(const string& a, char digit) {
  int x = ctoi(digit);
  if (x == 0) return string("0");
  if (x == 1) return a;
  string result;
  unsigned carry = 0;
  for (int i = a.length() - 1; i >= 0; i--) {
    int b = carry + ctoi(a[i]) * x;
    carry = b / 10;
    result = to_string(b % 10) + result;
  }
  if (carry != 0) {
    result = to_string(carry) + result;
  }
  return result;
}

string addTwoStrings(const string& a, const string& b) {
  string result;
  int i = a.length() - 1;
  int j = b.length() - 1;
  int k = i > j ? i + 1 : j + 1;
  unsigned carry = 0;

  while (k--) {
    int aVal = i >= 0 ? ctoi(a[i--]) : 0;
    int bVal = j >= 0 ? ctoi(b[j--]) : 0;
    int temp = aVal + bVal + carry;
    carry = temp / 10;
    result = to_string(temp % 10) + result;
  }

  if (carry != 0) {
    result = to_string(carry) + result;
  }

  return result;
}


string multiply(const string& a, const string& b) {
  string result("0");
  for (int i = b.length() - 1; i >= 0; i--) {
    string temp = multiplyByDigit(a, b[i]) + string(b.length() - i - 1, '0');
    result = addTwoStrings(temp, result);
  }
  return result;
}

int main() {
  cout << multiplyByDigit("999", '9') << endl;
  cout << multiplyByDigit("888", '9') << endl;
  cout << addTwoStrings("999", "999") << endl;
  cout << addTwoStrings("999", "2") << endl;
  cout << addTwoStrings("2", "999") << endl;
  cout << multiply("9", "999") << endl;
  cout << multiply("12345", "987654321") << endl;
  cout << multiply("123", "0") << endl;
  cout << multiply("123456789", "9876543210") << endl;
  while(1) {
    cout << "Enter two numbers: ";
    string x, y;
    cin >> x >> y;
    cout << x << " x " << y << " = " << multiply(x, y) << endl;
  }

  return 0;
}
