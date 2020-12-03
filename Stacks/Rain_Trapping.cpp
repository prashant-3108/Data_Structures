#include<bits/stdc++.h>
using namespace std;


vector<int> max_on_right(vector<int> a)
{
    int n = a.size();
    stack<int> s;
    vector<int> right;
    for(int i = n-1;i>=0;i--)
    {
        if(s.empty())
        {
            right.push_back(a[i]);
            s.push(a[i]);
            continue;
        }
        else if(s.size()>0 && s.top()>a[i])
        {
            right.push_back(s.top());
        }
        else if(s.size()>0 && s.top()<=a[i])
        {
            right.push_back(s.top());
            while(s.size()>0 && s.top()<=a[i])
            {
                s.pop();
            }
            s.push(a[i]);
        }
    }
    reverse(right.begin(),right.end());
    return right;
}

vector<int> max_on_left(vector<int> a)
{
    int n = a.size();
    stack<int> s;
    vector<int> right;
    for(int i = 0;i<n;i++)
    {
        if(s.empty())
        {
            right.push_back(a[i]);
            s.push(a[i]);
            continue;
        }
        else if(s.size()>0 && s.top()>a[i])
        {
            right.push_back(s.top());
        }
        else if(s.size()>0 && s.top()<=a[i])
        {
            right.push_back(s.top());
            while(s.size()>0 && s.top()<=a[i])
            {
                s.pop();
            }
            s.push(a[i]);
        }
        
    }
    // reverse(right.begin(),right.end());
    return right;
}

int main()
 {
	
	int t ;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int> a(n),left,right;
	    
	    for(int i =0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    
	    left = max_on_left(a);
	    right = max_on_right(a);
	    
	   
	    int ans  = 0;
	    for(int i = 0;i<n;i++)
	    {
	        if((min(right[i],left[i])-a[i])>0)
	           ans += (min(right[i],left[i])-a[i]);
	    }
	    cout<<ans<<endl;
	}
	return 0;
}