// Given a pattern and a string str, find if str follows the same pattern.
// Examples:
// pattern = "abba", str = "dog cat cat dog" should return true.
// pattern = "abba", str = "dog cat cat fish" should return false.
// pattern = "aaaa", str = "dog cat cat dog" should return false.
// pattern = "abba", str = "dog dog dog dog" should return false.
// Notes:
// pattern contains only lowercase alphabetical letters, 
// and str contains words separated by a single space.
// Each word in str contains only lowercase alphabetical letters.
// Both pattern and str do not have leading or trailing spaces.
// Each letter in pattern must map to a word with length that is at least 1.

const int SIZE = 29989;
const int MULT = 31;

struct Node {
    char c;
    const string& s;
    Node *next;
    Node(char _c, const string& _s, Node *_n) : c(_c), s(_s), next(_n) {} 
};

class Solution {
public:
    unsigned calcHash(const string& s) {
        unsigned result = 0;
        for (int i = 0; i < s.size(); ++i) {
            result = result * MULT + s[i];
        }
        return result % SIZE;
    }
    bool wordPattern(string pattern, string str) {
        string mymap[26];
        Node  *myhash[SIZE] = { nullptr };
        
        istringstream iss(str);
        string s;
        int count = 0;
        for (int i = 0; i < pattern.size(); ++i) {
            if (!(iss >> s)) {
                return false;
            }
            ++count;
            int index = pattern[i] - 'a';
            if (mymap[index].empty()) {
                mymap[index] = s;
            } else if (mymap[index] != s) {
                return false;
            }
            
            unsigned h = calcHash(s);
            Node *n = myhash[h];
            while (n) {
                if (n->s == s) {
                    if (n->c != pattern[i]) {
                        return false;
                    }
                    break;
                }
                n = n->next;
            }
            if (n == nullptr) {
                n = new Node(pattern[i], s, myhash[h]);
                myhash[h] = n;
            }
            
        }
        return iss.eof();
    }
};
