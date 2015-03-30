#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

// given two strings, write a function that returns true if they are anagrams
// false otherwise

// best implementation so far
bool anagram(const string& s1, const string& s2) {

  if (s1.length() != s2.length()) return false;

  unordered_map<char, int> hash;

  for (char c : s1) {
    hash[c]++;
  }

  for (char c : s2) {
    if (--hash[c] < 0) return false;
  }

  // this is not needed because of the length check above
  /*
  for (const auto& p : hash) {
    if (p.second != 0) return false;
  }
  */

  return true;

}

// assume both words contain alphabets [a-z][A-Z] and spaces only
// implement without using hash table
bool checkIsAnagram(const string& word1, const string& word2)
{
  if (word1.length() != word2.length()) return false;

  int count[26] = { 0 };
  const string* words[] = { &word1, &word2 };
  
  for (int i = 0; i < 2; i++)
  {
    for (unsigned int j = 0; j < words[i]->length(); j++)
    {
      char c = words[i]->at(j);
      if (c == ' ') continue; // ignore spaces
      int index = c < 'a' ? c - 'A' : c - 'a';
      if (i == 0) count[index]++;
      else if (--count[index] < 0) return false;
    }
  }
  
  /* this check is not needed because of the length check above
  for (int i = 0; i < 26; i++)
  {
    if (count[i] != 0) return false;
  }
  */

  return true;
}

int main() {
  while (1) {
    string s1, s2;
    cout << "Enter first string: ";
    cin.getline(s1);
    cout << "Enter second string: ";
    cin.getline(s2);
    string result = anagram(s1, s2) ? " are " : " are not ";
    cout << s1 << " and " << s2 << result << "anagrams." << endl;
  }
  return 0;
}

