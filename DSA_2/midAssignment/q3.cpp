#include <iostream>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
        cin >> n;
        
        vector<long long> freq(n);
        long long total_freq = 0;
        for (int i = 0; i < n; i++) {
            cin >> freq[i];
            total_freq += freq[i];
        }
        
        if (n <= 1) {
            cout << 0 << endl;
        }
        
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (auto f : freq) {
            pq.push(f);
        }
        
        long long total_bits = 0;
        
        while (pq.size() > 1) {
            long long a = pq.top(); pq.pop();
            long long b = pq.top(); pq.pop();
            
            long long merge = a + b;
            total_bits += merge;
            
            pq.push(merge);
        }
        
        cout << total_bits << endl;
    
    return 0;
}