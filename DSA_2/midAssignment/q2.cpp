#include <iostream>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
        cin >> n >> m;
        
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {

            cin >> arr[i];

        }

        // sorting to find minimum best
        
        sort(arr.begin(), arr.end());
        
        int bestMinimum = INT_MAX;
        
        for (int i = 0; i <= n - m; i++) {
            int difference = arr[i + m - 1] - arr[i];
            if (difference < bestMinimum) {
                bestMinimum = difference;
            }
        }
        
        cout << bestMinimum << endl;
    
    return 0;
}