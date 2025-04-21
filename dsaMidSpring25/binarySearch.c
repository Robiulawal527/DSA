#include <stdio.h>

int binarySearch(int A[], int size);

int main()
{

    int A[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int size = sizeof(A) / sizeof(A[0]);

    binarySearch(A, size);

    return 0;
}

int binarySearch(int A[], int size)
{

    int key = 50;

    int low = 0;
    int high = size -1; 

    while (low <= high){

        int mid = (low + high) / 2;

        if (A[mid] == key){
            
        }
        

    }


    return 0;
}