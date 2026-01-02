#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProductKadane(const vector<long long>& arr) {
    int n = arr.size();
    if (n == 0) return 0;

    int global_max = arr[0];
    int curr_max = arr[0];
    int curr_min = arr[0];

    for (int i = 1; i < n; i++) {
        int temp = curr_max;

        curr_max = max({arr[i], temp * arr[i], curr_min * arr[i]});
        curr_min = min({arr[i], temp * arr[i], curr_min * arr[i]});

        global_max = max(global_max, curr_max);
    }

    return global_max;
}


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

    cout << " " << endl; 


    cout << "Maximum Product: " << maxProductKadane(arr) << endl;


    return 0;
}