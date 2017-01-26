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
using Graph = unordered_map<string, vector<const string*>>;

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

void print(const Graph& g) {
    for (const auto& p : g) {
        cout << p.first << ": [ ";
        for (const string *s : p.second) {
            cout << *s << " ";
        }
        cout << "]" << endl;;
    }
}

class Solution {
public:
    int ladderLength(const string&   beginWord,
                     const string&   endWord,
                     vector<string>& words) {

        words.emplace_back(beginWord);
        words.emplace_back(endWord);
        // 1. Build the graph
        Graph g;
        g.reserve(words.size() + 2);
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                const string& s1 = words[i];
                const string& s2 = words[j];
                if (isEditDistanceOne(s1, s2)) {
                    g[s1].emplace_back(&s2);
                    g[s2].emplace_back(&s1);
                }
            }
        }

        print(g);

        struct Node {
            const string* word;
            int           distance;
            Node(const string& word, int distance) {
                this->word     = &word;
                this->distance = distance;
            }
        };

        // 2. Do the graph search using BFS
        unordered_set<string> visited;
        queue<Node> q;
        q.emplace(beginWord, 1);
        while (!q.empty()) {
            Node node = q.front();
            q.pop();
            const string& word = *(node.word);
            //cout << "Checking " << word << ", distance = " << node.distance << endl;
            visited.insert(word);
            auto it = g.find(word);
            if (it != g.end()) {
                // A node will not exist in the graph if it does not have any
                // neighbour
                for (const string *s : it->second) {
                    //cout << "\tChecking neighbour " << *s << ", " << (visited.end() == visited.find(*s) ? "not seen before" : "seen") << endl;
                    if (*s == endWord) {
                        return node.distance + 1;                          // RETURN
                    }
                    if (visited.end() == visited.find(*s)) {
                        q.emplace(*s, node.distance + 1);
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    struct {
        int            i;
        string         beginWord;
        string         endWord;
        vector<string> words;
        int            distance;
    } CASES[] = {
        // #   begin   end           words                           distance
        // --  -----  -----  ---------------------                   --------
        {  1,  "hot", "got", {"hot", "got"},                              2 },
        {  2,  "hot", "pit", {"hot", "pot", "pit"},                       3 },
        {  3,    "c",   "b", {"a", "b", "c"},                             2 },
        {  4,  "hit", "cog", {"hot", "dot", "dog", "lot", "log" ,"cog" }, 5 },
        {  5,   "aa",  "ee", {"ab", "ac", "ad"},                          0 },
        {  6,    "a",   "a", {},                                          0 },
        {  7,  "hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog" }, 0 },
    };
    int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int num           = CASES[i].i;
        auto& begin = CASES[i].beginWord;
        auto& end   = CASES[i].endWord;
        auto& words = CASES[i].words;
        int expected      = CASES[i].distance;
        cout << "Running test case " << num << endl;
        Solution s;
        int distance = s.ladderLength(begin, end, words);
        cout << "Shortest distance from '" << begin << "' to '" << end << "' = "
             << distance << endl << endl;
        assert(distance == expected);
    }
    cout << "All test cases passed!" << endl;
    return 0;
}