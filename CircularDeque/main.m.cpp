#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> v;
    cout << v.capacity() << endl;

    v.emplace_back(0);
    cout << v.capacity() << endl;

}
