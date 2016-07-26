#include <vector>
#include <iostream>
using namespace std;

class TwoDArrayIterator {
    private:
        int i,j;
        const vector<vector<int>>& v;
    public:
        TwoDArrayIterator(const vector<vector<int>>& array)
        : v(array) {
            i = 0;
            j = 0;
            while (i < v.size() && v[i].empty()) {
                ++i;
            }
        }

        bool hasNext() const {
            return i < v.size() && j < v[i].size();
        }

        int next() {
            if (!hasNext()) {
                return -1;
            }
            int next = v[i][j++];
            if (j == v[i].size()) {
                ++i;
                j = 0;
            }
            while (i < v.size() && v[i].empty()) {
                ++i;
            }
            return next;
        }
};

int main() {
    vector<vector<int>> v = { {}, {3,4,5}, {}, {1}, {6,7}, {2}, {} };
    TwoDArrayIterator it(v);
    while (it.hasNext()) {
        cout << it.next() << endl;
    }
    return 0;
}
