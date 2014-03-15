#include <iostream>
#include <string>
using namespace std;

// given two strings, write a function that returns true if they are anagrams
// false otherwise

// assume both words contain alphabets [a-z][A-Z] and spaces only
bool checkIsAnagram(const string& word1, const string& word2)
{
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
  
  for (int i = 0; i < 26; i++)
  {
    if (count[i] != 0) return false;
  }
  return true;
}

int main()
{
  string word1, word2;
  cout << "Enter first word: ";
  getline(cin, word1);
  cout << "Enter second word: ";
  getline(cin, word2);
  string isAnagram = checkIsAnagram(word1, word2) ? " are " : " are not ";
  cout << word1 << " and " << word2 << isAnagram << "anagrams" << endl;
}
