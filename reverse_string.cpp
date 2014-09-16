#include <iostream>
using namespace std;

char* reverse_string(char* p) {
  char* head = p;
  char* tail = p;
  
  // first find the null terminating character
  while (*tail) {
    tail++;
  }
  tail--;
  
  // swap left most and right most pointer
  while (tail > p) {
    char temp = *p;
    *p++ = *tail;
    *tail-- = temp;
  }
  return head;
}

int main() {
  char str1[] = "Hello World!";
  cout << str1 << endl;
  cout << reverse_string(str1) << endl;
  char str2[] = "Hello World";
  cout << str2 << endl;
  cout << reverse_string(str2) << endl;
  return 0;
}
