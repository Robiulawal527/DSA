#include <iostream>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
        cin >> n;
        
        vector<long long> freqCount(n);
        
        long long total_freqCount = 0;
        for (int i = 0; i < n; i++) {
            cin >> freqCount[i];
            total_freqCount += freqCount[i];
        }
        
        if (n <= 1) {
            cout << 0 << endl;
        }

        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (auto f : freqCount) {
            pq.push(f);
        }
        
        long long totalBitsNumber = 0;
        
        while (pq.size() > 1) {
            long long a = pq.top(); pq.pop();
            long long b = pq.top(); pq.pop();
            
            long long merge = a + b;
            totalBitsNumber += merge;
            
            pq.push(merge);
        }
        
        cout << totalBitsNumber << endl;
    
    return 0;
}