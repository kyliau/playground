#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

// keep the invariant that all descendants of A[index] are <= A[index]
void max_heapify(vector<int>& A, size_t N, int index) {
  assert(index >= 0 && index < N);
  int left = 2 * index + 1;
  int right = 2 * index + 2;
  int largest = index;
  // find the node that has the largest value
  if (left < N && A[left] > A[index]) {
    largest = left;
  }
  if (right < N && A[right] > A[largest]) {
    largest = right;
  }
  if (largest != index) {
    swap(A[index], A[largest]);
    max_heapify(A, N, largest);
  }
}

void heap_sort(vector<int>& A) {
  int N = A.size();
  // first make sure the array obeys the max heap property
  // we start from the parent node of the last node because by definition
  // the leaf nodes already satisfy the max heap property
  int parent = N / 2 - 1;
  for (int i = parent; i >= 0; --i) {
    max_heapify(A, N, i);
  }
  for (int i = N - 1; i > 0; --i) {
    swap(A[0], A[i]);
    max_heapify(A, --N, 0);
  }
}

int main() {
  while(1) {
    int x;
    vector<int> A;
    while (cin >> x) {
      A.emplace_back(x);
    }
    cin.clear();
    cin.ignore(200, '\n');
    heap_sort(A);
    for (const int& a : A) {
      cout << a << " ";
    }
    cout << endl;
  }
  return 0;
}

/*
// Requires that left and right subtrees obey the heap structure
// Parent node will float down
template<typename TYPE, typename COMP>
void binary_heap<TYPE, COMP>::heapify(int node)
{
  int left = 2 * node + 1;
  int right = 2 * node + 2;
  int size = data.size();
  int smallest;
  if (left < size && this->compare(data[node], data[left]))
  {
    smallest = left;
  }
  else
  {
    smallest = node;
  }
  if (right < size && this->compare(data[smallest], data[right]))
  {
    smallest = right;
  }
  if (smallest != node)
  {
    TYPE temp = data[smallest];
    data[smallest] = data[node];
    data[node] = temp;
    heapify(smallest);
  }
}

template<typename TYPE, typename COMP>
void binary_heap<TYPE, COMP>::make_heap()
{
  //Your code.
  int node = data.size() / 2 - 1;
  for (int i = node; i >= 0; i--)
  {
    heapify(i);
  }
}
*/
