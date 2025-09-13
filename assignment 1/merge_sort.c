#include<stdio.h>

void merge(int s[],int l,int mid,int r){
    int temp[10000];
    int k=0;
    int i=l,j=mid+1;
    while (i<=mid && j<=r)
    {
        if(s[i]<=s[j]){
            temp[k++]=s[i];
            i++;
        }else{
            temp[k++]=s[j];
            j++;
        }
    }
    while (i<=mid)
    {
        temp[k++]=s[i];
            i++;
    }
     while (j<=r)
    {
        temp[k++]=s[j];
            j++;
    }
    for (int x = 0; x < k; x++)
    {
        s[x+l]=temp[x]; 
    }
    
    

}

void merge_sort(int s[],int l, int r){
    if(l<r){
        int mid=(l+r)/2;
        merge_sort(s,l,mid);
        merge_sort(s,mid+1,r);
        merge(s,l,mid,r);
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

    merge_sort(s,0,n-1);

    for (int i = 0; i < n; i++)
    {
       printf("%d ",s[i]);
    }
    

    
}