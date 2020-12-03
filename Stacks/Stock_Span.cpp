#include <bits/stdc++.h>
using namespace std;

# NEXT GREATER ELEMENT TO LEFT ...

int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int> a(n);
	    vector<int> ans;
	    for(int i = 0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    stack<int> s;
	    for(int i = 0;i<n;i++)
	    {
	        if(s.empty())
	        {
	            ans.push_back(1);
	        }
	        else if(s.size()>0 && a[s.top()]>a[i])
	        {
	            ans.push_back(i-s.top());
	        }
	        else if(s.size()>0 && a[s.top()]<=a[i])
	        {
	            while(s.size()>0 && a[s.top()]<=a[i])
	            {
	                s.pop();
	            }
	            if(s.size()==0)
	            {
	                ans.push_back(i+1);
	            }
	            else
	            {
	                ans.push_back(i-s.top());
	            }
	        }
	        s.push(i);
	    }
	    for(int i = 0;i<n;i++)
	    {
	        cout<<ans[i]<<" \n"[i==n-1];
	    }
	    
	}
	return 0;
}