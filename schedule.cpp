#include <iostream>
#include <vector>
using namespace std;

vector<char> copyExcept(const vector<char>& ori, char A, char B) {
	vector<char> copy;
	for (char c : ori) {
		if (c != A && c != B) {
			copy.push_back(c);
		}
	}
	return copy;
}

void print(char A, char B, int round) {
	cout << "Round " << round << ": Team " << A << " plays Team " << B << endl;
}

void generate(const vector<char>& teams, int round) {
	if (teams.size() <= 2) {
		print(teams[0], teams[1], round);
		return;
	}
	char current = teams[0];
	for (unsigned i = 1; i < teams.size(); ++i) {
		print(current, teams[i], round + i - 1);
		generate(copyExcept(teams, current, teams[i]), round + i - 1);
	}
}

int main() {
	int num;
	cout << "Number of teams: ";
	cin >> num;
	vector<char> teams;
	for (int i = 0; i < num; i++) {
		teams.push_back('A' + i);
	}
	generate(teams, 1);
	return 0;
}
