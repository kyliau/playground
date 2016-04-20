#include <iostream>
#include <string>
using namespace std;  

  string addBinary(string a, string b) {
        auto aIt = a.crbegin();
        auto bIt = b.crbegin();
        int carry = 0;
        string result;
        while (aIt != a.crend() || bIt != b.crend()) {
            int aVal = (aIt == a.crend() ? 0 : *aIt++ - '0');
            int bVal = (bIt == b.crend() ? 0 : *bIt++ - '0');
            int val = aVal + bVal + carry;
            carry = val / 2;
            result = (char)((val % 2) + '0') + result;
        }
        if (carry) {
            result = '1' + result;
        }
        return result;
    }

int main() {
    cout << addBinary("11", "1") << endl;
    cout << addBinary("1", "11") << endl;
}
