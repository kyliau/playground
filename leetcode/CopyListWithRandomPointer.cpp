// A linked list is given such that each node contains an additional
// random pointer which could point to any node in the list or null.
// Return a deep copy of the list.

#include <unordered_map>

using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
private:
    unordered_map<const RandomListNode *, RandomListNode *> nodeMap;

    RandomListNode *makeNode(const RandomListNode *node) {
        if (node == nullptr) {
            return nullptr;
        }
        auto it = nodeMap.find(node);
        if (it == nodeMap.end()) {
            RandomListNode *n = new RandomListNode(node->label);
            nodeMap[node] = n;
            n->next   = makeNode(node->next);
            n->random = makeNode(node->random);
            return n;
        } else {
            return it->second;
        }
    }
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        return makeNode(head);
    }
};

class Solution2 {
  public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        using Node = RandomListNode;
        Node *current = head;
        Node *next;
        while (current) {
            next = current->next;
            current->next = new Node(current->label);
            current->next->next = next;
            current = next;
        }
        current = head;
        while (current) {
            Node *duplicate = current->next;
            duplicate->random = current->random ? current->random->next
                                                : nullptr;
            current = duplicate->next;
        }
        current = head;
        Node *newHead = nullptr;
        while (current) {
            Node *duplicate = current->next;
            if (!newHead) {
                newHead = duplicate;
            }
            next = duplicate->next;
            current->next = next;
            duplicate->next = next ? next->next : nullptr;
            current = next;
        }
        return newHead;
    }
};