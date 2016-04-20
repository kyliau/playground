Please compile with flag -std=c++11
Tested on CAEN g++ version 4.7.0

mystruct2 is replaced with structure name NDFSA.
The struct definition is as follows.

Assumption: each alphabet is (exactly) one character long.

struct NDFSA
{
  set<string> states;
  vector<string> alphabets;
  multimap<string, string> transitions;
  vector<string> initial_states;  // there can be more than one initial state
  set<string> final_states;
}

NDFSA is read from file ndfsa.txt arranged in the following format.

line 01: allowable states separated by spaces
line 02: allowable alphabets separated by spaces
line 03: number of transitions (one line for each transition)
line 04: current_state,symbol next_state
line 05: current_state,symbol next_state
line 06: current_state,symbol next_state
line 07: starting states
line 08: final states (there can be more than one)

Resulting DFSA is written to output file equaldfsa.txt