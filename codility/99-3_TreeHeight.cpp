// Lesson 99 - Future Training
// TreeHeight
// Compute the height of a binary link-tree.

int solution(tree * T) {
    // write your code in C++11
    if (T == nullptr) return -1;
    return 1 + max(solution(T->l), solution(T->r));
}
