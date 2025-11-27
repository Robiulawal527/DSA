#include <bits/stdc++.h>

using namespace std;

template <typename T>
void printMap(map<T, T> &mp)
{
    for (const auto i : mp)
    {
        cout << i.first << " -- " << i.second << "\n";
    }
}

int main()
{
    // init
    map<int, int> mp;

    // insertion
    mp.insert({1, 2});
    mp.insert({1, 3}); // ignore because 1 is already there
    mp.insert({1, 4}); // ignore too
    mp.insert({2, 4}); // add
    mp.insert({0, 1});
    printMap(mp);

    // deletion
    mp.erase(1); // remove key 1
    printMap(mp);

    // clear map
    // mp.clear();

    // accessing elements
    cout << mp[1] << "\n";    // mp[key], not found? inserts new key
    cout << mp.at(1) << "\n"; // mp.at(key), not found? does nothing

    // finding elements
    bool isPresent = mp.count(1); // 1 -> in map. 0 -> not in map. makes more sense for mutimap
    // or
    bool isPresent = mp.find(1) != mp.end(); // will be true if 1 is in map. 0 if 1 is not in map

    // find size
    mp.size();
    // check if map is empty
    mp.empty();
}