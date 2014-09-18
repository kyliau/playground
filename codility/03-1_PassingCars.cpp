
// Lesson 3 - Prefix Sums
// PassingCars
// Count the number of passing cars on the road.

int solution(vector<int> &A) {
    unsigned sum = 0;
    for (int a : A) {
        sum += a;
    }
    unsigned count = 0;
    for (int a : A) {
        if (a == 0) {
            count += sum;
            if (count > 1e9) {
                return -1;
            }
        } else {
            sum--;
        }
    }
    return count;
}


