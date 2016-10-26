// Design a data structure that supports all following operations in
// average O(1) time.

// insert(val): Inserts an item val to the set if not already present.
// remove(val): Removes an item val from the set if present.
// getRandom  : Returns a random element from current set of elements.
//              Each element must have the same probability of being returned.

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <random>

using namespace std;

class RandomizedSet {
private:
    std::default_random_engine d_engine;
    // map the key to the index of the key in 'd_vector'
    unordered_map<int, int>    d_map;
    vector<int>                d_vector;

public:
    /**
     * Initialize your data structure here.
     */
    RandomizedSet()
    : d_engine(std::random_device()())
    {    
    }
    
    /**
     * Inserts a value to the set. Returns true if the set did not already
     * contain the specified element.
     */
    bool insert(int val) {
        if (d_map.end() == d_map.find(val)) {
            d_vector.emplace_back(val);
            d_map[val] = d_vector.size() - 1;
            return true;
        }
        return false;
    }
    
    /**
     * Removes a value from the set.
     * Returns true if the set contained the specified element.
     */
    bool remove(int val) {
        auto it = d_map.find(val);
        if (d_map.end() == it) {
            return false;
        }
        int index = it->second;
        d_map[d_vector.back()] = index;
        std::swap(d_vector.back(), d_vector[index]);
        d_vector.pop_back();
        d_map.erase(it);
        return true;
    }
    
    /**
     * Get a random element from the set.
     */
    int getRandom() {
        std::uniform_int_distribution<int> dis(0, d_vector.size() - 1);
        int n = dis(d_engine);
        return d_vector[n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
