#include<stdio.h>

int main()
{
    //printf("hello");
    int n, i=0;
    float low, high, mid, th = .005;

    printf("enter number: ");
    scanf("%d", &n);

    low = 0;
    high = n;



    while(1)
    {
        mid = (low+high)/2;

        if(mid*mid >= n-th && mid*mid <= n+th)
        {
            printf("square root of %d is %.3f\n",n,mid);
            break;
        }
        else if(mid*mid > n)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
        i++;
    }
    printf("number of iteration %d\n",i);

    return 0;
}

//int flAbs(float n, float sqrt)
//{
//
//}