#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the cookies function below.
 */
 

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

int Delete_Heap(vector<int>& A)
{
    int n = A.size()-1;
    int i,j,x,temp,val;
    val=A[1];
    x=A[n];
    A[1]=A[n];
    A.pop_back();    // Copy last element as root of heap
    // A[n]=val;     // Removed element to last of Heap
    
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

 
int cookies(int k, vector<int> A) 
{
    A.push_back(-1);
    for(int i = A.size()-2;i>=0;i--)
    {
        A[i+1] = A[i];
    }
    A[0] = -1;
    Create_by_Heapify(A);
    int ans = 0;
    bool ok =false;
    while(A[1]<k)
    {
        if(A.size()==3)
        {
            int sweetness = A[1] + 2*(A[2]);
            if(sweetness>=k)
            {
                ans++;
                break;
            }
            ok = true;
            break;
        }
        
        int a = Delete_Heap(A);
        int b = Delete_Heap(A);
        int sweetness = a+2*b;
        insert_inheap(A,sweetness);
        ans+=1;
    }
    if(ok)
      return -1;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split_string(A_temp_temp);

    vector<int> A(n);

    for (int A_itr = 0; A_itr < n; A_itr++) {
        int A_item = stoi(A_temp[A_itr]);

        A[A_itr] = A_item;
    }

    int result = cookies(k, A);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
