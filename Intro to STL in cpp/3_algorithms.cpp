#include <bits/stdc++.h>

using namespace std;

template <typename T>
void printVector(const vector<T> &vec)
{
    for (const T i : vec)
    {
        cout << i << " ";
    }
    cout << "\n";
}

int main()
{
    vector<int> v = {1, 9, 1, 4, 2, 9, 3};
    // sorting
    sort(v.begin(), v.end()); // ascending order
    // stable_sort(v.begin(), v.end()); // stable ascending order
    printVector(v);
    sort(v.begin(), v.end(), greater<int>()); // descending order sort
    printVector(v);

    // searching
    vector<int> v2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << binary_search(v2.begin(), v2.end(), 2) << "\n";
    cout << binary_search(v2.begin(), v2.end(), 10) << "\n";

    // min-max
    cout << min(10, 0) << "\n";                         // min element between two
    cout << max(100, 10) << "\n";                       // max element between two
    cout << *min_element(v2.begin(), v2.end()) << "\n"; // min element in the vector
    cout << *max_element(v2.begin(), v2.end()) << "\n"; // max element in the vector

    // reverse element
    reverse(v2.begin(), v2.end());
    printVector(v2);

    // counting
    count(v2.begin(), v2.end(), 2); // count the number of times 2 appears
    count_if(v2.begin(), v2.end(), [](int n)
             { return n % 2 == 0; }); // count the number of even elements in the vector. YOU DO NOT NEED IT FOR THIS COURSE, BUT JENE RAKHLE NO PROB. THIS IS AN INTERESTING CONCEPT

    // summation
    accumulate(v2.begin(), v2.end(), 0);  // sum up all the elements, sum starts from 0
    accumulate(v2.begin(), v2.end(), 10); // sum up all the elements, sum starts from 10
}