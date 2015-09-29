// wip

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
