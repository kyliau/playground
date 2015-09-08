// Write a program to find the node at which the intersection of two singly linked lists begins.
// For example, the following two linked lists:
// A:          a1 → a2
//                    ↘
//                      c1 → c2 → c3
//                    ↗            
// B:     b1 → b2 → b3
// begin to intersect at node c1.
// Notes:
// If the two linked lists have no intersection at all, return null.
// The linked lists must retain their original structure after the function returns.
// You may assume there are no cycles anywhere in the entire linked structure.
// Your code should preferably run in O(n) time and use only O(1) memory.

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        size_t lengthA = 0, lengthB = 0;
        ListNode *prevA = nullptr, *prevB = nullptr;
        ListNode *listA = headA, *listB = headB;
        while (listA) {
            ++lengthA;
            prevA = listA;
            listA = listA->next;
        }
        while (listB) {
            ++lengthB;
            prevB = listB;
            listB = listB->next;
        }
        if (prevA != prevB || prevA == nullptr || prevB == nullptr) {
            return nullptr;
        }
        bool aIsLonger = lengthA > lengthB;
        int advance = aIsLonger ? lengthA - lengthB
                                : lengthB - lengthA;
        for (int i = 0; i < advance; ++i) {
            if (aIsLonger) {
                headA = headA->next;
            } else {
                headB = headB->next;
            }
        }
        while (headA) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};
