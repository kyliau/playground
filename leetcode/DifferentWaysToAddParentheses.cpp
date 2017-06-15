class Solution {
  public:
    vector<int> diffWaysToCompute(const string& input) {
        vector<int> results;
        for (int i = 0; i < input.length(); ++i) {
            char c = input[i];
            if (c == '-' || c == '*' || c == '+') {
                vector<int> left  = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for (int x : left) {
                    for (int y : right) {
                        switch(c) {
                            case '-':
                                results.emplace_back(x - y);
                                break;
                            case '*':
                                results.emplace_back(x * y);
                                break;
                            case '+':
                                results.emplace_back(x + y);
                                break;
                        }
                    }
                }
            }
        }
        if (results.empty()) {
            results.emplace_back(std::stoi(input));
        }
        return results;
    }
};