// Given a roman numeral, convert it to an integer.
// Input is guaranteed to be within the range from 1 to 3999.

// I placed before V or X indicates one less       (IV, IX)
// X placed before L or C indicates ten less       (XL, XC)
// C placed before D or M indicates a hundred less (CD, CM)

class Solution {
public:
    int romanToInt(string s) {
        int map[26] = { 0 };
        map['I' - 'A'] = 1;
        map['V' - 'A'] = 5;
        map['X' - 'A'] = 10;
        map['L' - 'A'] = 50;
        map['C' - 'A'] = 100;
        map['D' - 'A'] = 500;
        map['M' - 'A'] = 1000;
        int result = 0;
        char prev  = 'A';
        for (char c : s) {
            result += map[c - 'A'];
            if ((prev == 'I' && c == 'V') ||
                (prev == 'I' && c == 'X') ||
                (prev == 'X' && c == 'L') ||
                (prev == 'X' && c == 'C') ||
                (prev == 'C' && c == 'D') ||
                (prev == 'C' && c == 'M')) {
                result -= 2 * map[prev - 'A'];
            }
            prev = c;
        }
        return result;
    }
};
