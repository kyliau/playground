// Given an array of integers, find if the array contains any duplicates.
// Your function should return true if any value appears at least twice in the array,
// and it should return false if every element is distinct.

// this problem is trivial with the use of std::sort or std::unordered_map
// strategy : Trying to roll my own hash table!
// note     : no memory management!
// results  : It is indeed faster than std::unordered_map :)

// My hash table implementation is inspired by the book Programming Pearls

// choose some random prime numbers
const unsigned int NHASH = 29989;
const unsigned int MULT  = 31;

struct Node {
    int   num;
    Node *next;
};

inline unsigned int myhash(int n) {
    // this is a random hash function - might not even make sense
    return (MULT * n + n) % NHASH;
}

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        Node* bin[NHASH] = { 0 };
        for (int n : nums) {
            unsigned int h = myhash(n);
            Node *p;
            for (p = bin[h]; p != nullptr; p = p->next) {
                if (p->num == n) {
                    return true;
                }
            }
            p = new Node();
            p->num  = n;
            p->next = bin[h];
            bin[h]  = p;
        }
        return false;
    }
};
