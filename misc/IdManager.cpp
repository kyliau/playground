#include <iostream>
#include <cstdint>
#include <unordered_map>
#include <bitset>
#include <assert.h>
using namespace std;

static const int BIN_SIZE = 256;

class IdManager {

  private:
    using BitSet = std::bitset<BIN_SIZE>;
    uint32_t                   d_counter;
    unordered_map<int, BitSet> d_free;

  public:
    IdManager()
    : d_counter(0)
    {
    }

    uint32_t assign() {
        if (d_free.empty()) {
            return d_counter++;
        }
        auto it = d_free.begin();
        assert(it != d_free.end());
        int label    = it->first;
        BitSet& bits = it->second;
        uint32_t id  = 0;
        for (unsigned i = 0; i < bits.size(); ++i) {
            if (bits[i]) {
                id = label * bits.size() + i;
                bits[i] = 0;
                break;
            }
        }
        if (0 == bits.count()) {
            d_free.erase(it);
        }
        return id;
    }

    void free(uint32_t id) {
        int label    = id / BIN_SIZE;
        BitSet& bits = d_free[label];
        bits[id - label * BIN_SIZE] = 1;
        assert(0 < bits.count());
    }

};

int main() {
    IdManager manager;
    for (int i = 0; i < 10; ++i) {
        uint32_t id = manager.assign();
        cout << "Assign new id: " << id << endl;
        manager.free(id);
    }
}
