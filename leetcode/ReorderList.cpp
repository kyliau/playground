// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
// You must do this in-place without altering the nodes' values.
// For example,
// Given {1,2,3,4}, reorder it to {1,4,2,3}.

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
    ListNode *reverseList(ListNode *head) {
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
    ListNode *zipLists(ListNode *list1, ListNode* list2) {
        if (list1 == nullptr || list2 == nullptr) {
            return list1 ? list1 : list2;
        }
        ListNode *head = nullptr;
        ListNode *curr = nullptr;
        while (list1) {
            if (curr) {
                curr->next = list1;
                curr = list1;
            } else {
                head = list1;
                curr = list1;
            }
            list1 = list1->next;
            swap(list1, list2);
        }
        return head;
    }
    void reorderList(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (slow) {
            ListNode *temp = slow->next;
            slow->next = nullptr;
            slow = temp;
        }
        zipLists(head, reverseList(slow));
    }
};
