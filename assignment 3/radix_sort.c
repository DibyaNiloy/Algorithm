#include <stdio.h>

int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}


void count_sort(int arr[], int n, int p)
{
    int output[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[(arr[i] / p) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / p) % 10] - 1] = arr[i];
        count[(arr[i] / p) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void redix_sort(int arr[], int n)
{
    int m = getMax(arr, n);
    for (int p = 1; m / p > 0; p *= 10)
        count_sort(arr, n, p);
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    redix_sort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
