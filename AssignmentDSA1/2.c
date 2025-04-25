#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mostFrequent(int arr[], int n)
{
    int freq[101] = {0};  // Values range from 1 to 100

    // Count frequency
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    // Find max frequency
    int maxFreq = 0;
    for (int i = 1; i <= 100; i++)
    {
        if (freq[i] > maxFreq)
            maxFreq = freq[i];
    }

    // Print all values with max frequency
    printf("\nMost frequent value(s): ");
    for (int i = 1; i <= 100; i++)
    {
        if (freq[i] == maxFreq)
        {
            printf("%d ", i);
        }
    }
    printf("occurred %d times\n", maxFreq);
}

int main()
{
    int N;
    printf("Enter N: ");
    scanf("%d", &N);

    int arr[N];
    srand(time(0));

    printf("Random values: ");
    for (int i = 0; i < N; i++)
    {
        arr[i] = (rand() % 100) + 1;
        printf("%d ", arr[i]);
    }
    printf("\n");

    mostFrequent(arr, N);

    return 0;
}
