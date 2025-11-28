#include <iostream>
#include<map>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str; 
    cout << "Enter a string: ";

    cin >> str; 

    map<char, int> freq; 

    for(char c: str) freq[c]++; 

    for(auto it: freq) cout << it.first << " --> " << it.second << endl;


    
    return 0;
}