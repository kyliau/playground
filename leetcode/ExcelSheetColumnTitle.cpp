// Given a positive integer, return its corresponding column title as appear in an Excel sheet.
// For example:
//    1 -> A
//    2 -> B
//    3 -> C
//    ...
//    26 -> Z
//    27 -> AA
//    28 -> AB 

class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n > 0) {
            --n;
            result = char((n % 26) + 'A') + result;
            n /= 26;
        }
        // From the test results using reverse is slower than
        // string concatenation using operator+
        // reverse(result.begin(), result.end());
        return result;
    }
};
