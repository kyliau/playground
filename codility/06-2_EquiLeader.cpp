
// Lesson 6 - Leader
// EquiLeader
// Find the index S such that the leaders of the sequences 
// A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N - 1] are the same.

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

#include <unordered_map>
int solution(vector<int> &A) {

	int N = A.size();
	unordered_map<int, int> map, mymap;

	// first do a scan across the array
	for (int a : A) {
		map[a]++;
	}

	// we need to keep track of the leader in the left half

	int count = 0;
	int equileader = 0;
	int leader = 0;		// leader of the left half
	bool leader_exists = false;

	for (int a : A) {
		int temp = ++mymap[a];
		count++;
	
		// make a the leader if it is more than half
		if (temp > count / 2) {
			leader = a;
			leader_exists = true;
		}

		if (leader_exists) {
			int leader_count = mymap[leader];
			// we need to check whether the current leader is still the leader
			if (leader_count <= count / 2) {
				leader_exists = false;
			} else if (map[leader] - leader_count > (N - count) / 2) {
				// left and right array has the same leader
				equileader++;
			}
		}
	}

	return equileader;
}

int find_leader(const vector<int>& A, int left, int right) {
	if (left > right) return -1;
	unordered_map<int, int> map;
	for (unsigned i = left; i <= right; ++i) {
		int temp = ++map[A[i]];
		if (temp > (right - left + 1) / 2) {
			return A[i];
		}
	}
	return -1;
}



int solution_slow(vector<int>& A) {
	int equileader = 0;
	for (unsigned i = 0; i < A.size() - 1; ++i) {
		int a = find_leader(A, 0, i);
		if (a < 0) continue;
		int b = find_leader(A, i + 1, A.size() - 1); 
		if (a == b) {
			equileader++;
		}
	}
	return equileader;
}

int main() {
	while (1) {
		vector<int> A;
		int x;
		cout << "Enter numbers: ";
		while (cin >> x) {
			if (x < 0) break;
			A.push_back(x);
		}
		cout << "correct = " << solution_slow(A) << "\tequi_leaders = " << solution(A) << endl;
	}
	return 0;
}

