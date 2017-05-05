// Given a collection of intervals, merge all overlapping intervals.
//
// For example,
// Given [1,3],[2,6],[8,10],[15,18],
// return [1,6],[8,10],[15,18].

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool operator==(const Interval& lhs, const Interval& rhs) {
    return lhs.start == rhs.start && lhs.end == rhs.end;
}

ostream& operator<<(ostream& stream, const Interval& interval) {
    return stream << "(" << interval.start << ", " << interval.end << ")";
}

template <typename T>
ostream& operator<<(ostream& stream, const vector<T>& v) {
    stream << "[";
    for (int i = 0; i < v.size(); ++i) {
        stream << (i == 0 ? "" : ", ") << v[i];
    }
    stream << "]";
    return stream;
}

class Solution {
  public:
    std::vector<Interval> merge(std::vector<Interval>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const Interval& lhs,
                                                         const Interval& rhs) {
            return lhs.start < rhs.start;
        });
        std::vector<Interval> results;
        if (intervals.empty()) {
            return results;
        }
        Interval interval(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            const Interval& intv = intervals[i];
            if (intv.start > interval.end) {
                results.emplace_back(interval);
                interval = intv;
            } else {
                interval.end = std::max(interval.end, intv.end);
            }
        }
        results.emplace_back(interval);
        return results;
    }
};

int main() {
    const struct {
        int                   n;
        std::vector<Interval> v;
        std::vector<Interval> e;
    } CASES[] = {
        { 1, {{1, 3}, {2, 6}, {8, 10}, {15, 18}}, {{1, 6}, {8, 10}, {15, 18}} },
        { 2, {{1, 2}, {3, 4}, {5, 6}}, {{1, 2}, {3, 4}, {5, 6}} },
        { 3, {{1, 3}, {4, 5}, {2, 9}, {3, 6}}, {{1, 9}} },
    };
    const int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int   n = CASES[i].n;
        auto  v = CASES[i].v;
        auto& e = CASES[i].e;
        Solution s;
        std::cout << "Test case " << n << " ... ";
        auto result = s.merge(v);
        if (e == result) {
            std::cout << "PASS";
        }
        else {
            std::cout << "FAIL (Expect " << e << " but got " << result << ")";
        }
        std::cout << std::endl;
    }
    return 0;
}