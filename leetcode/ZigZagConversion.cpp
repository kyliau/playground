// The string "PAYPALISHIRING" is written in a zigzag pattern
// on a given number of rows like this:
//
// P   A   H   N
// A P L S I I G
// Y   I   R
//
// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given a number of rows:
// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

// Note: Runtime is average ...
// Seems not much difference between ostringstream and string

class Solution {
public:
    string convert(string s, int numRows) {
        string result;
        const int totalStep = numRows <= 1 ? 1 : 2 * (numRows - 1);
        for (int row = 0; row < numRows; ++row) {
            int step = row == 0 ? totalStep : 2 * row;
            for (int i = row; i < s.size(); i += step) {
                result.push_back(s[i]);
                step = totalStep == step ? step : totalStep - step;
            }
        }
        return result;
    }
};
