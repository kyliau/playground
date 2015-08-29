#include <limits>
#include <iostream>

using namespace std;

class Solution {
public:
    static int myAtoi(string str) {

        int result = 0;
        const char *c = str.data();
        bool negative = false;
        
        std::size_t firstNonBlank = str.find_first_not_of(" \t\n\r");
        if (firstNonBlank != std::string::npos) {
            c += firstNonBlank;
        }
        
        if (*c != '+' && *c != '-' && (*c < '0' || *c > '9')) {
            return 0;
        }
        cout << *c << endl;
        if (*c && (*c == '+' || *c == '-')) {
            negative = (*c == '-');
            ++c;
        }
        while (*c && (*c >= '0' && *c <= '9')) {
            int newResult;
            if (negative) {
                newResult = result * 10 - (*c - '0');
                if (newResult > result) {
                    return std::numeric_limits<int>::min();
                }
            } else {
                newResult = result * 10 + (*c - '0');
                if (newResult < result) {
                    return std::numeric_limits<int>::max(); 
                }
            }
            cout << *c << '\t' << result << '\t' << newResult << endl;
            result = newResult;
            ++c;
        }
        return result;
    }
};

int main() {
    std::cout << Solution::myAtoi("    10522545459") << endl;
}


// Leetcode submission
// It would be desirable to not use long long
// See leetcode solution
class Solution {
public:
    int myAtoi(string str) {

        long long result = 0;
        const char *c = str.data();
        bool negative = false;
        
        std::size_t firstNonBlank = str.find_first_not_of(" \t\n\r");
        if (firstNonBlank != std::string::npos) {
            c += firstNonBlank;
        }
        
        if (*c != '+' && *c != '-' && (*c < '0' || *c > '9')) {
            return 0;
        }
        if (*c && (*c == '+' || *c == '-')) {
            negative = (*c == '-');
            ++c;
        }
        while (*c && (*c >= '0' && *c <= '9')) {
            long long newResult;
            if (negative) {
                newResult = result * 10 - (*c - '0');
                if (newResult < INT_MIN) {
                    return INT_MIN;
                }
            } else {
                newResult = result * 10 + (*c - '0');
                if (newResult > INT_MAX) {
                    return INT_MAX;
                }
            }
            result = newResult;
            ++c;
        }
        return result;
    }
};
