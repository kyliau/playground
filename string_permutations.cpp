#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Print all possible permutations of a string
// For example: Given the string 'abc', print
// abc bac cab
// acb bca cba

// return a vector of all possible permutations of s
vector<string> string_permutations(string s) {

  vector<string> result;
  
  if (s.length() == 0) {
    return result;
  }
  
  if (s.length() == 1) {
    result.push_back(s);
    return result;
  }
  
  char c = s.back();
  s.pop_back();
  for (const string& p : string_permutations(s)) {
    // put c in every possible location
    for (int i = 0; i < p.size() + 1; i++) {
      result.push_back(p.substr(0, i) + c + p.substr(i));
    }
  }
  
  return result;
}


int main() {
  for (const string& p : string_permutations("abcd")) {
    cout << p << endl;
  }
  return 0;
}
