#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void addTwoStrings(string *result, const string& s1, const string& s2)
{
    result->clear();
    result->reserve(std::max(s1.length(), s2.length()) + 1);
    int carry = 0;
    int i = s1.length() - 1;
    int j = s2.length() - 1;
    while (i >= 0 || j >= 0) {
        int x = i < 0 ? 0 : s1[i--] - '0';
        int y = j < 0 ? 0 : s2[j--] - '0';
        int z = x + y + carry;
        result->push_back('0' + (z % 10));
        carry = z / 10;
    }
    if (carry) {
        result->push_back('1');
    }
    std::reverse(result->begin(), result->end());
}

int main()
{
    string result, s1, s2;
    while (cin >> s1 >> s2) {
        addTwoStrings(&result, s1, s2);
        cout << result << endl;
    }
}
