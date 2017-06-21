class Solution {
  public:
    int calculate(const string& s) {
        std::stack<int> stack;
        int result = 0;
        int num = 0;
        int sign = 1;
        for (char c : s) {
            if (std::isdigit(c)) {
                num = num * 10 + c - '0';
            }
            else if (c == '+') {
                result += num * sign;
                num = 0;
                sign = 1;
            }
            else if (c == '-') {
                result += num * sign;
                num = 0;
                sign = -1;
            }
            else if (c == '(') {
                stack.push(result);
                stack.push(sign);
                sign = 1;
                result = 0;
                assert(num == 0);
            }
            else if (c == ')') {
                result += sign * num;
                num = 0;
                result *= stack.top();  // sign
                stack.pop();
                result += stack.top();  // result
                stack.pop();
            }
        }
        result += sign * num;
        return result;
    }
};