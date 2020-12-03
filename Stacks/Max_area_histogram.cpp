#include <bits/stdc++.h>
using namespace std;

// BOTH NEXT SMALLER LEFT AND RIGHT TO GET WIDTHS

long getMaxArea(long long a[], int n)
{
    vector<long long> right,left;

    stack<pair<long long,long long>> s,t;

    for(long long i =n-1;i>=0;i--)
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

    for(long long i = 0;i<n;i++)
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

    long long maxx = -1000;
    for(long long i =0;i<n;i++)
    {
        // cout<<right[i]<<" "<<left[i]<<endl;
        long long temp = (right[i]+left[i]+1)*a[i];
        if(temp>maxx)
        {
            maxx = temp;
        }
    }
    // cout<<endl;
    return maxx;
}


int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        cout<<getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}