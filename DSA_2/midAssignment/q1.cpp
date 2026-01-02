#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    int n; 
    cout << "Enter array size : "; 
    cin >> n; 

    vector <long long> arr(n);

    cout << "Enter array elements: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << "Array Elements are: ";
    for(int i=0; i<n; i++){
        cout << " " << arr[i];
    }



    return 0;
}