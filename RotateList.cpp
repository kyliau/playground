// Given a list, rotate the list to the right by k places,
// where k is non-negative.
// For example:
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) {
            return head;
        }
        ListNode *n = head;
        int length = 1;
        while (n->next) {
            ++length;
            n = n->next;
        }
        k %= length;
        ListNode *tail = n;
        tail->next = head;
        for (int i = 0; i < length - k; ++i) {
            n = n->next;
        }
        head = n->next;
        n->next = nullptr;
        return head;
    }
};
