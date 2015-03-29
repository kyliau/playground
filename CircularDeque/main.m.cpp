#include <vector>
#include <iostream>
using namespace std;

int main()
{
    cout << -6 % 5 << endl;
    cout << int() << endl;
    vector<int> v;
    cout << v.capacity() << endl;

    v.emplace_back(0);
    cout << v.capacity() << endl;

    v.emplace_back(1);
    cout << v.capacity() << endl;

    v.emplace_back(2);
    v.emplace_back(3);
    cout << v.capacity() << endl;

    v.resize(0);
    cout << "size = " << v.size() << ", capacity = " << v.capacity() << endl;

    v.clear();
    cout << v[2] << endl;
}
