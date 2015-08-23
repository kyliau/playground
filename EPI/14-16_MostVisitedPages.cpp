// EPI Problem 14.16 page 110
// You are to implement methods to analyze log file data to find the most
// visited pages. Specifically, implement the following methods:
//
// void add(Entry p)
// add p.page to the set of visited pages. It is guaranteed that if add(q) is
// called after add(p) then q.timestamp is greater than or equal to p.timestamp
//
// List<String> common(k)
// return a list of the k most common pages
//
// First solve the problem when common(k) is called exactly once after all
// pages have been read. Then solve the problem when calls to common and add
// are interleaved. Assume you have unlimited RAM.

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <random>
#include <map>
#include <algorithm>
#include <cassert>
using namespace std;

struct Log {
    long   timestamp;
    string page;
};

void solution(const vector<Log>& logs, int k)
{
    // map the page to the frequency
    typedef unordered_map<string, int> PageToFreqMap;
    PageToFreqMap pageToFreqMap;

    for (const Log& log : logs) {
        PageToFreqMap::iterator it = pageToFreqMap.find(log.page);
        if (it == pageToFreqMap.end()) {
            pageToFreqMap[log.page] = 1;
        } else {
            ++it->second;
        }
    }

    k = min<int>(k, pageToFreqMap.size());

    // at this point we have two options
    // 1. easy option, O(n log n)
    // Dump the hash table into a multimap
    // This has the added benefit that the top k most common pages are sorted.
    {
        multimap<int, string> freqToPageMap;
        for (const auto& p : pageToFreqMap) {
            freqToPageMap.emplace(p.second, p.first);
        }
        cout << "First method: " << endl;
        int count = k;
        for (auto it  = freqToPageMap.crbegin();
                  it != freqToPageMap.crend() && count > 0;
                  ++it) {
            cout << it->second << "\t" << it->first << endl;
            --count;
        }
    }

    // 2. O(n)
    // Use the k-th largest algorithm
    // Since we expect to split the array into roughly equal halves on average,
    // Recurrence relation : T(n) = T(n/2) + O(n) = O(n)
    // Top k most common pages are not sorted

    vector<pair<string, int>> v(pageToFreqMap.begin(), pageToFreqMap.end());

    // Note, the use of 'auto' in lambda expression requires C++14
    nth_element(v.begin(),
                v.begin() + k - 1,
                v.end(),
                [](const auto& x, const auto& y){ return x.second > y.second; });

    cout << endl << "Second method: " << endl;
    for (const auto& p : v) {
        cout << p.first << " " << p.second << endl;
    }
}

int main()
{
    vector<Log> logs = {{0, "http://www.google.com"    },
                        {1, "http://www.yahoo.com"     },
                        {2, "http://www.apple.com"     },
                        {2, "http://www.microsoft.com" },
                        {3, "http://www.google.com"    },
                        {3, "http://www.google.com"    },
                        {4, "http://www.apple.com"     }};
    solution(logs, 1);
}
