#include <iostream>
using namespace std;

#include <stdlib.h>


typedef long long ll;


int recursiveCall(int arr[], int n){

    
    int i = 0; 

    cout << arr[i]; 

    i++; 

    if(int i = n) return 1;
    else recursiveCall(arr,n); 

    return 0; 

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; 

    cin >> n; 

    int arr[n];

    // set seed time to null 
    srand(time(NULL));

    for(int i=0; i<n; i++){

        // generate random number each iteration.
        int x = rand() % 100;

        // asign to the array's i th index
        arr[i] = x;
    }

    // printing the array in one line

    //for(int i=0; i<n; i++) cout << arr[i] <<" ";

    //printint the array using recursion

    recursiveCall(arr, n);

    
    
    return 0;
}