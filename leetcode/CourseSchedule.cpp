// TODO: wip

// There are a total of n courses you have to take, labeled from 0 to n - 1.
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
// For example:
// 2, [[1,0]]
// There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
// 2, [[1,0],[0,1]]
// There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
// Note:
// The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
// Hints:
// This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
// Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
// Topological sort could also be done via BFS.

class Solution {
private:
    static const int UNEXPLORED = -1;
    bool visit(const vector<vector<int>>& v, int course, vector<int> *visited, int *currentLabel) {
        int label = visited->at(course);
        if (label > 0) {
            return *currentLabel < label;
        }
        for (int c : v[course]) {
            if (!visit(v, c, visited, currentLabel)) {
                return false;
            }
        }
        (*visited)[course] = *currentLabel;
        --(*currentLabel);
        return true;
    }
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> v(numCourses);
        vector<int> visited(numCourses, UNEXPLORED);
        for (const auto& p : prerequisites) {
            v[p.second].emplace_back(p.first);
        }
        int label = numCourses;
        for (int i = 0; i < numCourses; ++i) {
            if (!visit(v, i, &visited, &label)) {
                return false;
            }
        }
        return true;
    }
};
