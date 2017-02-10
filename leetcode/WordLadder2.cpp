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
#include <queue>

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

ostream& operator<<(ostream& stream, const unordered_map<string, int>& m) {
    for (const auto& p : m) {
        stream << p.first << " : " << p.second << endl;
    }
    return stream;
}

ostream& operator<<(ostream& stream, const vector<const string *>& v) {
    stream << "[";
    for (int i = 0; i < v.size(); ++i) {
        if (i > 0) {
            stream << ", ";
        }
        stream << *(v[i]);
    }
    stream << "]";
    return stream;
}

class Solution {
private:
    unordered_map<string, vector<const string *>> d_graph;
    unordered_map<string, int>                    d_distance;

    bool isEditDistanceOne(const string& s1, const string& s2) const {
        int distance = 0;
        int length   = s1.length();
        for (int i = 0; i < length; ++i) {
            if (s1[i] != s2[i]) {
                if (distance > 0) {
                    return false;                                      // RETURN
                }
                ++distance;
            }
        }
        return distance == 1;
    }

    void buildGraph(const string& beginWord, const vector<string>& wordList) {
        d_graph.reserve(wordList.size() + 1);
        if (wordList.end() == std::find(wordList.begin(),
                                        wordList.end(),
                                        beginWord)) {
            for (const string& w : wordList) {
                if (isEditDistanceOne(w, beginWord)) {
                    d_graph[w].emplace_back(&beginWord);
                    d_graph[beginWord].emplace_back(&w);
                }
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

    int findShortestDistance(const string& beginWord, const string& endWord) {
        std::queue<const string *> q;
        q.push(&beginWord);
        int count    = 1;
        int distance = 0;
        while (!q.empty()) {
            const string& w = *(q.front());
            q.pop();
            --count;
            if (d_distance.end() == d_distance.find(w)) {
                d_distance[w] = distance;
                if (w == endWord) {
                    return distance;                                   // RETURN
                }
                const auto it = d_graph.find(w);
                if (it != d_graph.end()) {
                    // A word won't be found in the graph if it has no neighbors
                    for (const string *n : it->second) {
                        if (d_distance.end() == d_distance.find(*n)) {
                            q.push(n);
                        }
                    }
                }
            }
            if (0 == count) {
                count = q.size();
                ++distance;
            }
        }
        return -1;
    }

    void backtrack(vector<vector<string>> *r,
                   vector<string>         *v,
                   const string&           endWord) {
        assert(!v->empty());
        if (v->back() == endWord) {
            r->emplace_back(*v);
            return;                                                    // RETURN
        }
        const string& word = v->back();
        auto it = d_distance.find(word);
        assert(it != d_distance.end());
        int distance = it->second;
        assert(d_graph.end() != d_graph.find(word));
        for (const string *n : d_graph[word]) {
            auto it = d_distance.find(*n);
            if (d_distance.end() != it && it->second == distance + 1) {
                v->emplace_back(*n);
                backtrack(r, v, endWord);
                v->pop_back();
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
        int shortestDistance = findShortestDistance(beginWord, endWord);
        if (0 <= shortestDistance) {
            vector<string> v = { beginWord };
            backtrack(&result, &v, endWord);
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
            "aa",
            "bb",
            {"aa", "ab", "ba", "bb"},
            {
                {"aa", "ab", "bb"},
                {"aa", "ba", "bb"}
            }
        },
        {
            2,
            "hit",
            "cog",
            {"hot", "dot", "dog", "lot", "log", "cog"},
            {
                {"hit", "hot", "dot", "dog", "cog"},
                {"hit", "hot", "lot", "log", "cog"},
            }
        },
        {
            3,
            "hot",
            "got",
            {"got"},
            {
                {"hot", "got"}
            }
        },
        {
            4,
            "a",
            "b",
            {}, // endWord is not in wordList
            {}
        },
        {
            5,
            "aaa",
            "abc",
            {"aad", "abd", "abc", "aba"},
            {
                {"aaa", "aba", "abc"}
            }
        },
        {
            6,
            "aa",
            "bb",
            {"aa", "bb"},
            {}
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
                 << result;
        }
        cout << endl;
    }
    return 0;
}