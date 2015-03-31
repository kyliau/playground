// Shuffle an array

#include <vector>
#include <random>
#include <utility>
#include <iterator>
#include <iostream>
#include <chrono>


typedef std::vector<int>::iterator VectorIt;

void shuffleHelper(VectorIt                    begin,
                   VectorIt                    end,
                   std::default_random_engine& generator)
    // 'begin' points to the first element,
    // 'end' points to one past the last element
{
    if (begin >= end) {
        return;
    }
    size_t numElements = end - begin;

    // This distribution produces random integers in a range [a,b]
    // where each possible value has an equal likelihood of being produced.
    std::uniform_int_distribution<int> distribution(0, numElements - 1);

    size_t indexToShuffle = distribution(generator);

    std::swap(*(begin + indexToShuffle), *(end - 1));
}

void shuffle(std::vector<int>& v)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    //std::default_random_engine generator;
    std::ostream_iterator<int> out_it (std::cout, ", ");
    for (size_t i = 0; i < v.size(); ++i) {
        shuffleHelper(v.begin(), v.end() - i, generator);
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
