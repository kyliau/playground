// Given two words (beginWord and endWord), and a dictionary's word list,
// find all shortest transformation sequence(s) from beginWord to endWord,
// such that:

// * Only one letter can be changed at a time
// * Each intermediate word must exist in the word list
// For example,

// Given:
// beginWord = "hit"
// endWord   = "cog"
// wordList  = ["hot","dot","dog","lot","log"]
// Return
//   [
//     ["hit","hot","dot","dog","cog"],
//     ["hit","hot","lot","log","cog"]
//   ]
//   Note:
//   All words have the same length.
//   All words contain only lowercase alphabetic characters.

class Solution {
private:
    bool isEditDistanceOne(const string& s1, const string& s2) {
        assert(s1.length() == s2.length());
        int distance = 0;
        for (int i = 0; i < s1.length(); ++i) {
            distance += abs(s1[i] - s2[i]);
            if (1 < distance) {
                return false;                                         // RETURN
            }
        }
        return 1 == distance;
    }

public:
    vector<vector<string>> findLadders(string                 beginWord,
                                       string                 endWord,
                                       unordered_set<string> &wordList) {
		wordList.insert(beginWord);
        wordList.insert(endWord);

        unordered_map<string, vector<string&>> map;

        for (const string& s1 : wordList) {
            for (const string& s2 : wordList) {
            if (isEditDistance1(s1, s2)) {
                map[s1].emplace_back(s2);
                map[s2].emplace_back(s1);
            }
        }

        // OK, now I am ready to do the graph search
        queue<string&> q;
        q.push(beginWord);
        while (!q.empty()) {
            const string& s = q.top();
            q.pop();
            for (const string& n : map[s]) {

            }
        }
        
    }
};
