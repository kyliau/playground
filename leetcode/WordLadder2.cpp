// Given two words (beginWord and endWord), and a dictionary's word list,
// find all shortest transformation sequence(s) from beginWord to endWord,
// such that:
// Only one letter can be changed at a time
// Each transformed word must exist in the word list.
// Note that beginWord is not a transformed word.
// For example,
// Given:
// beginWord = "hit"
// endWord   = "cog"
// wordList  = ["hot","dot","dog","lot","log","cog"]
// Return
//   [
//     ["hit","hot","dot","dog","cog"],
//     ["hit","hot","lot","log","cog"]
//   ]
// Note:
// Return an empty list if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.
// You may assume no duplicates in the word list.
// You may assume beginWord and endWord are non-empty and are not the same.

#include <iostream>
#include <assert.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

ostream& operator<<(ostream& stream, const vector<string>& v) {
    stream << "[ ";
    ostream_iterator<string> it(stream, " ");
    std::copy(v.begin(), v.end(), it);
    stream << "]";
    return stream;
}

ostream& operator<<(ostream& stream, const vector<vector<string>>& v) {
    stream << "[ ";
    for (const auto& s : v) {
        stream << s << " ";
    }
    stream << "]";
    return stream;
}

class Solution {
public:
    vector<vector<string>> findLadders(const string&         beginWord,
                                       const string&         endWord,
                                       const vector<string>& wordList) {
        vector<vector<string>> result;
        return result;
    }
};

int main() {
    const struct {
        int n;
        string                 beginWord;
        string                 endWord;
        vector<string>         wordList;
        vector<vector<string>> expected;
    } TEST_CASES[] = {
        { 1, "hit", "cog",
            {"hot", "dot", "dog", "lot", "log", "cog"},
            {
                {"hit", "hot", "dot", "dog", "cog"},
                {"hit", "hot", "lot", "log", "cog"},
            }
        },
    };
    int NUM_CASES = sizeof(TEST_CASES) / sizeof(TEST_CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        const int     n         = TEST_CASES[i].n;
        const string& beginWord = TEST_CASES[i].beginWord;
        const string& endWord   = TEST_CASES[i].endWord;
        const auto&   wordList  = TEST_CASES[i].wordList;
        const auto&   expected  = TEST_CASES[i].expected;
        for (int j = 1; j < expected.size(); ++j) {
            assert(expected[j].size() == expected[j-1].size());
        }
        Solution s;
        const auto result = s.findLadders(beginWord, endWord, wordList);
        for (int j = 1; j < result.size(); ++j) {
            assert(result[j].size() == result[j-1].size());
        }
        bool isExpected = result.size() == expected.size();
        for (int j = 0; j < expected.size() && isExpected; ++j) {
            auto it = std::find(result.begin(), result.end(), expected[j]);
            isExpected = it != result.end();
        }
        cout << "Test case " << n << "\t... ";
        if (isExpected) {
            cout << "PASS";
        } else {
            cout << "FAIL\n    Expected " << expected << "\n    but got "
                 << result << endl;
        }
        cout << endl;
    }
    return 0;
}