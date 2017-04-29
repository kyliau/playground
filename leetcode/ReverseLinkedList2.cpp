// Reverse a linked list from position m to n. Do it in-place and in one-pass.
//
// For example:
// Given 1->2->3->4->5->NULL, m = 2 and n = 4,
//
// return 1->4->3->2->5->NULL.
//
// Note:
// Given m, n satisfy the following condition:
// 1 ≤ m ≤ n ≤ length of list.

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy1(0);
        ListNode dummy2(0);
        dummy1.next = &dummy2;
        dummy2.next = head;
        ListNode *prev1 = &dummy1;
        ListNode *prev2 = &dummy2;
        ListNode *curr  = head;
        for (int i = 0; i < m; ++i) {
            prev1 = prev1->next;
            prev2 = prev2->next;
            curr  = curr->next;
        }
        // Now we are ready to reverse the linked list
        ListNode *prev = prev2;
        for (int i = 0; i < n - m; ++i) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        prev2->next = curr;
        prev1->next = prev;
        return dummy2.next;
    }
};

int main() {
    const struct {
        int         c;
        vector<int> v;
        int         m;
        int         n;
        vector<int> expected;
    } CASES[] = {
        { 1, { 1, 2, 3, 4, 5 }, 1, 5, { 5, 4, 3, 2, 1 } },
        { 2, { 1, 2, 3, 4, 5 }, 2, 5, { 1, 5, 4, 3, 2 } },
        { 3, { 1, 2, 3, 4, 5 }, 3, 5, { 1, 2, 5, 4, 3 } },
        { 4, { 1, 2, 3, 4, 5 }, 4, 5, { 1, 2, 3, 5, 4 } },
        { 5, { 1, 2, 3, 4, 5 }, 5, 5, { 1, 2, 3, 4, 5 } },
        { 6, { 1, 2, 3, 4, 5 }, 2, 4, { 1, 4, 3, 2, 5 } },
    };
    int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int   c = CASES[i].c;
        auto& v = CASES[i].v;
        int   m = CASES[i].m;
        int   n = CASES[i].n;
        auto& e = CASES[i].expected;
        cout << "Test case " << c << " ... ";
        Solution s;
        ListNode *result = s.reverseBetween(makeList(v), m, n);
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