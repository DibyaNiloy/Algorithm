#include<stdio.h>

int partition(int s[],int l, int h){
    int i=l;
    int j=h;
    int pivot=s[l];
    while (i<j)
    {
       
        while (pivot>=s[i])
        {
            i++;
        }
        while (pivot<s[j])
        {
            j--;
        }
        if(i<j){
            int t=s[i];
            s[i]=s[j];
            s[j]=t;
        }
    }
            int t=s[l];
            s[l]=s[j];
            s[j]=t;

            return j;
}

void quick_sort(int s[],int l, int h){
    if(l<h){
    int pi=partition(s,l,h);
    quick_sort(s,l,pi-1);
    quick_sort(s,pi+1,h);
    }
}


int main(){

    int n;
    scanf("%d",&n);

    int s[n];
      for (int i = 0; i < n; i++)
    {
            scanf("%d",&s[i]);

    }

    quick_sort(s,0,n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",s[i]);
    }
    

    return 0;
}