// TODO: wip

// There are a total of n courses you have to take, labeled from 0 to n - 1.
// Some courses may have prerequisites, for example to take course 0
// you have to first take course 1, which is expressed as a pair: [0,1]
// Given the total number of courses and a list of prerequisite pairs,
// is it possible for you to finish all courses?
//
// For example:
// 2, [[1,0]]
// There are a total of 2 courses to take. To take course 1
// you should have finished course 0. So it is possible.
//
// 2, [[1,0],[0,1]]
// There are a total of 2 courses to take. To take course 1
// you should have finished course 0, and to take course 0
// you should also have finished course 1. So it is impossible.
//
// Note:
// The input prerequisites is a graph represented by a list of edges,
// not adjacency matrices. Read more about how a graph is represented.
// Hints:
// This problem is equivalent to finding if a cycle exists in a directed graph.
// If a cycle exists, no topological ordering exists and therefore it will be
// impossible to take all courses.
// Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera
// explaining the basic concepts of Topological Sort.
// Topological sort could also be done via BFS.

// Test case
// 8
// [[1,0],[2,6],[1,7],[6,4],[7,0],[0,5]]

class Solution {
    bool visit(const vector<vector<int>>& v, int course, int origin, vector<bool> *visited) {
        if (visited->at(course)) {
            return true;
        }
        (*visited)[course] = true;
        for (int c : v[course]) {
            if (c == origin || !visit(v, c, origin, visited)) {
                return false;
            }
        }
        (*visited)[course] = false;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> v(numCourses);
        vector<bool> visited(numCourses, false);
        for (const auto& p : prerequisites) {
            v[p.second].emplace_back(p.first);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!visit(v, i, i, &visited)) {
                return false;
            }
        }
        return true;
    }
};
