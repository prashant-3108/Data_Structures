#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long int

void insert_inheap(vector<int>& v,int key)
{
    int i = v.size();
    v.emplace_back(key);

    while (i > 1 && key < v[i/2])
    {
        v[i] = v[i/2];  // Going to parent 1 based indexing
        i = (i/2);
    }
    v[i] = key;
}

void swap(vector<int>& A, int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void minHeapify(vector<int>& arr,int curr_idx)
{
   int size = arr.size()-1;
   int child = 2*curr_idx;
   while(child<=size)
   {
       if((child+1<=(size)) && (arr[child+1]<arr[child]))
       {
           child+=1;
       }
       if(arr[child]<arr[curr_idx])
       {
          swap(arr,child,curr_idx);
          curr_idx = child;
          child = 2*curr_idx;
       }
       else if(arr[child]>=arr[curr_idx])
       {
          break;
       }
       
   }
}

void Create_by_Heapify(vector<int>&A)
{
    int size = A.size();
   for(int i = floor(size/2);i>=1;i--)
   {
      minHeapify(A,i);
   }
}

void Delete_Heap(vector<int>& A,int key)
{
    // int idx = -1;
    std::vector<int>::iterator it; 
    it = std::find (A.begin(), A.end(), key);
    A.erase(it);
    Create_by_Heapify(A);
} 

int32_t main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    vector<int> heap;
    heap.push_back(-1);
    int q;
    cin>>q;
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int x;
            cin>>x;
            insert_inheap(heap,x);
        }
        if(t==2)
        {
            int x;
            cin>>x;
            Delete_Heap(heap,x);
        }
        if(t==3)
        {
            cout<<heap[1]<<endl;
        }
    } 
    return 0;
}
