           #include<stdio.h>
#include<stdlib.h>
#include<time.h>

int linearSearch(int arr[], int n, int v);
int binarySearch(int arr[], int s, int v);

void bubbleSort(int arr[], int s);
void selectionSort(int arr[], int s);
void insertionSort(int arr[], int s);

int main()
{
    int data[100], n, i, v, flag=0;

    printf("enter size: ");
    scanf("%d",&n);

    //printf("input: ");
    srand(time(NULL));
    for(i=0; i<n; i++)
    {
        //scanf("%d",&data[i]);
        data[i] = 1 + rand()%100;
    }


    printf("output: ");
    for(i=0; i<n; i++)
    {
        printf("%d ",data[i]);
    }

    insertionSort(data, n);

    printf("\n\nafter sort: ");
    for(i=0; i<n; i++)
    {
        printf("%d ",data[i]);
    }

    printf("\n\nenter value to search: ");
    scanf("%d",&v);

    if(binarySearch(data, n, v))
        printf("found\n");
    else
         printf("not found\n");





    return 0;
}

int linearSearch(int arr[], int n, int v)//array, size, searchValue
{
    int i, flag = 0;
    for(i=0; i<n ; i++)
    {
        if(arr[i] == v)
        {
            flag = 1;
            break;
        }
        else
        {
            flag = 0;
        }
    }

    return flag;
}

void bubbleSort(int arr[], int s)
{
    int i, j, temp;

    for(i=0; i<s-1; i++)
    {
        for(j=0; j<s-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return;


}

int binarySearch(int arr[], int s, int v)
{
    int low = 0, high = s-1, mid;

    while(low <= high)
    {
        mid = (low+high)/2;
        if(arr[mid] == v) return 1;
        else if(arr[mid] > v) high = mid-1;
        else low = mid + 1;
    }
    return 0;
}

void selectionSort(int arr[], int s)
{
    int i, j, temp, low;

    for(i = 0; i<s-1; i++)
    {
        low = i;
        for(j=i; j<s; j++)
        {
            if(arr[j] < arr[low])
            {
                low = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[low];
        arr[low] = temp;
    }
}

void insertionSort(int arr[], int s)
{
    int i, j, key;

    for(i = 1; i < s; i++)
    {
        key = arr[i];


        for(j = i-1; j>= 0 && arr[j] > key; j--)
        {
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }
}
