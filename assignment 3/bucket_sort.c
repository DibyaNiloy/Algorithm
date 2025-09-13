#include <stdio.h>
#include <stdlib.h>

void insertionSort(float arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n)
{
    float buckets[n][n];
    int count[n];
    for (int i = 0; i < n; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
    {
        int bi = n * arr[i];
        buckets[bi][count[bi]++] = arr[i];
    }

    for (int i = 0; i < n; i++)
        if (count[i] > 0)
            insertionSort(buckets[i], count[i]);

    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < count[i]; j++)
            arr[index++] = buckets[i][j];
}

int main()
{
    int n;
    scanf("%d", &n);
    float arr[n];
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    bucketSort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%.3f ", arr[i]);
    printf("\n");

    return 0;
}
