#include <iostream>
#include <string>
#include <vector>
using namespace std;

// generate all possible combinations of a string
// for example: given a string "abc"
// output:
// a  ab  abc ac
// b  bc
// c

vector<string> combination(string s) {

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
  result.push_back(string(1,c));
  for (string& s2 : combination(s)) {
    result.push_back(s2);
    s2.push_back(c);
    result.push_back(s2);
  }

  return result;
}
  
int main() {
  for (const string& s : combination("abcd")) {
    cout << s << endl;
  }
  return 0;
}
    
