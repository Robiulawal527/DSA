#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mostFreq(int arr[], int n)
{
    int freq[101] = {0};  


    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }


    int maxFreq = 0;
    for (int i = 1; i <= 100; i++)
    {
        if (freq[i] > maxFreq)
            maxFreq = freq[i];
    }


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
        arr[i] = (rand()  % 100) + 1;
        printf("%d ", arr[i]);
    }
    printf(" \n");

    mostFreq(arr, N);

    return 0;
}
