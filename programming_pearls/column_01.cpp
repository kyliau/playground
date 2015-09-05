
// Code structure from book:
// Phase 1 : Initialize set to empty
// Phase 2 : Insert present elements into the set
// Phase 3 : Write sorted output (to file or to screen)
//
// Notes:
// - Number is [0, 10,000,000)
// - Use a bitmap data structure
//
// So, we need 10^7 bits / 8 bits per byte = 1250000 bytes

#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <cassert>

class Bitmap {
  private:
    static const int MAX  = 1e7;
    static const int SIZE = MAX / 8;    // approx. 1 MB
    uint8_t d_array[SIZE];

  public:
    Bitmap();

    bool get(int x) const;

    void set(int x);

};

inline
Bitmap::Bitmap()
{
    std::cout << "Constructor begin" << std::endl;
    // use a loop, or we can be fancy and use memset
    for (int i = 0; i < SIZE; ++i) {
        d_array[i] = 0;
    }
    std::cout << "Constructor end" << std::endl;
}

inline
bool Bitmap::get(int x) const
{
    if (x < 0 || x >= MAX) {
        return false;
    }
    int index        = x / 8;
    int bytePosition = x % 8;
    return (d_array[index] & (1 << bytePosition));
}

inline
void Bitmap::set(int x)
{
    if (x < 0 || x >= MAX) {
        return;                                                       // RETURN
    }
    int index        = x / 8;
    int bytePosition = x % 8;
    d_array[index] |= (1 << bytePosition);
}

int main()
{
    Bitmap bitmap;
    for (int i = 0; i < 100; i += 2) {
        std::cout << i << std::endl;
        bitmap.set(i);
        assert(bitmap.get(i));
        assert(!bitmap.get(i + 1));
    }
    return 0;
}
