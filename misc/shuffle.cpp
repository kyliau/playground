// Shuffle an array

#include <vector>
#include <random>
#include <utility>
#include <iterator>
#include <iostream>
#include <chrono>

void shuffle(std::vector<int>& v)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    
    for (size_t i = 0; i < v.size(); ++i) {
        std::uniform_int_distribution<int> distribution(i, v.size() - 1);
        // This distribution produces random integers in a range [a,b]
        // where each possible value has an equal likelihood of being produced.
        size_t indexToShuffle = distribution(generator);
        std::swap(v[i], v[indexToShuffle]);
    }
}

int main()
{
    std::vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    shuffle(v);
    std::ostream_iterator<int> out_it (std::cout, ", ");
    std::copy (v.begin(), v.end(), out_it);
    std::cout << std::endl;
    return 0;
}
