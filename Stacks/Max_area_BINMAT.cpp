// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int maxArea(int M[MAX][MAX], int n, int m);
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        cout << maxArea(M, n, m) << endl;
    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int getMaxArea(int a[], int n)
{
    vector<int> right,left;

    stack<pair<int,int>> s,t;

    for(int i =n-1;i>=0;i--)
    {
        if(s.empty())
        {
            right.push_back(0);
        }
        else if(s.size()>0 && s.top().first<a[i])
        {
            right.push_back(s.top().second-i-1);
        }
        else if(s.size()>0 && s.top().first>=a[i])
        {
            while(s.size()>0 && s.top().first>=a[i])
            {
                s.pop();
            }
            if(s.size()==0)
            {
                right.push_back(n-i-1);
            }
            else
            {
                right.push_back(s.top().second-i-1);
            }
        }
        s.push({a[i],i});
    }
    reverse(right.begin(),right.end());

    for(int i = 0;i<n;i++)
    {
        if(t.empty())
        {
            left.push_back(0);
        }
        else if(t.size()>0 && t.top().first<a[i])
        {
            left.push_back(i-t.top().second-1);
        }
        else if(t.size()>0 && t.top().first>=a[i])
        {
            while(t.size()>0 && t.top().first>=a[i])
            {
                t.pop();
            }
            if(t.size()==0)
            {
                left.push_back(i);
            }
            else
            {
                left.push_back(i-t.top().second-1);
            }
        }
        t.push({a[i],i});
    }

    int maxx = -1000;
    for(int i =0;i<n;i++)
    {
        // cout<<right[i]<<" "<<left[i]<<endl;
        int temp = (right[i]+left[i]+1)*a[i];
        if(temp>maxx)
        {
            maxx = temp;
        }
    }
    // cout<<endl;
    return maxx;
}

int maxArea(int M[MAX][MAX], int n, int m) {
    // Your code here
    int i=1;
    while(i<n)
    {
        for(int j = 0;j<m;j++)
        {
            if(M[i][j])
            {
                M[i][j]+=M[i-1][j];
            }
        }
        i++;
    }
    int ans = -1000;
    for(int i =0;i<n;i++)
    {
        int temp = getMaxArea(M[i],m);
        if(temp>ans)
        {
            ans = temp;
        }
    }
    return ans;
    
}
