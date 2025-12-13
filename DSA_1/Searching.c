#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void menu(int arr[], int n)
{
    int choice;

    while (1)
    {
        printf("\nMenu:\n");
        printf("0. Exit from code.\n");
        printf("1. Print the array: \n");
        printf("2.  \n");
        printf("3. \n");

        printf("Enter your choice: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            return;
        case 1:
            printArray(arr, n);
            break;
        }
    }
}

int main()
{

    int n;

    printf("Enter array size: ");

    scanf("%d", &n);

    srand(time(0));

    int randomNumber;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        randomNumber = (rand() % 100) + 1;
        arr[i] = randomNumber;
    }
    printf("%d size array created.",n);


    menu(arr, n);

    return 0;
}
