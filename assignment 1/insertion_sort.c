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
    
    int hole, value;
    for (int i = 1; i < n; i++)
    {
        value = s[i];
        hole = i;
        while (hole > 0 && value < s[hole - 1])
        {
            s[hole] = s[hole - 1];
            hole--;
        }
        s[hole] = value;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", s[i]);
    }

    return 0;
}