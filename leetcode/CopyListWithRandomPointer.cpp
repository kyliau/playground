// A linked list is given such that each node contains an additional
// random pointer which could point to any node in the list or null.
// Return a deep copy of the list.

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
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
