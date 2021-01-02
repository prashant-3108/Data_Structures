#include<bits/stdc++.h>
using namespace std;


void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

pair<int,int> partition(int a[],int l,int r)
{
    int pivot = a[l];
    int i,j = r;
    pair<int,int> pr; 
    int p = l,q = l;
    while(q<=r)
    {
        if(a[q]<a[p])
        {
            int x = a[q];
            for(int z = q-1;z>=p;z--)
            {
                a[z+1] = a[z];
            }
            
            a[p] = x;
            p = p+1;
        }
        q++;
    }
    pr.first = p;
    i = p;
    while(i<j)
    {
        while(a[i]==a[p])
          i++;
        
        while(a[j]>a[p])
          j--;

        if(i<j)
          swap(&a[i],&a[j]);
    }
    
    swap(&a[p],&a[j]);
    pr.second = j;
    return pr;
}

void quick_sort(int a[],int l,int r)
{
    pair<int,int> pr;
    
    if(l<r)
    {
        pr = partition(a,l,r);
        quick_sort(a,l,pr.first-1);
        quick_sort(a,pr.second+1,r);
    }
}


int main()
{ 
    int n;
    cin>>n;  
    int a[n];
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
    }
    quick_sort(a,0,n-1);
    for(int i =0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}