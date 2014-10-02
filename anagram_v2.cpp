#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

bool anagram(const string& s1, const string& s2) {

  if (s1.length() != s2.length()) return false;

  unordered_map<char, int> hash;

  for (char c : s1) {
    hash[c]++;
  }

  for (char c : s2) {
    if (--hash[c] < 0) return false;
  }

  for (const auto& p : hash) {
    if (p.second != 0) return false;
  }

  return true;

}

int main() {
  while (1) {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;
    string result = anagram(s1, s2) ? " are " : " are not ";
    cout << s1 << " and " << s2 << result << "anagrams." << endl;
  }
  return 0;
}
