#include <iostream>
#include <string>
using namespace std;

int atoi(const char* s) {
  int result = 0;
  bool negative = false;
  if (*s == '-') {
    negative = true;
    s++;
  }
  while (*s) {
    result = result * 10 + (*s - '0');
    s++;
  }
  return negative ? -result : result;
}

int main() {
  while (1) {
    cout << "Enter a number: ";
    string s;
    cin >> s;
    cout << atoi(s.data()) << endl;
  }
  return 0;
}
