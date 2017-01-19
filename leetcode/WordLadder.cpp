// Given two words (beginWord and endWord), and a dictionary's word list, find
// the length of shortest transformation sequence from beginWord to endWord,
// such that:
// Only one letter can be changed at a time
// Each intermediate word must exist in the word list
// For example,
// Given:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
// As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
// Note:
// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <queue>
#include <assert.h>

using namespace std;

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

class Solution {
public:
    int ladderLength(const string&                beginWord,
                     const string&                endWord,
                     const unordered_set<string>& wordList) {
        unordered_set<string> words(wordList);
        words.insert(beginWord);
        words.insert(endWord);
        // 1. Build the graph
        unordered_map<string, vector<const string *>> g;
        g.reserve(words.size());

        for (const string& s1 : words) {
            for (const string& s2 : words) {
                if (isEditDistanceOne(s1, s2)) {
                    g[s1].emplace_back(&s2);
                }
            }
        }

        for (const auto& p : g) {
            cout << p.first << ": [";
            for (const string *s : p.second) {
                cout << *s << " ";
            }
            cout << "]" << endl;;
        }

        // 2. Do the graph search using BFS
        int distance = 0;
        unordered_set<string> visited;
        queue<const string *> q;
        q.emplace(&beginWord);
        while (!q.empty()) {
            const string& top = *(q.front());
            q.pop();
            if (top == endWord) {
                return distance;
            }
            visited.insert(top);
            auto it = g.find(top);
            if (it != g.end()) {
                ++distance;
                for (const string *s : it->second) {
                    if (visited.end() == visited.find(*s)) {
                        q.push(s);
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    {
        Solution s;
        assert(1 == s.ladderLength("hot", "got", {"hot", "got"}));
    }
    {
        Solution s;
        assert(2 == s.ladderLength("hot", "pit", {"hot", "pot", "pit"}));
    }
    {
        Solution s;
        int l = s.ladderLength("c", "b", {"a", "b", "c"});
        cout << l << endl;
        assert(1 == l);
    }
    {
        Solution s;
        int l = s.ladderLength("hit",
                               "cog",
                               {"hot","dot","dog","lot","log"});
        cout << l << endl;
        assert(5 == l);
    }
    return 0;
}