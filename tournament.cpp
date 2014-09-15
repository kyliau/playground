#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
void print(char A, char B, unsigned round) {
  cout << "Round " << round << ": " << A << " vs. " << B << endl;
}

void generate_schedule(vector<char> teams, unsigned round) {
  unsigned N = teams.size();
  if (N <= 1) return;
  if (N == 2) {
    print(teams[0], teams[1], round);
    return;
  }
  for (unsigned i = 0; i < N / 2; i++) {
    for (unsigned j = 0; j < ceil(0.5 * N); j++) {
      print(teams[j], teams[j + N / 2], round);
    }
    round++;
    auto mid = teams.begin() + N / 2;
    rotate(mid, mid + 1, teams.end());
  }
  generate_schedule(vector<char>(teams.begin(), teams.begin() + N / 2), round);
  generate_schedule(vector<char>(teams.begin() + N / 2, teams.end()), round);
}


// for now assume a power of 2
int main() {
  char teams[26];
  for (unsigned i = 0; i < 26; ++i) {
    teams[i] = (char)('A' + i);
  }
  while(1) {
    cout << "Enter number of teams: ";
    unsigned total;
    cin >> total;
    generate_schedule(vector<char>(teams, teams + total), 1);
  }
}
