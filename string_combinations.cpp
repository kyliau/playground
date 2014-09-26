#include <iostream>
#include <string>
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
  s.pop();
  result.push_back(c);
  for (string& s2 : combination(s)) {
    result.push_back(s2);
    result.push_back(s2.push_back(c));
  }
  
}
  
int main() {
  for (const string& s : combination("abcd")) {
    cout << s << endl;
  }
  return 0;
}
    
