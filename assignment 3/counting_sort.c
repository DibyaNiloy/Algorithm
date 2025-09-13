#include <stdio.h>

void counting_sort(int s[], int n)
{
    int k = s[0];
    for (int i = 1; i < n; i++)
    {
        if (s[i] > k)
            k = s[i];
    }

    int count[k + 1];
    int output[n];

    for (int i = 0; i <= k; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[s[i]]++;

    for (int i = 1; i <= k; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[s[i]] - 1] = s[i];
        count[s[i]]--;
    }

    for (int i = 0; i < n; i++)
        s[i] = output[i];
}

int main()
{
    int n;
    scanf("%d", &n);

    int s[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }

    counting_sort(s, n);

    for (int i = 0; i < n; i++)
        printf("%d ", s[i]);
    printf("\n");

    return 0;
}
