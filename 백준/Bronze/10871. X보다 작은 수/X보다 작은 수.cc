#include<stdio.h>

int main(void)
{
    int N, X, i, j = 0;
    int arr[N];
    scanf("%d %d", &N, &X);

    for (i = 0;i < N;i++)
    {
        while (j < N)
        {
            scanf("%d", &arr[j]);
            j++;
        }
        if (X > arr[i])
        {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}