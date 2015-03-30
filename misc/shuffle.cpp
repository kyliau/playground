// Shuffle an array

#include <vector>
#include <random>
#include <utility>

typedef vector<int>::iterator VectorIt;

void shuffleHelper(VectorIt begin, VectorIt end)
    // 'begin' points to the first element,
    // 'end' points to one past the last element
{
    if (begin >= end) {
        return;
    }
    size_t numElements = end - begin;
    
    // This distribution produces random integers in a range [a,b]
    // where each possible value has an equal likelihood of being produced.
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, numElements - 1);
    
    size_t indexToShuffle = distribution(generator);
    
    swap(*(begin + indexToShuffle), *(end - 1));
}

void shuffle(vector<int>& v)
{
    for (size_t i = 0; i < v.size(); ++i) {
        shuffleHelper(v.begin(), v.end() - i);
    }
}
}
