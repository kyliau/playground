// Find the top N most frequent words in the given string in O(n) time.

#include <algorithm>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

void printTopN(const string& str, size_t N)
{
    typedef unordered_map<string, size_t> WordMap;
    size_t maxFrequency = 0;
    WordMap map;
    istringstream iss(str);
    string word;
    while (iss >> word) {
        maxFrequency = max(maxFrequency, ++map[word]);
    }

    vector<vector<const WordMap::value_type *>> buckets(maxFrequency);

    // instead of dumping the contents of the map to a 2D vector,
    // an alternative would be using the partition and
    // find_largest_k algorithm, which has the same O(n) complexity.
    for (const auto& pair : map) {
        buckets[pair.second - 1].emplace_back(&pair);
    }

    size_t count = 0;
    for (auto it = buckets.rbegin(); it != buckets.rend(); ++it) {
        for (auto pair : *it) {
            cout << ++count << ": " << pair->first
                 << " (" << pair->second << ')' << endl;
            if (count >= N) {
                return;                                               // return
            }
        }
    }
}

int main()
{
    cout << "Enter a sentence: " << endl;
    string str;
    getline(cin, str);
    size_t N = 0;
    cout << "Enter top N: ";
    cin >> N;
    printTopN(str, N);
}
