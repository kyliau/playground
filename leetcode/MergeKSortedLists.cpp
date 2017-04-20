// Merge k sorted linked lists and return it as one sorted list.
// Analyze and describe its complexity.

#include <iostream>
#include <vector>
#include <queue>
#include <assert.h>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
    ListNode* mergeKLists(const vector<ListNode*>& lists) {
        using Pair = std::pair<ListNode *, int>;
        auto cmp = [](const Pair& lhs, const Pair& rhs) {
            assert(lhs.first);
            assert(rhs.first);
            return lhs.first->val > rhs.first->val;
        };
        std::priority_queue<Pair, std::vector<Pair>, decltype(cmp)> q(cmp);
        ListNode head(0);

        for (int i = 0; i < lists.size(); ++i) {
            ListNode *node = lists[i];
            if (node) {
                q.push(Pair(node, i));
            }
        }

        ListNode *current = &head;
        while (!q.empty()) {
            Pair p = q.top();
            q.pop();
            ListNode *node = p.first;
            if (node->next) {
                q.push(Pair(node->next, p.second));
            }
            current->next = node;
            current = current->next;
        }

        return head.next;
    }
};

ListNode *toList(const vector<int>& v) {
    if (v.empty()) {
        return nullptr;
    }
    ListNode *head = new ListNode(v[0]);
    ListNode *current = head;
    for (int i = 1; i < v.size(); ++i) {
        current->next = new ListNode(v[i]);
        current = current->next;
    }
    return head;
}

vector<ListNode *> toLists(const vector<vector<int>>& v) {
    vector<ListNode *> results;
    results.reserve(v.size());
    for (auto& list : v) {
        results.emplace_back(toList(list));
    }
    return results;
}

bool isSame(const ListNode *lhs, const ListNode *rhs) {
    while (lhs && rhs && lhs->val == rhs->val) {
        lhs = lhs->next;
        rhs = rhs->next;
    }
    return !lhs && !rhs;
}


int main() {
    const struct {
        int                 n;
        vector<vector<int>> lists;
        vector<int>         result;
    } CASES[] = {
        { 1, {                 {1}, {2}, {3} },             {1, 2, 3} },
        { 2, {                 {3}, {1}, {2} },             {1, 2, 3} },
        { 3, { {2, 4, 6}, {}, {1, 3, 5}, {0} }, {0, 1, 2, 3, 4, 5, 6} },
    };
    const int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int          n = CASES[i].n;
        auto&    lists = CASES[i].lists;
        auto& expected = CASES[i].result;
        Solution s;
        cout << "Test case " << n << " ... ";
        ListNode *node = s.mergeKLists(toLists(lists));
        if (isSame(node, toList(expected))) {
            cout << "PASS";
        }
        else {
            cout << "FAIL ( ";
            while (node) {
                cout << node->val << " ";
                node = node->next;
            }
            cout << ")" << endl;
        }
        cout << endl;
    }
    return 0;
}