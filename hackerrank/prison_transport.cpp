#include <iostream>
#include <vector>
#include <unordered_set>
#include <math.h>
using namespace std;
int main() {
    
    vector<unordered_set<int> > v;
    unordered_set<int> individuals;
    unsigned cost = 0;
    
    int N; // number of inmates
    int M; // number of pairs of inmates
    cin >> N >> M;
    
    int x, y;
    while (cin >> x >> y) {
        bool found_set = false;
        for (auto& set : v) {
            if (set.count(x) > 0 || set.count(y) > 0) {
                // x and y belong to this set
                set.insert(x);
                set.insert(y);
                found_set = true;
                break;
            }
        }
        if (!found_set) {
            // create a new set for the new group
            unordered_set<int> temp;
            temp.insert(x);
            temp.insert(y);
            v.push_back(temp);
        }
        individuals.insert(x);
        individuals.insert(y);
    }
    // take care of the individuals first
    for (int i = 1; i <= N; i++) {
        if (individuals.count(i) == 0) {
            // these are inmates that are alone and must be transported individually
            cost++;
        }
    }
    // now take care of all the linked groups
    for (const auto& set : v) {
        cost += ceil(sqrt(set.size()));
    }
    
    cout << cost << endl;
    
    return 0;
}