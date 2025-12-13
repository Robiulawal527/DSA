#include <iostream>
#include <set>
#include <unordered_set>
#include <iterator>

using namespace std;

// ignore the details on this function. you can do a deep study on it
// basically, a template allows us to work with whatever datatype we give it
// template basically bole "this function will work with any dtype"
// compiler automatically deduces the template T from the args you pass
template <typename T>
void printSet(const set<T> &s)
{
    for (const T i : s)
    {
        cout << i << " ";
    }
    cout << "\n";
}

int main()
{
    // init
    set<int> s = {1, 2, 3, 4, 4}; // duplicate 4 wont be added
    printSet(s);

    // also init
    set<int> _set;
    // adding elements
    _set.insert(10);
    _set.insert(20);
    _set.insert(40); // regardless of add, a set keeps elements in sorted order
    _set.insert(30);
    // find an element
    set<int>::iterator isPresent = _set.find(30);
    cout << (isPresent == _set.end()) << "\n";

    // _set.empty() // empty set
    // _set.erase(20); // erase by value
    // removing at a specific index is a pain
    auto it = next(_set.begin(), 2); // use std::next for this. to remove index = 2, just start from the first it, then move 2.
    _set.erase(it);                  // next erase the it (remember an it is a pointer)
    printSet(_set);

    // set -> implemented in cpp using a self-balancing bin tree. maintains elements in sorted order
    // unordered_set -> implemented using hash table. elements stored according to hash values. no specific order
    unordered_set<int> us;

    // when to use which?
    // set -> preferred when maintaining sorted order of elements is important or when operations like finding the predecessor or successor of an element are required
    // unordered_set -> preferred when the order of elements is not important, and fast average-case performance for insertions, deletions, and lookups is crucial
}