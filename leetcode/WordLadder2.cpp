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
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;
using Graph = unordered_map<string, vector<const string *>>;

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

ostream& operator<<(ostream& stream, const Graph& g) {
    for (const auto& p : g) {
        stream << p.first << " : [ ";
        for (const auto s : p.second) {
            stream << *s << " ";
        }
        stream << "]\n";
    }
    return stream;
}

class Solution {
private:
    //using Graph = unordered_map<string, vector<const string *>>;
    Graph d_graph;
    Graph d_path;

    bool isEditDistanceOne(const string& s1, const string& s2) {
        int distance = 0;
        int length   = s1.length();
        for (int i = 0; i < length; ++i) {
            if (s1[i] != s2[i]) {
                if (distance > 0) {
                    return false;
                }
                ++distance;
            }
        }
        return distance == 1;
    }

    void buildGraph(const string& beginWord, const vector<string>& wordList) {
        for (const string& w : wordList) {
            if (isEditDistanceOne(w, beginWord)) {
                d_graph[w].emplace_back(&beginWord);
                d_graph[beginWord].emplace_back(&w);
            }
        }
        for (int i = 0; i < wordList.size(); ++i) {
            for (int j = i + 1; j < wordList.size(); ++j) {
                const string& s1 = wordList[i];
                const string& s2 = wordList[j];
                if (isEditDistanceOne(s1, s2)) {
                    d_graph[s1].emplace_back(&s2);
                    d_graph[s2].emplace_back(&s1);
                }
            }
        }
    }

    void findShortestDistance(const string& beginWord, const string& endWord) {
        std::stack<const string *> s;
        std::unordered_set<string> visited;
        s.push(&beginWord);
        while (!s.empty()) {
            const string& w = *(s.top());    // fix this! should not make a copy
            s.pop();
            visited.insert(w);
            const auto it = d_graph.find(w);
            assert(it != d_graph.end());
            const auto& neighbours = it->second;
            for (const string *n : neighbours) {
                if (visited.end() == visited.find(*n)) {
                    d_path[*n].emplace_back(&w);
                    s.push(n);
                }
            }
        }
    }

    void backtrack(vector<vector<string>> *r,
                   vector<string>         *v,
                   const string&           word,
                   const string&           beginWord) {
        auto it = d_path.find(word);
        if (d_path.end() == it) {
            v->emplace_back(beginWord);
            std::reverse(v->begin(), v->end());
            return;                                                    // RETURN
        }
        v->emplace_back(word);
        for (int i = 0; i < it->second.size(); ++i) {
            const string& w = *(it->second[i]);
            if (i == 0) {
                backtrack(r, v, w, beginWord);
            } else {
                r->emplace_back(*v);
                backtrack(r, &r->back(), w, beginWord);
            }
        }
    }

public:
    vector<vector<string>> findLadders(const string&         beginWord,
                                       const string&         endWord,
                                       const vector<string>& wordList) {
        vector<vector<string>> result;
        if (wordList.end() == std::find(wordList.begin(),
                                        wordList.end(),
                                        endWord)) {
            return result;                                             // RETURN
        }
        buildGraph(beginWord, wordList);
        cout << d_graph;
        findShortestDistance(beginWord, endWord);
        cout << d_path;
        auto it = d_path.find(endWord);
        if (it != d_path.end()) {
            result.emplace_back();
            backtrack(&result, &result.back(), endWord, beginWord);
        }
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
        {
            1,
            "hit",
            "cog",
            {"hot", "dot", "dog", "lot", "log", "cog"},
            {
                {"hit", "hot", "dot", "dog", "cog"},
                {"hit", "hot", "lot", "log", "cog"},
            }
        },
        {
            2,
            "hot",
            "got",
            {"got"},
            {
                {"hot", "got"}
            }
        }
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
        //for (int j = 1; j < result.size(); ++j) {
        //    assert(result[j].size() == result[j-1].size());
        //}
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
                 << result;
        }
        cout << endl;
    }
    return 0;
}