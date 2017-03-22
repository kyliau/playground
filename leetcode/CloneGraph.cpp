// Clone an undirected graph. Each node in the graph contains a label and a list
// of its neighbors.

#include <iostream>
#include <unordered_map>
#include <vector>
#include <assert.h>

using namespace std;

/**
 * Definition for undirected graph.
 */
struct UndirectedGraphNode {
    int                           label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *clone(
                        UndirectedGraphNode                        *node,
                        unordered_map<int, UndirectedGraphNode *>&  hashTable) {
        if (!node) {
            return nullptr;                                            // RETURN
        }
        auto it = hashTable.find(node->label);
        if (it != hashTable.end()) {
            return it->second;
        }
        UndirectedGraphNode *n = new UndirectedGraphNode(node->label);
        hashTable[node->label] = n;
        n->neighbors.reserve(node->neighbors.size());
        for (UndirectedGraphNode *neighbor : node->neighbors) {
            n->neighbors.emplace_back(clone(neighbor, hashTable));
        }
        return n;
    }

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int, UndirectedGraphNode *> hashTable;
        return clone(node, hashTable);
    }
};

int main() {
    Solution s;
    s.cloneGraph(nullptr);
};