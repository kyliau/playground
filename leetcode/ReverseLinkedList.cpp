// Reverse a singly linked list.

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *makeList(const vector<int>& v) {
    if (v.empty()) {
        return nullptr;
    }
    ListNode *head = new ListNode(v[0]);
    ListNode *curr = head;
    for (int i = 1; i < v.size(); ++i) {
        curr->next = new ListNode(v[i]);
        curr = curr->next;
    }
    return head;
}

bool isSame(ListNode *x, ListNode *y) {
    if (x == y) {
        return true;
    }
    while (x && y) {
        if (x->val != y->val) {
            return false;
        }
        x = x->next;
        y = y->next;
    }
    return !x && !y;
}

class Solution {
  public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

// Recursive solution
class Solution2 {
  public:
    ListNode *reverseList(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *rest = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return rest;
    }
};

int main() {
    const struct {
        int         n;
        vector<int> v;
        vector<int> expected;
    } CASES[] = {
        { 1, { 1, 2, 3, 4, 5 }, { 5, 4, 3, 2, 1 } },
        { 2, { 1 }, { 1 } },
        { 3, { }, { } },
        { 4, { 1, 2 }, { 2, 1 } },
    };
    int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int   n = CASES[i].n;
        auto& v = CASES[i].v;
        auto& e = CASES[i].expected;
        cout << "Test case " << n << " ... ";
        Solution2 s;
        ListNode *result = s.reverseList(makeList(v));
        if (isSame(result, makeList(e))) {
            cout << "PASS";
        }
        else {
            cout << "FAIL";
        }
        cout << endl;
    }
    return 0;
}