#include<bits/stdc++.h>
using namespace std;

// 0 based Indexing -->

void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void maxHeapify(int arr[],int size,int curr_idx)
{
   int child = 2*curr_idx+1;
   while(child<=size-1)
   {
       if((child+1<=(size-1)) && (arr[child+1]>arr[child]))
       {
           child+=1;
       }
       if(arr[child]>arr[curr_idx])
       {
          swap(arr,child,curr_idx);
          curr_idx = child;
          child = 2*curr_idx+1;
       }
       else if(arr[child]<=arr[curr_idx])
       {
          break;
       }
       
   }
}

void printHeap(int arr[], int n) 
{ 
	cout << "Array representation of Heap is:\n"; 

	for (int i = 0; i < n; ++i) 
		cout << arr[i] << " "; 
	cout << "\n"; 
} 

void Create_by_Heapify(int a[],int size)
{
   for(int i = floor(size/2)-1;i>=0;i--)
   {
      maxHeapify(a,size,i);
   }
}

int main()
{
   int a[]={ 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
   int n = sizeof(a) / sizeof(a[0]);
   Create_by_Heapify(a,n);
   printHeap(a,n);
   return 0;
}