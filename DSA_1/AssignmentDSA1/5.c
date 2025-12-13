#include <stdio.h>

double cubeRoot(int n)
{
    double low = 0, high = n > 1 ? n : 1;
    double mid;

    while ((high - low) > 0.005)
    {
        mid = ( low + high) / 2.0;

        if (mid * mid * mid > n)
            high =  mid;
        else
            low =  mid;
    }

    return (low + high) / 2.0;
}

int main()
{


    int N;
    
    printf("Enter  N: ");
    scanf("%d", &N);

    double result = cubeRoot(N);
    printf("Cubic  root of %d is %.3lf\n", N, result);

    return 0;
}
