#include<bits/stdc++.h>
using namespace std;


void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int partition(int a[],int l,int r)
{
    int pivot = a[l];
    int i = l,j = r;

    while(i<j)
    {
        while(a[i]<=pivot)
          i++;
        
        while(a[j]>pivot)
          j--;

        if(i<j)
          swap(&a[i],&a[j]);
    }
    swap(&a[l],&a[j]);
    return j;
}

void quick_sort(int a[],int l,int r)
{
    int j;
    if(l<r)
    {
        j = partition(a,l,r);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,r);
    }
}


int main()
{ 
    int a[] = {11,13,7,12,16,9,24,5,10,3};
    quick_sort(a,0,9);
    for(int i =0;i<10;i++)
    {
        cout<<a[i]<<" \n"[i==9];
    }
}