class Solution {
  private:
    bool isSign(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }
  public:
    int calculate(const string& s) {
        std::stack<int> stack;
        int num = 0;
        char sign = '+';
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (std::isdigit(c)) {
                num = num * 10 + c - '0';
            }
            if (isSign(c) || i == s.size() - 1) {
                if (sign == '+') {
                    stack.push(num);
                }
                else if (sign == '-') {
                    stack.push(-num);
                }
                else if (sign == '*') {
                    int x = stack.top();
                    stack.pop();
                    stack.push(x * num);
                }
                else if (sign == '/') {
                    int x = stack.top();
                    stack.pop();
                    stack.push(x / num);
                }
                num = 0;
                sign = c;
            }
        }
        int result = 0;
        while (!stack.empty()) {
            result += stack.top();
            stack.pop();
        }
        return result;
    }
};