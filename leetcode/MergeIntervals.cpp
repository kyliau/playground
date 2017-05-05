// Given a collection of intervals, merge all overlapping intervals.
//
// For example,
// Given [1,3],[2,6],[8,10],[15,18],
// return [1,6],[8,10],[15,18].

#include <iostream>
#include <vector>
#include <algorithm>
//using namespace std;

/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
    //void swap(Interval& lhs, Interval& rhs) {
    //    std::swap(lhs.start, rhs.start);
    //    std::swap(lhs.end, rhs.end);
    //}
};

//void swap(Interval& lhs, Interval& rhs) {
//    std::swap(lhs.start, rhs.start);
//    std::swap(lhs.end, rhs.end);
//}

bool operator==(const Interval& lhs, const Interval& rhs) {
    return lhs.start == rhs.start && lhs.end == rhs.end;
}

class Solution {
  public:
    std::vector<Interval> merge(const std::vector<Interval>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const Interval& lhs, const Interval& rhs) {
            return lhs.start < rhs.start;
        });




        std::vector<Interval> results;
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
    };
    const int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int   n = CASES[i].n;
        auto& v = CASES[i].v;
        auto& e = CASES[i].e;
        Solution s;
        std::cout << "Test case " << n << " ... ";
        auto result = s.merge(v);
        if (e == result) {
            std::cout << "PASS";
        }
        else {
            std::cout << "FAIL";
        }
        std::cout << std::endl;
    }
    return 0;
}