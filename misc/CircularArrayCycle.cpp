// Given a circular array of relative indices, determine if it contains a
// single, complete cycle.

bool hasSingleCompleteCycle(const vector<int>& v) {
    const int start = 0;       // starting position
    int position = start;
    for (int i = 0; i < v.size(); ++i) {
        position = (position + v[position]) % v.size();
        if (position < 0) {
            position += v.size();
        }
        if (position == start) {
            return false;
        }
    }
    return position == start;
}
