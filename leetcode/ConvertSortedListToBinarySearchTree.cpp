// Given a singly linked list where elements are sorted in ascending order,
// convert it to a height balanced BST.

#include <vector>
#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  private:
    TreeNode *makeTree(ListNode *head, ListNode *end) {
        if (head == end) {
            return nullptr;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != end && fast->next != end && fast->next->next != end) {
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode *node = new TreeNode(slow->val);
        node->left  = makeTree(head, slow);
        node->right = makeTree(slow->next, end);
        return node;
    }

  public:
    TreeNode* sortedListToBST(ListNode* head) {
        return makeTree(head, nullptr);
    }
};

ListNode *makeList(const vector<int>& v) {
    ListNode *head = nullptr;
    ListNode *node = nullptr;
    for (int i : v) {
        if (node) {
            node->next = new ListNode(i);
            node = node->next;
        }
        else {
            head = new ListNode(i);
            node = head;
        }
    }
    return head;
}

void treeToVector(TreeNode *node, vector<int>& v) {
    if (node) {
        treeToVector(node->left, v);
        v.emplace_back(node->val);
        treeToVector(node->right, v);
    }
}

int main() {
    const struct {
        int         n;
        vector<int> v;
    } CASES[] = {
        { 1, { 1, 2, 3, 4, 5 } },
        { 2, {} },
        { 3, { 3, 3, 3, 3, 3 } },
        { 4, { 2, 4, 6, 8, 10 } },
    };
    const int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        const int n = CASES[i].n;
        auto&     v = CASES[i].v;
        cout << "Test case " << n << " ... ";
        Solution s;
        TreeNode *node = s.sortedListToBST(makeList(v));
        vector<int> result;
        result.reserve(v.size());
        treeToVector(node, result);
        if (result == v) {
            cout << "PASS" << endl;
        }
        else {
            cout << "FAIL" << endl;
        }
    }
    return 0;
}