// Design and implement a data structure for Least Recently Used (LRU) cache.
// It should support the following operations: get and set.
// get(key) - Get the value (will always be positive) of the key
//            if the key exists in the cache, otherwise return -1.
// set(key, value) - Set or insert the value if the key is not already present.
//                   When the cache reached its capacity, it should invalidate
//                   the least recently used item before inserting a new item.

class LRUCache {
private:
    typedef list<int>::iterator                   ListIt;
    typedef unordered_map<int, pair<int, ListIt>> Table;
    int       d_size;
    Table     d_table;
    list<int> d_queue;
    void evictLRU() {
        assert(d_table.size() == d_size);
        assert(d_queue.size() == d_size);
        int victim = d_queue.back();
        int elemsErased = d_table.erase(victim);
        assert(1 == elemsErased);
        d_queue.pop_back();
    }
    void moveToFront(Table::iterator it) {
        d_queue.emplace_front(it->first);
        d_queue.erase(it->second.second);
        it->second.second = d_queue.begin();
    }
public:
    LRUCache(int capacity)
    : d_size(capacity) {
        d_table.reserve(capacity);
    }
    
    int get(int key) {
        auto it = d_table.find(key);
        if (it == d_table.end()) {
            return -1;
        }
        moveToFront(it);
        return it->second.first;
    }
    
    void set(int key, int value) {
        auto it = d_table.find(key);
        if (it == d_table.end()) {
            if (d_table.size() == d_size) {
                evictLRU();
            }
            d_queue.emplace_front(key);
            d_table[key] = { value, d_queue.begin() };
        } else {
            it->second.first = value;
            moveToFront(it);
        }
    }
};
