
// Lesson 3 - Prefix Sums
// GenomicRangeQuery
// Find the minimal nucleotide from a range of sequence DNA.

// The idea is to keep track of how many ACGTs I have seen so far while
// iterating through the characters in S.

#include <map>
#include <cstring>
vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {

    map<char, int> dna {{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};
    unsigned N = S.size(), M = P.size();
    unsigned table[N][4]; // this is not standard C++
    unsigned count[4] {0};

    for (unsigned i = 0; i < N; i++) {
      count[dna[S[i]]-1]++;
      memcpy(*(table+i), count, sizeof(count));
    }

    vector<int> result(M, 1);
    for (unsigned i = 0; i < M; ++i) {
      for (int j = 0; j < 4; ++j) {
        int temp = table[Q[i]][j];
        if (P[i] > 0) {
          temp -= table[P[i]-1][j];
        }
        if (temp > 0) {
          result[i] = j + 1;
          break;
        }
      }
    }

    return result;
}

