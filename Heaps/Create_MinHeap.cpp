#include<bits/stdc++.h>
using namespace std;

// MIN HEAP --> 1 Based Indexing
// Parent --> i/2

// Creating Heap in Another Vector:
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
// O(nlogn) -- Not Heapify.

void CreateHeap(vector<int>& vec, int A[], int n)
{
    for (int i=1; i<n; i++)
    {
        insert_inheap(vec, A[i]);
    }
}


// Modifying same array as Heap:
void InsertInplace(int A[], int n)
{
    int i = n;
    int temp = A[n];
    while (i > 1 && temp < A[i/2])
    {
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}

void Create_InplaceHeap(int A[], int n)
{
    for (int i=1; i<n; i++)
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
    val=A[1];
    x=A[n];
    A[1]=A[n];    // Copy last element as root of heap
    A[n]=val;     // Removed element to last of Heap
    
    i=1;
    j=i*2;
    while(j<=n-1)
    {
        if(j<n-1 && A[j+1]<A[j])
          j = j+1;

        if(A[i]>A[j])
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
// Sorted in Descending Order..
void Heapsort(int A[],int n)
{
    for(int i=n-1;i>1;i--)
    { 
        Delete_Heap(A,i);
    }
}

int main() 
{
 
    cout << "Create Heap" << endl;
    int Array[] = {0,10, 20, 30, 25, 5, 40, 35};
    Print(Array, sizeof(Array)/sizeof(Array[0]), "Array");
 
    vector<int> v;
    v.push_back(0);
    CreateHeap(v, Array, sizeof(Array)/sizeof(Array[0]));
    Print(v, v.size(), "Vector");
 
    cout << "Inplace Insert" << endl;
    Create_InplaceHeap(Array, sizeof(Array)/sizeof(Array[0]));
    Print(Array, sizeof(Array)/sizeof(Array[0]), "Array");

    Heapsort(Array,sizeof(Array)/sizeof(Array[0]));
    Print(Array, sizeof(Array)/sizeof(Array[0]), "Array");

    return 0;
}

