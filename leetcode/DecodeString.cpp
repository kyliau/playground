class Solution {
  private:
    string decode(const string& s, int left, int right) {
        ostringstream stream;
        int num      = 0;
        int brackets = 0;
        int begin    = -1;
        int length   = 0;
        for (int i = left; i < right; ++i) {
            if (s[i] >= '0' || s[i] <= '9') {
                num += num * 10 + s[i] - '0';
            }
            else if (s[i] == '[') {
                ++brackets;
            }
            else if (s[i] == ']') {
                if (--brackets == 0) {
                    string result = decode(s, begin, begin + length);
                    for (int j = 0; j < num; ++j) {
                        stream << result;
                    }
                    num = 0;
                    begin = -1;
                    length = 0;
                }
            }
            else {
                if (begin == -1) {
                    begin = i;
                }
                ++length;
            }
        }
        stream << s.substr(begin, length);
        return stream.str();
    }
  public:
    string decodeString(const string& s) {
        if (s.empty()) {
            return s;
        }
        return decode(s, 0, s.length() - 1);
    }
};