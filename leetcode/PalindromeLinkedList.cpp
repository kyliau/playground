// Given a singly linked list, determine if it is a palindrome.
// Follow up:
// Could you do it in O(n) time and O(1) space?

// O(n) runtime, O(n) space
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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return true;
        }
        string s;
        while (head) {
            s.push_back(head->val);
            head = head->next;
        }
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};

// O(n) runtime, O(1) space
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
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode *list1, ListNode *list2) {
        while (list1) {
            if (list1->val != list2->val) {
                return false;
            }
            list1 = list1->next;
            list2 = list2->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;
        while (fast && fast->next && fast->next->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast && fast->next) {
            prev = slow;
            slow = slow->next;
        }
        if (prev) {
            prev->next = nullptr;
        }
        ListNode *mid = reverseList(slow);
        return isPalindrome(head, mid);
    }
};
