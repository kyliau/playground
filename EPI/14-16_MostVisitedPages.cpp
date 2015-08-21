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
#include <set>
#include <unordered_map>
#include <string>
#include <vector>
#include <random>
using namespace std;

struct Log {
    long   timestamp;
    string page;
};

size_t partition()
{
    return 0;
}

int partition(vector<pair<string, size_t>> *v, int left, int right, int pivot)
{
    
}

void firstSolution(const vector<Log>& logs, size_t k)
{
    // map the page to the frequency
    typedef unordered_map<string, size_t> PageToFreqMap;
    PageToFreqMap pageToFreqMap;

    for (const Log& log : logs) {
        PageToFreqMap::iterator it = pageToFreqMap.find(log.page);
        if (it == pageToFreqMap.end()) {
            pageToFreqMap[log.page] = 1;
        } else {
            ++it->second;
        }
    }

    vector<PageToFreqMap::value_type> v(pageToFreqMap.begin(),
                                        pageToFreqMap.end());
    int left = 0, right = v.size() - 1;
    while (left <= right) {
        default_random_engine gen((random_device())());
        // generate random int in [left, right]
        uniform_int_distribution<int> dis(left, right);
        int p = partition(&v, left, right, dis(gen));
        if (p == k - 1) {
            int i = p, j = k;
            while (i >= 0 && j >= 0) {
                cout << v[i].second << " " << v[i].first << endl;
                --i;
                --j;
            }
        } else if (p > k - 1) {
            right = p - 1;
        } else {    // p < k - 1
            left  = p + 1;
        }
    }
}

int main()
{
    vector<Log> logs = {{0, "http://www.google.com" },
                        {1, "http://www.yahoo.com"  },
                        {2, "http://www.apple.com"  },
                        {3, "htpp://www.google.com" },
                        {3, "htpp://www.google.com" },
                        {4, "http://www.apple.com"  }};
    firstSolution(logs, 3);
}
