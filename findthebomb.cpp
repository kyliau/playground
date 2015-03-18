#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// returns true if there is a bomb in the sorted array v
// a bomb is defined as three consecutive distinct pairs
bool findTheBomb(const vector<int>& v)
{
    if (v.size() < 6 || !is_sorted(v.begin(), v.end())) {
        return false;
    }
    
    for (int i = 0; i <= v.size() - 6; ++i) {
        if (v[i] == v[i + 1] &&
            v[i + 2] == v[i + 3] &&
            v[i + 4] == v[i + 5] &&
            v[i] < v[i + 2] &&
            v[i + 2] < v[i + 4]) {
            return true;
        }
    }
    
    return false;
}

int main()
{
    vector<int> v1 = { 1, 1, 2, 2, 3, 3 };
    vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
    cout << findTheBomb(v1) << endl;
    cout << findTheBomb(v2) << endl;
    return 0;
}
