#include <stdio.h>

int binarySearch(int A[], int size);

int main()
{

    int A[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int size = sizeof(A) / sizeof(A[0]);

    int result = binarySearch(A, size);

    printf("%d key is found /n", A[result]);

    return 0;
}

int binarySearch(int A[], int size)
{

    int key = 10;

    int low = 0;
    int high = size - 1;

    while (low <= high)
    {

        int mid = (low + high) / 2;

        if (A[mid] == key)
        {
            return mid;
        }
        else if (A[mid] > key)
        {
            high = mid - 1;
        }
        else if (A[mid] < key)
        {
            low = mid + 1;
        }
    }

    return 0;
}