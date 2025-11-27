#include <bits/stdc++.h>

using namespace std;

int main()
{
    // init
    stack<int> st;

    // push
    st.push(10); // Add to top
    st.push(20);
    st.push(30);
    st.push(40); // on top

    cout << "Top " << st.top() << "\n"; // doesnt remove the element just shows it
    cout << "Size: " << st.size() << "\n";
    cout << "Empty? " << st.empty() << "\n";

    st.pop(); // remove top element
    cout << "After pop, top: " << st.top() << "\n";

    // iteration (ik ik you can also write the template function here, for this lesson, i choose not to)
    while (!st.empty())
    {
        cout << st.top() << " "; // 30 20 10
        st.pop();
    }
    cout << "\n";

    // ex: string reversal
    stack<char> charStack;
    string str = "hello";
    for (char c : str)
    {
        charStack.push(c);
    }
    string reversed = "";
    while (!charStack.empty())
    {
        reversed += charStack.top();
        charStack.pop();
    }
    cout << "Reversed string: " << reversed << "\n";
}