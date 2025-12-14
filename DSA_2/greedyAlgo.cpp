#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;          // empty
    v.reserve(5);           // avoid reallocation for first 5 pushes
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    
    cout << "size=" << v.size() << ", cap=" << v.capacity() << "\n";
    for (int x : v) cout << x << ' ';  // 10 20 30
    cout << "\n";

    v[1] = 99;              // modify by index
    cout << v.at(1) << "\n"; // safe access (bounds-checked)
}