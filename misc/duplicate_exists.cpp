#include <iostream>
#include <vector>
using namespace std;

//bool containsDuplicate(vector<int>& nums) {
//    size_t size = (1L << 32);
//    cout << "size = " << size << endl;
//    vector<bool> map(size, false);
//    for (long long n : nums) {
//        size_t index = n + 2147483648;
//        cout << "index = " << index << endl;
//        if (map[index]) {
//            return true;
//        }
//        map[index] = true;
//    }
//    return false;
//}

const unsigned int NHASH = 29989;
const unsigned int MULT  = 31;

struct Node {
    int   num;
    Node *next;
};

inline unsigned int myhash(int n) {
    return (MULT * n + n) % NHASH;
}

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        Node* bin[NHASH] = { 0 };
        for (int n : nums) {
            cout << "n = " << n << endl;
            unsigned int h = myhash(n);
            cout << "hash = " << h << endl;
            Node *p;
            for (p = bin[h]; p != 0; p = p->next) {
                if (p->num == n) {
                    return true;
                }
            }
            cout << "Creating new node" << endl;
            p = new Node();
            p->num = n;
            p->next = bin[h];
            bin[h] = p;
        }
        return false;
    }
};

int main() {
    vector<int> v = { INT_MIN, 0, INT_MAX };
    Solution s;
    cout << s.containsDuplicate(v) << endl;
}
