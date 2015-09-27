#include <vector>
#include <random>
#include <utility>

void shuffle(vector<int> *v) {
    std::random_device rd;
    std::default_random_engine gen(rd());
    for (int i = 0; i < v->size(); ++i) {
        std::uniform_int_distribution<int> dis(i, v->size() - 1);
        int randomNumber = dis(gen);
        swap(v->at(i), v->at(randomNumber));
    }
}

int main() {
    std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    shuffle(&v);
}
