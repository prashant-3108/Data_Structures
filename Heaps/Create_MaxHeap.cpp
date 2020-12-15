#include<bits/stdc++.h>
using namespace std;

// MAX HEAP -->

// Creating Heap in Another Vector:
void insert_inheap(vector<int>& v,int key)
{
    int i = v.size();
    v.emplace_back(key);

    while (i > 0 && key > v[i % 2 == 0 ? (i/2)-1 : i/2])
    {
        v[i] = v[(i%2==0)?((i/2)-1):(i/2)];  // Going to parent 0 based indexing
        i = ((i%2==0)?((i/2)-1):(i/2));
    }
    v[i] = key;
}
// O(nlogn) -- Not Heapify.

void CreateHeap(vector<int>& vec, int A[], int n)
{
    for (int i=0; i<n; i++)
    {
        insert_inheap(vec, A[i]);
    }
}


// Modifying same array as Heap:
void InsertInplace(int A[], int n)
{
    int i = n;
    int temp = A[n];
    while (i > 0 && temp > A[i % 2 == 0 ? (i/2)-1 : i/2])
    {
        A[i] = A[i % 2 == 0 ? (i/2)-1 : i/2];
        i = i % 2 == 0 ? (i/2)-1 : i/2;
    }
    A[i] = temp;
}

void Create_InplaceHeap(int A[], int n)
{
    for (int i=0; i<n; i++)
    {
        InsertInplace(A,i);
    }
}

//Print Heap:
template <class T>
void Print(T& vec, int n, string c)
{
    cout << c << ": [" << flush;
    for (int i=0; i<n; i++)
    {
        cout << vec[i] << flush;
        if (i < n-1)
        {
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

int Delete_Heap(int A[],int n)
{
    int i,j,x,temp,val;
    val=A[0];
    x=A[n];
    A[0]=A[n];    // Copy last element as root of heap
    A[n]=val;     // Removed element to last of Heap
    
    i=0;
    j=1;
    while(j<=n-1)
    {
        if(j<n-1 && A[j+1]>A[j])
          j = j+1;

        if(A[i]<A[j])
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i = j;
            j = 2*j; 
        }
        else
        {
            break;
        }
    }
    return val;
} 

void Heapsort(int A[],int n)
{
    for(int i=n-1;i>0;i--)
    { 
        Delete_Heap(A,i);
    }
}


int main() 
{
 
    cout << "Create Heap" << endl;
    int Array[] = {10, 20, 30, 25, 5, 40, 35};
    Print(Array, sizeof(Array)/sizeof(Array[0]), "Array");
 
    vector<int> v;
    CreateHeap(v, Array, sizeof(Array)/sizeof(Array[0]));
    Print(v, v.size(), "Vector");
 
    cout << "Inplace Insert" << endl;
    Create_InplaceHeap(Array, sizeof(Array)/sizeof(Array[0]));
    Print(Array, sizeof(Array)/sizeof(Array[0]), "Array");
    
    Heapsort(Array,sizeof(Array)/sizeof(Array[0]));
    Print(Array, sizeof(Array)/sizeof(Array[0]), "Array");

    int B[] = {5, 10, 30, 20};
    Print(B, sizeof(B)/sizeof(B[0]), "B");
 
    // build_maxheap(B, sizeof(B)/sizeof(B[0]));
    Print(B, sizeof(B)/sizeof(B[0]), "Heapified B");

    return 0;
}

