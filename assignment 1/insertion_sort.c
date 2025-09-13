#include <stdio.h>
int main()
{
    
    int n;
    scanf("%d",&n);
    int s[n];
    for (int i = 0; i < n; i++)
    {
            scanf("%d",&s[i]);

    }
    
    int j, key;
    for (int i = 1; i < n; i++)
    {
        key = s[i];
        j = i-1;
        while (j >= 0 && key < s[j])
        {
            s[j+1] = s[j];
            j--;
        }
        s[j+1] = key;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", s[i]);
    }

    return 0;
}