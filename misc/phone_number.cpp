#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

// Given a number that is not more than 9 digits,
// print out all possible "strings" according to the keypad on the phone
//
//         ABC   DEF
//    1     2     3
//   
//   GHI   JKL   MNO
//    4     5     6
//   
//   PQRS  TUV   WXYZ
//    7     8     9
//
//          0
//
// For example, 
// 10 -> 10
// 12 -> 1A, 1B, 1C
// 23 -> AD, AE, AF, BD, BE, BF, CD, CE, CF
// 2662278 -> comcast, and many others

// input number is a positive integer not more than 9 digits
vector<string> solution(int number) {
  static const unordered_map<int, vector<string>> map {
    {0, {"0"}},
    {1, {"1"}},
    {2, {"A", "B", "C"}},
    {3, {"D", "E", "F"}},
    {4, {"G", "H", "I"}},
    {5, {"J", "K", "L"}},
    {6, {"M", "N", "O"}},
    {7, {"P", "Q", "R", "S"}},
    {8, {"T", "U", "V"}},
    {9, {"W", "X", "Y", "Z"}},
  };

  if (number < 10) {
    return map.at(number);
  }

  vector<string> result;
  int last_digit = number % 10;
  number /= 10;
  const vector<string>& v = map.at(last_digit);
  for (const string& s : solution(number)) {
    for (const string& c : v) {
      result.push_back(s + c);
    }
  }

  return result;
}

int main() {
  while (1) {
    int number;
    cout << "Enter number: ";
    cin >> number;
    for (const string& s : solution(number)) {
      cout << s << endl;
    }
  }
  return 0;
}
