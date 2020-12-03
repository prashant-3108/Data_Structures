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
