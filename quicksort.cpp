#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

// generates a number that is in [min, max]
// this serves as a place holder for better implementation, such as 
// median of medians
int pick_index(int min, int max) {
	// simple implementation:
	return min + (max - min) / 2;
}

// partition the array A[left]..A[right] such that A[index] is in its 
// final sorted position and all elements to the left are <= than A[index]
// and all elements to the right are > than A[index]
// (This algorithm is tricky and I got it wrong many times, in the end
//  I referred to CLRS, so this is from CLRS with slight modification)
int partition(vector<int>& A, int left, int right, int index) {

	assert(index >= left && index <= right);

	int target = A[index];

  // place target in the right most position
	swap(A[index],A[right]);

  int i = left;
  for (int j = left; j < right; ++j) {
    if (A[j] <= target) {
      swap(A[i], A[j]);
      i++;
    }
  }
  
  swap(A[i], A[right]);

  return i;
}

// sort the vector v from v[left] to v[right] (inclusive)
void quicksort(vector<int>& A, int left, int right) {

	if (left >= right) return;

	// randomly pick an element within [left, right]
	int index = pick_index(left, right);

	index = partition(A, left, right, index);

	// at this point v[index] is at the correct location in the sorted array
	// all elements to the left of A[index] are <= A[index], all elements to the
	// right are > A[index]
	quicksort(A, left, index-1);
	quicksort(A, index+1, right);
}

void quicksort(vector<int>& A) {
	quicksort(A, 0, A.size() - 1);
}

int main() {
	vector<int> A {5,2,6,3,7,8,9,3,29,0,-5,47,92,-33,0,1,50,16,-3,4,0};
	quicksort(A);
	cout << "sorted array: " << endl;
	for (int a : A) {
		cout << a << " ";
	}
	cout << endl;
	return 0;
}
