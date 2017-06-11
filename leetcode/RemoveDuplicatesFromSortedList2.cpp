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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;
        ListNode *curr = head;
        while (curr) {
            if (!curr->next || curr->val != curr->next->val) {
                prev->next = curr;
                prev = curr;
            }
            int val = curr->val;
            while (curr && curr->val == val) {
                curr = curr->next;
            }
        }
        prev->next = nullptr;
        return dummy.next;
    }
};