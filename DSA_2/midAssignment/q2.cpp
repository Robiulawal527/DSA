#include <iostream>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
        cin >> n >> m;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        sort(a.begin(), a.end());
        
        int best = INT_MAX;
        
        for (int i = 0; i <= n - m; i++) {
            int diff = a[i + m - 1] - a[i];
            if (diff < best) {
                best = diff;
            }
        }
        
        cout << best << endl;
    
    return 0;
}