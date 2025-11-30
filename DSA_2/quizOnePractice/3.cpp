#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout << "Enter a string: ";
    string str; 

    cin >> str; 

    stack<char> s; 


    for(char c : str) s.push(c); 

    string reverseStack; 
    while(!s.empty()){

        reverseStack += s.top();
        s.pop();

    }

    if (str == reverseStack) cout << "Palindrome";
    else cout << "Not Palindrome";

    return 0;
}
