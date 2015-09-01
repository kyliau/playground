// Given an array of integers and an integer k,
// find out whether there are two distinct indices
// i and j in the array such that nums[i] = nums[j]
// and the difference between i and j is at most k.

// Easy but (relatively) slow solution
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // map an integer to its last seen index
        unordered_map<int, size_t> myMap;
        for (size_t i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            auto it = myMap.find(n);
            if (it != myMap.end() && i - it->second <= k) {
                return true;
            }
            myMap[n] = i;
        }
        return false;
    }
};

// Slightly faster solution ;)
// (runtime beats 100.00% of cpp coders)
const size_t NHASH = 29989;
const size_t MULT  = 31;

inline size_t myhash(int n) {
    // random hash function - might not even make sense
    return (n * MULT + n) % NHASH;
}

struct Node {
    int     num;
    size_t  index;
    Node   *next;
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        Node *bin[NHASH] = { 0 };
        for (size_t i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            size_t h = myhash(n);
            bool found = false;
            for (Node *p = bin[h]; p != nullptr && !found; p = p->next) {
                if (p->num ==n) {
                    if (i - p->index <= k) {
                        return true;
                    }
                    found = true;
                    p->index = i;
                }
            }
            if (!found) {
                Node *p = new Node();
                p->num   = n;
                p->index = i;
                p->next  = bin[h];
                bin[h]   = p;
            }
        }
        return false;
    }
};
