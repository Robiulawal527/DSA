// #include <bits/stdc++.h> // just including this will give you all the libs at the tradeoff of slower compilation
#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int> &vec)
{
    for (int i : vec)
        cout << i << " ";
    cout << "\n";
}



int main()
{
    // init a vector
    vector<int> vec = {1, 2, 3, 4, 5, 6};
    // access
    cout << vec[0] << "\n";              // access the first element.
    cout << vec.front() << "\n";         // another way of accessing the first element
    cout << vec.size() << "\n";          // size
    cout << vec[vec.size() - 1] << "\n"; // access the last element
    cout << vec.back() << "\n";          // another way of accessing the last element
    cout << vec.at(2) << "\n";           // accessing the element at index 2

    // iterations
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }
    cout << "\n";
    // or
    for (int i : vec)
    {
        cout << i << " ";
    }
    cout << "\n";
    // or
    vector<int>::iterator it;
    for (it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << "\n";
    }

    // init pt 2. blank init; with size
    vector<int> vec2, vec3(10);
    // adding elements
    vec2.push_back(1);
    vec2.push_back(2);
    vec2.push_back(3);
    vec2.push_back(4);
    vec2.push_back(5);
    // removing elements
    vec2.pop_back(); // remove last inserted element
    vec2.empty();    // clear the vector

    // 2D vectors
    vector<vector<int>> twod_vec;
    // creating a matrix
    twod_vec.push_back({1, 2, 3, 4, 5});
    twod_vec.push_back({6, 7, 8});
    twod_vec.push_back({9, 10, 11, 12});
    for (vector<int> i : twod_vec)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }

    // insert at a specific position
    vec2.insert(vec2.begin() + 2, 10);
    printVector(vec2);
    vec2.insert(vec2.begin() + 2, {10, 20, 30});
    printVector(vec2);

    // erase from specific position(s)
    vec2.erase(vec2.begin() + 2); // erase at index 2
    printVector(vec2);
    vec2.erase(vec2.begin() + 2, vec2.begin() + 2 + 3);
    printVector(vec2);
}