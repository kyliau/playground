#include <iostream>
#include <vector>
#include <unordered_set>
#include <math.h>
#include <assert.h>
using namespace std;

// problem description:
// https://www.hackerrank.com/contests/lambda-calculi-may14/challenges/prison-transport

// we need a disjoint set (union find) data structure
// reference: https://www.youtube.com/watch?v=wSPAjGfDl7Q

class disjoint_set {
  private:
    unsigned size;
    // array a is the crux of the data structure.
    // for elements that isn't the root of the set, a[i] points to the parent
    // for elements that are root, a[i] is -(size of the set)
    int* a;

  public:
    disjoint_set(unsigned n);
    ~disjoint_set();
    int find(int x);
    void merge(int x, int y);
    vector<int> get_group_and_size();
};

// constructor takes in a number n which specifies how many disjoint sets
// there are initially
disjoint_set::disjoint_set(unsigned n) {
  size = n;
  a = new int[n + 1];
  // initially each element's root is itself (size is 1)
  for (int i = 0; i <= n; ++i) {
    a[i] = -1;
  }
  // a[0] is not used
}

// find the "representative" (the root) of the element x
// serves another purpose: change the element's parent pointer to the root
// as it traverses up the tree
// x must be [1..N]
int disjoint_set::find(int x) {
  assert(x > 0 && x <= size);
  if (a[x] < 0) return x; // we are already at the root
  a[x] = find(a[x]);
  return a[x];
}

// merge the set that contains x with the set that contains y
void disjoint_set::merge(int x, int y) {
  int rootx = find(x);
  int rooty = find(y);
  if (rootx == rooty) return;
  assert(a[rootx] < 0 && a[rooty] < 0);
  if (a[rootx] < a[rooty]) {
    // since the size is stored as negative value, here the size of 
    // x tree is larger than the size of y tree
    a[rootx] += a[rooty];
    a[rooty] = rootx;
  } else {
    a[rooty] += a[rootx];
    a[rootx] = rooty;
  }
}

disjoint_set::~disjoint_set() {
  delete [] a;
}

// return a vector that contains the size of each group
// so, vector.size() is the total number of groups in the disjoint set
//     vector[i] is the size of group i
vector<int> disjoint_set::get_group_and_size() {
  vector<int> result;
  for (unsigned i = 1; i <= size; ++i) {
    if (a[i] < 0) {
      result.push_back(-a[i]);
    }
  }
  return result;
}

void second_attempt() {
  int N; // number of inmates
  int M; // number of pairs of inamtes
  cin >> N >> M;

  disjoint_set ds(N);

  int x, y;
  while (cin >> x >> y) {
    ds.merge(x, y);
  }
  
  unsigned cost = 0;

  for (int i : ds.get_group_and_size()) {
    cost += ceil(sqrt(i));
  }
  
  cout << cost << endl;
}

// this is the submitted version, but this implementation is incorrect 
// because it doesn't handle merge cases
// for example: N = 4, M = 3, pairs = (1,2) (3,4) (2,3)
// would result in incorrect output
void submitted_solution() {

    vector<unordered_set<int> > v;
    unordered_set<int> individuals;
    unsigned cost = 0;
    
    int N; // number of inmates
    int M; // number of pairs of inmates
    cin >> N >> M;
    
    int x, y;
    while (cin >> x >> y) {
        bool found_set = false;
        // instead of doing a linear search here
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
}

int main() {
    second_attempt();
    return 0;
}
