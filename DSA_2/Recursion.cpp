#include <iostream>
using namespace std;

#include <stdlib.h>


typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; 

    cin >> n; 

    int arr[n];

    srand(time(NULL));

    for(int i=0; i<n; i++){
        int x = rand() % 100;
        arr[i] = x;
    }

    for(int i=0; i<n; i++) cout << arr[i] <<" ";






    
    
    return 0;
}