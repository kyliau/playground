// this is wip

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
    void reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr) {
            ListNode *node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = node;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head1 = head;
        ListNode *head2 = reverseList(slow);
        while (head1 || head2) {
            ListNode *node1 = head1->next;
            head1->next = head2;
            ListNode *node2 = head2->next;
            head2->next = node1;
            head1 = node1;
            head2 = node2;
        }
        return head;
    }
};
