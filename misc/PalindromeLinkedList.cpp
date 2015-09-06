#include <iostream>
#include <string>

struct ListNode {
    char val;
    ListNode *next;
    ListNode(char x) : val(x), next(NULL) {}
};

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
void printList(ListNode *head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
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

ListNode *makeList(const std::string& s) {
    ListNode *head = nullptr;
    ListNode *prev = nullptr;
    for (size_t i = 0; i < s.size(); ++i) {
        ListNode *node = new ListNode(s[i]);
        if (i == 0) {
            head = node;
        } else {
            prev->next = node;
        }
        prev = node;
    }
    return head;
}

int main() {
    ListNode *head = makeList("racecar");
    printList(head);
    std::cout << "is palindrome? " << std::boolalpha
              << isPalindrome(head) << std::endl;
}
