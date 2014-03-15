#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#include <fstream>
#include <assert.h>
using namespace std;

struct DFSA
{
  vector<string> states;
  vector<string> alphabets;
  map<string, string> transitions;
  string initial_state; // there is only one initial state for DFSA
  vector<string> final_states;
  
  void printToFile()
  {
    ofstream outFile("equaldfsa.txt");
    
    for (auto it = states.begin(); it != states.end(); it++)
    {
      outFile << *it << " ";
    }
    outFile << '\n';
    
    for (auto it = alphabets.begin(); it != alphabets.end(); it++)
    {
      outFile << *it << " ";
    }
    outFile << '\n';
    
    outFile << transitions.size() << '\n';
    
    for (auto it = transitions.begin(); it != transitions.end(); it++)
    {
      outFile << it->first << " " << it->second << '\n';
    }
    
    outFile << initial_state << '\n';
    
    for (auto it = final_states.begin(); it != final_states.end(); it++)
    {
      outFile << *it << " ";
    }
    
    outFile.close();
  }
};

struct NDFSA
{
  set<string> states;
  vector<string> alphabets;
  multimap<string, string> transitions;
  set<string> initial_states;  // there can be more than one initial state
  set<string> final_states;
  
  NDFSA(const char* fname)
  {
    //ifstream inFile("dfsa.txt");
    ifstream inFile(fname);
    string line;
    
    int count = 0;
    while (getline(inFile, line))
    {
      // ignore comment lines
      if (line.find("//") != string::npos)
        continue;
      
      istringstream iss(line);
      string data;
      while (iss >> data)
      {
        switch(count)
        {
          case 0: // states
            states.insert(data);
            break;
          case 1: // alphabets
            alphabets.push_back(data);
            break;
          case 2: // number of transitions and transition set
            for (int i = 0; i < atoi(data.c_str()); i++)
            {
              getline(inFile, line);
              iss.str(line);
              string first, second;
              iss >> first >> second;
              transitions.insert(pair<string,string>(first,second));
            }
            break;
          case 3: // intial_state
            initial_states.insert(data);
            break;
          case 4: // final_states
            final_states.insert(data);
            break;
        }
      }
      count++;
    }
    inFile.close();
  }
};

// convert a set of states to a string (a name for the states in a power set)
string setToString(const set<string>& s)
{
  string result;

  for (auto it = s.begin(); it != s.end(); it++)
  {
    result += it == s.begin() ? *it : '_' + *it; 
  }
  //assert(result.length() > 0);
  if (result.length() == 0) result = "fail";
  return result;
}

// recursively find the empty transition closure
void helper(const multimap<string, string>& tran, const string& state,
            set<string>& result)
{
  auto ret = tran.equal_range(state + ',' + "empty");
  for (auto it = ret.first; it != ret.second; ++it)
  {
    result.insert(it->second);
    helper(tran, it->second, result);
  }
}

// find the empty transition closure
set<string> findClosure(const multimap<string, string>& tran, 
                        const set<string>& states)
{
  set<string> result = states;
  
  for (auto& state : states)
  {
    helper(tran, state, result);
  }
  return result;
}

// given a set of states and a transition table find out the reachable sets
set<string> findReachableStates(const multimap<string, string>& tran, 
                                const set<string>& s,const string& symbol)
{
  set<string> result;
  
  for (auto it = s.begin(); it != s.end(); it++)
  {
    set<string> temp;
    helper(tran, *it, temp);
    for (auto& s : temp)
    {
      result.insert(s);
    }
    /*
    auto it1 = tran.find(*it + ",empty");
    if (it1 != tran.end())
    {
      result.insert(it1->second);
    }
    */
    auto ret = tran.equal_range(*it + ',' + symbol);
    for (auto it2 = ret.first; it2 != ret.second; ++it2)
    {
      result.insert(it2->second);
    }
  }
  return result;
}

DFSA NDFSA_to_DFSA(NDFSA ndfsa)
{
  DFSA dfsa;
  int tempCount = 0;
  
  dfsa.alphabets = ndfsa.alphabets;
  
  multimap<string, string> tran;
  
  for (auto it = ndfsa.transitions.begin(); it != ndfsa.transitions.end(); it++)
  {
    istringstream iss(it->first);
    string first, second;
    getline(iss,first,',');
    getline(iss,second);
    
    // single character transition
    if (second.length() == 1)
    {
      tran.insert(pair<string, string>(it->first, it->second));
    }
    else if (second == "empty") // eliminate empty transitions
    {
      tran.insert(pair<string, string>(it->first, it->second));
      for (unsigned int i = 0; i < dfsa.alphabets.size(); ++i)
      {
        tran.insert(pair<string, string>(first + ',' + dfsa.alphabets[i], 
                                         it->second));
      }
    }
    else  // eliminate multi-character transitions
    {
      ostringstream oss1;
      oss1 << 't' << tempCount++;
      string tempState = oss1.str();
      ndfsa.states.insert(tempState);
      tran.insert(pair<string, string>(first + ',' + second[0], tempState));
      for (unsigned int i = 1; i < second.length() - 1; i++)
      {
        ostringstream oss2;
        oss2 << 't' << tempCount++;
        tran.insert(pair<string, string>(tempState + ',' + second[i], 
                                         oss2.str()));
        tempState = oss2.str();
        ndfsa.states.insert(tempState);
      }
      int end = second.length() - 1;
      tran.insert(pair<string, string>(tempState + ',' + second[end], 
                                       it->second));
    }
  }
  /*
  for (auto it = tran.begin(); it != tran.end(); it++)
  {
    // print out all transitions
    cout << it->first << " " << it->second << endl;
  }
  */
  set<string> allStates;
  
  // convert vector of initial states (there could be more than one) to set
  set<string> initialStates = findClosure(tran, ndfsa.initial_states);
  dfsa.initial_state = setToString(initialStates);
  allStates.insert(dfsa.initial_state);
  
  queue<set<string>> q;
  q.push(initialStates);
  
  // find where we can go from here  
  while (!q.empty())
  {
    set<string> curSet = q.front();
    q.pop();
    /*
    cout << "curSet contains: " << endl;
    for (const string& name : curSet)
    {
      cout << name << " ";
    }
    cout << endl;
    */
    string curState = setToString(curSet);
    // cout << "curState: " << curState << endl;
    // add to the states vector of the DFSA
    dfsa.states.push_back(curState);
    
    // determine if the state is a final state
    set<string> intersection;
    set_intersection(curSet.begin(), curSet.end(), 
                     ndfsa.final_states.begin(), ndfsa.final_states.end(),
                     inserter(intersection, intersection.begin()));
    if (intersection.size() > 0)
    {
      dfsa.final_states.push_back(curState);
    }
    
    for (unsigned int i = 0; i < dfsa.alphabets.size(); ++i)
    {
      set<string> reachable = findReachableStates(tran, curSet, dfsa.alphabets[i]);
      string nextState = setToString(reachable);
      //if (nextState.length() == 0) nextState = "fail";
      // check if the state already exists in the transition
      if (allStates.find(nextState) == allStates.end())
      {
        q.push(reachable);
        allStates.insert(nextState);
      }
      // cout << "current: " << curState << " alphabet: " << dfsa.alphabets[i] 
           // << " next: " << nextState << endl;
      dfsa.transitions[curState + ',' + dfsa.alphabets[i]] = nextState;
    }
  }

  return dfsa;
};

int main()
{
  NDFSA ndfsa("ndfsa.txt");
  DFSA dfsa = NDFSA_to_DFSA(ndfsa);
  dfsa.printToFile();
  return 0;
}