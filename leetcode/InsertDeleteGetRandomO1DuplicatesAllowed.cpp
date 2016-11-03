// Design a data structure that supports all following operations in average
// O(1) time.

// Note: Duplicate elements are allowed.
// insert(val): Inserts an item val to the collection.
// remove(val): Removes an item val from the collection if present.
// getRandom  : Returns a random element from current collection of elements.
//              The probability of each element being returned is linearly
//              related to the number of same value the collection contains.

#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <random>
#include <cassert>
#include <iostream>

using namespace std;

void print(const unordered_map<int, unordered_set<int>>& m) {
    for (const auto& p : m) {
        cout << '\t' << p.first << ": ";
        for (int i : p.second) {
            cout << i << " ";
        }
        cout << endl;
    }
}

void print(const vector<int>& v) {
    cout << '\t';
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}

class RandomizedCollection {
private:
    std::default_random_engine             d_engine;
    unordered_map<int, unordered_set<int>> d_map;
    vector<int>                            d_vector;

public:
    /** Initialize your data structure here. */
    RandomizedCollection()
    : d_engine(std::random_device()())
    {    
    }
    
    /**
     * Inserts a value to the collection. Returns true if the collection
     * did not already contain the specified element.
     */
    bool insert(int val) {
        int count = d_map.count(val);
        d_vector.emplace_back(val);
        d_map[val].insert(d_vector.size() - 1);
        return 0 == count;
    }
    
    /**
     * Removes a value from the collection. Returns true if the collection
     * contained the specified element.
     */
    bool remove(int val) {
        auto it = d_map.find(val);
        if (d_map.end() == it) {
            return false;
        }
        auto victim = it->second.begin();
        int last    = d_vector.back();
        d_vector.pop_back();
        if (last == val) {
            victim = it->second.find(d_vector.size());
            assert(it->second.end() != victim);
        } else {
            int index = *victim;
            d_vector[index] = last;
            unordered_set<int>& set = d_map[last];
            int count = set.erase(d_vector.size());
            assert(1 == count);
            auto p = set.insert(index);
            assert(true == p.second);
        }
        if (it->second.size() == 1) {
            d_map.erase(it);
        } else {
            it->second.erase(victim);
        }
        return true;
    }
    
    /**
     * Get a random element from the collection.
     */
    int getRandom() {
        std::uniform_int_distribution<int> dis(0, d_vector.size() - 1);
        int n = dis(d_engine);
        return d_vector[n];
    }

    void print() {
        cout << "d_map" << endl;
        ::print(d_map);
        cout << "d_vector" << endl;
        ::print(d_vector);
        cout << endl;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main() {
    {
        RandomizedCollection c;
        assert(true  == c.insert(1));
        assert(false == c.insert(1));
        assert(true  == c.insert(2));
        assert(false == c.insert(1));
        assert(false == c.insert(2));
        assert(false == c.insert(2));
        assert(true  == c.remove(1));
        assert(true  == c.remove(2));
        assert(true  == c.remove(2));
        assert(true  == c.remove(2));
    }
    {
        RandomizedCollection c;
        assert(true  == c.insert(0));
        assert(true  == c.remove(0));
        assert(true  == c.insert(-1));
        assert(false == c.remove(0));
        assert(-1    == c.getRandom());
        assert(-1    == c.getRandom());
        assert(-1    == c.getRandom());
        assert(-1    == c.getRandom());
        assert(-1    == c.getRandom());
        assert(-1    == c.getRandom());
        assert(-1    == c.getRandom());
        assert(-1    == c.getRandom());
        assert(-1    == c.getRandom());
        assert(-1    == c.getRandom());
    }
    {
        RandomizedCollection c;
        assert(true  == c.insert(0));
        assert(true  == c.remove(0));
        assert(false == c.remove(0));
        assert(true  == c.insert(0));
        assert(0     == c.getRandom());
    }
    return 0;
}
