// All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T,
// for example: "ACGAATTCCG".
// When studying DNA, it is sometimes useful to identify repeated sequences
// within the DNA.
// Write a function to find all the 10-letter-long sequences (substrings) that
// occur more than once in a DNA molecule.
// For example,
// Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
// Return:
// ["AAAAACCCCC", "CCCCCAAAAA"].

#include <vector>
#include <string>
#include <assert.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class StringRef {
    private:
        const string& s;
        int           start;
        int           length;
    public:
        StringRef(const string& s, int start, int length)
        : s(s), start(start), length(length) {
        }

        bool operator==(const StringRef& other) {
            if (length != other.length) {
                return false;
            }
            for (int i = 0; i < length; ++i) {
                if (s[start + i] != other.s[other.start + i]) {
                    return false;
                }
            }
            return true;
        }
};

class Solution {
public:
    vector<string> findRepeatedDnaSequences(const string& t) {
        static const int kBase  = 26;
        static const int kMod   = 997;
        static const int s_size = 10;
        if (s_size > t.size()) {
            return {};                                                 // RETURN
        }
        int t_hash  = 0;
        int power_s = 1; // the module result of kBase ^ |s|
        for (int i = 0; i < s_size; ++i) {
            power_s = i ? power_s * kBase % kMod : 1;
            t_hash  = (t_hash * kBase + t[i]) % kMod;
        }
        unordered_map<int, vector<int>> hashTable;
        unordered_set<int>              unique;
        hashTable[t_hash].emplace_back(0);
        for (int i = 0; i < t.size() - s_size; ++i) {
            // compute the new hash code using rolling hash
            t_hash -= (t[i] * power_s) % kMod;
            t_hash += t_hash < 0 ? kMod : 0;
            t_hash  = (t_hash * kBase + t[i + s_size]) % kMod;
            bool found = false;
            for (int j : hashTable[t_hash]) {
                if (StringRef(t, j, s_size) == StringRef(t, i+1, s_size)) {
                    found = true;
                    unique.emplace(j);
                    break;
                }
            }
            if (!found) {
                hashTable[t_hash].emplace_back(i + 1);
            }
        }
        vector<string> result;
        result.reserve(unique.size());
        for (int i : unique) {
            result.emplace_back(string(t, i, s_size));
        }
        return result;
    }
};

int main() {
    Solution s;
    for (const string& t : s.findRepeatedDnaSequences("AAAAAAAAAAAA")) {
        cout << t << endl;
    }
    return 0;
}