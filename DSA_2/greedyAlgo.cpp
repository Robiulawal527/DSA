#include <iostream>
#include <vector>
#include <random>
using namespace std;

    int main()
    {
        int n = 10;
        vector<int> v;
        v.reserve(n);

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(1, 100);

        for (int i = 0; i < n; ++i)
            v.push_back(dist(gen));

        for (int x : v)
            cout << x << ' ';
        cout << "\n";
    }