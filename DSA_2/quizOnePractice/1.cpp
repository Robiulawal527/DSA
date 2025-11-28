#include <iostream>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string word; 

    cout <<"Enter a string: ";
    cin >> word; 
    //cout << "You have entered: " << word << endl; 

    stack<char> st; 

    for(char c: word) st.push(c); 

    string rev; 

    int len = word.length();

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    
    return 0;
}
