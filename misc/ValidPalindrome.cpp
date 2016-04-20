#include <iostream>
#include <string>
#include <cctype>
using namespace std;  

  bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }
        int left  = 0;
        int right = s.size() - 1;
        while (left < right) {
            cout << "loop begin" << endl;
            char l = tolower(s[left]);
            cout << "s[left] = " << s[left] << endl;
            char r = tolower(s[right]);
            cout << "s[right] = " << s[right] << endl;
            while (left < right && (l < 'a' || l > 'z')) {
                ++left;
                l = tolower(s[left]);
                cout << "s[left] = " << s[left] << endl;
            }
            while (left < right && (r < 'a' || r > 'z')) {
                --right;
                r = tolower(s[right]);
                cout << "s[right] = " << s[right] << endl;
            }
            if (l != r) {
                cout << "l = " << l << ", r = " << r << endl;
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }

int main() {
    cout << isPalindrome("a.") << endl;
}
