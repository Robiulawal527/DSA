#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Enter a string : ";
    string s;
    cin >> s; // reads a bracket string without spaces

    stack<char> st;

    for (char c : s) {
        if (c == '(') st.push(')');
        else if (c == '{') st.push('}');
        else if (c == '[') st.push(']');
        else if (c == ')' || c == '}' || c == ']') {
            if (st.empty() || st.top() != c) {
                cout << "False\n";
                return 0; // early exit on mismatch or extra closing
            }
            st.pop();
        } 
        else {
            // if other characters are not expected, treat as invalid
            cout << "False\n";
            return 0;
        }
    }

    cout << (st.empty() ? "True\n" : "False\n");
    return 0;
}
