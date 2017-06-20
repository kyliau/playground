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

void print(ListNode *head) {
    bool isHead = true;
    while (head) {
        cout << (isHead ? "" : "->") << head->val;
        isHead = false;
        head = head->next;
    }
    cout << endl;
}

class Solution {
  public:
    ListNode* sortList(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        if (!head->next) {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *right = sortList(slow->next);
        slow->next = nullptr;
        ListNode *left = sortList(head);

        ListNode dummy(0);
        ListNode *curr = &dummy;
        while (left || right) {
            if (!left) {
                curr->next = right;
                right = right->next;
            }
            else if (!right) {
                curr->next = left;
                left = left->next;
            }
            else if (left->val < right->val) {
                curr->next = left;
                left = left->next;
            }
            else {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
        curr->next = nullptr;
        return dummy.next;
    }
};

ListNode* makeList(const vector<int>& v) {
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


int main() {
    Solution s;
    print(s.sortList(makeList({ 5, 4, 3, 2, 1, 0})));
    print(s.sortList(makeList({ 5, 1 })));
    print(s.sortList(makeList({3,5,1,3,5,6,4,2,7})));
    return 0;
}