#include <iostream>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout << "Enter a string: ";
    string s;
    cin >> s;
    
    cout << s << "\n"; 


    stack<char> st; 

    for(char c: s) st.push(c);

    string reverseStack = " "; 

    while (!st.empty()){
        reverseStack += st.top();
        st.pop();
    }

    cout << reverseStack; 

    
    return 0;
}