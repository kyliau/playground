#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
  private:
    string decode(const string& s, int& index) {
        ostringstream stream;
        int num = 0;
        while (index < s.size()) {
            char c = s[index++];
            if (c >= '0' && c <= '9') {
                num = num * 10 + c - '0';
            }
            else if (c == '[') {
                string result = decode(s, index);
                for (int i = 0; i < num; ++i) {
                    stream << result;
                }
                num = 0;
            }
            else if (c == ']') {
                return stream.str();
            }
            else {
                stream << c;
            }
        }
        return stream.str();
    }
  public:
    string decodeString(const string& s) {
        int index = 0;
        return decode(s, index);
    }
};

int main() {
    Solution s;
    cout << s.decodeString("3[a]2[bc]") << endl;
    cout << s.decodeString("3[a2[c]]") << endl;
    cout << s.decodeString("2[abc]3[cd]ef") << endl;
    cout << s.decodeString("3[a2[c]]bbb") << endl;
}