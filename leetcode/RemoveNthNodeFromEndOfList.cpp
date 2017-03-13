// Given a linked list, remove the nth node from the end of list and return its
// head.
// For example,
//   Given linked list: 1->2->3->4->5, and n = 2.
//   After removing the second node from the end, the linked list becomes
//   1->2->3->5.
// Note:
// Given n will always be valid.
// Try to do this in one pass.

#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) {
            return nullptr;
        }
        ListNode *h = head;
        ListNode *c = head;
        for (int i = 0; i < n && h; ++i) {
            h = h->next;
        }
        if (!h) {
            ListNode *newHead = head->next;
            delete head;
            return newHead;
        }
        while (h->next) {
            h = h->next;
            c = c->next;
        }
        ListNode *victim = c->next;
        c->next = victim->next;
        delete victim;
        return head;
    }
};

class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) {
            return nullptr;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode *c = &dummy;
        ListNode *h = &dummy;
        for (int i = 0; i < n; ++i) {
            h = h->next;
        }
        while (h->next) {
            h = h->next;
            c = c->next;
        }
        ListNode *victim = c->next;
        c->next = victim->next;
        delete victim;
        return dummy.next;
    }
};

ListNode *buildList(const vector<int>& v) {
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

bool isSameList(ListNode *x, ListNode *y) {
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

ostream& operator<<(ostream& stream, ListNode *node) {
    stream << "[ ";
    bool isFirst = true;
    while (node) {
        stream << (isFirst ? "" : ", ") << node->val;
        isFirst = false;
        node = node->next;
    }
    stream << " ]";
    return stream;
}

int main() {
    const struct {
        int         k;
        vector<int> v;
        int         n;
        vector<int> r;
    } CASES[] = {
        {  1, {             1 }, 1, {            } },
        {  2, {          1, 2 }, 2, {          2 } },
        {  3, {          1, 2 }, 1, {          1 } },
        {  4, { 1, 2, 3, 4, 5 }, 1, { 1, 2, 3, 4 } },
        {  5, { 1, 2, 3, 4, 5 }, 2, { 1, 2, 3, 5 } },
        {  6, { 1, 2, 3, 4, 5 }, 3, { 1, 2, 4, 5 } },
        {  7, { 1, 2, 3, 4, 5 }, 4, { 1, 3, 4, 5 } },
        {  8, { 1, 2, 3, 4, 5 }, 5, { 2, 3, 4, 5 } },
        {  9, {               }, 0, {            } },
    };
    int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int   k = CASES[i].k;
        auto& v = CASES[i].v;
        int   n = CASES[i].n;
        auto& r = CASES[i].r;
        cout << "Test case " << k << " ... ";
        Solution2 s;
        ListNode *head     = buildList(v);
        ListNode *expected = buildList(r);
        ListNode *result   = s.removeNthFromEnd(head, n);
        if (isSameList(result, expected)) {
            cout << "PASS";
        }
        else {
            cout << "FAIL (Expected " << expected << " but got " << result
                 << ")";
        }
        cout << endl;
    }
    return 0;
}