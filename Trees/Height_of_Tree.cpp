#include<bits/stdc++.h>
using namespace std;

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *root;

void create()
{
    queue<node*> q;
    cout<<"Enter the Root Node."<<endl;
    int root_data;
    cin>>root_data;
    root = new node;
    root->data = root_data;
    root->left = root->right = NULL;

    q.push(root);

    node *p,*t;

    while(!q.empty())
    {
        p = q.front();
        q.pop();
        cout<<"Enter The Value of left child of "<<p->data<<endl;
        int left;
        cin>>left;
        if(left == -1)
        {
            p->left = NULL;
        }
        else
        {
            t = new node;
            t->data = left;
            t->left = t->right = NULL;
            p->left = t;
            q.push(t);
        }
        cout<<"Enter The Value of Right child of "<<p->data<<endl;
        int Right;
        cin>>Right;
        if(Right == -1)
        {
            p->right = NULL;
        }
        else
        {
            t = new node;
            t->data = Right;
            t->left = t->right = NULL;
            p->right = t;
            q.push(t);
        }
    }
}

int Height(node *p)  // Basically depth
{
    int l = 0;
    int r = 0;
 
    if (p != NULL)
    {
        l = Height(p->left);
        r = Height(p->right);
        if (l > r)
        {
            return l + 1;
        } 
        else 
        {
            return r + 1;
        }
    }
    return 0;  // Return -1 for 0 based Indexing Height
}
 
int Count(node *p) 
{
    int x;
    int y;
    if (p != NULL)
    {
        x = Count(p->left);
        y = Count(p->right);
        return x + y + 1;
    }
    return 0;
}
 
int Sum(node *p) 
{
    int x;
    int y;
    if (p != NULL)
    {
        x = Sum(p->left);
        y = Sum(p->right);
        return x + y + p->data;
    }
    return 0;
}
 
int deg2NodeCount(node *p) 
{
    int x;
    int y;
    if (p != NULL)
    {
        x = deg2NodeCount(p->left);
        y = deg2NodeCount(p->right);
        if (p->left && p->right)
        {
            return x + y + 1;
        } 
        else 
        {
            return x + y;
        }
    }
    return 0;
}
 
int leafNodeCount(node *p) 
{
    int x;
    int y;
    if (p != NULL){
        x = leafNodeCount(p->left);
        y = leafNodeCount(p->right);
        if (p->left == NULL && p->right == NULL)
        {
            return x + y + 1;
        } 
        else 
        {
            return x + y;
        }
    }
    return 0;
}
 
int deg1ordeg2NodeCount(node *p) 
{
    int x;
    int y;
    if (p != NULL){
        x = deg1ordeg2NodeCount(p->left);
        y = deg1ordeg2NodeCount(p->right);
        if (p->left != NULL || p->right != NULL)
        {
            return x + y + 1;
        } 
        else 
        {
            return x + y;
        }
    }
    return 0;
}
 
int deg1count(node *p) 
{
    int x;
    int y;
    if (p != NULL)
    {
        x = deg1count(p->left);
        y = deg1count(p->right);
        if ((p->left != NULL)^(p->right != NULL))
        {
            return x + y + 1;
        } 
        else 
        {
            return x + y;
        }
    }
    return 0;
}
 
void DestroyTree(node *p)
{
    if ( p!= NULL)
    {
        DestroyTree(p->left);
        DestroyTree(p->right);
        delete p;
    }
}

int main()
{
    create();
    cout<<"\n\nHeight of the Tree = "<<Height(root)<<endl;
    cout<<"Number of Nodes of the Tree = "<<Count(root)<<endl;
    cout<<"Number of Nodes with degree 2  = "<<deg2NodeCount(root)<<endl;
    cout<<"Number of Nodes with degree 1 or degree 2  = "<<deg1ordeg2NodeCount(root)<<endl;
    cout<<"Number of Nodes with degree 1  = "<<deg1count(root)<<endl;
    cout<<"Number of Leaf nodes [degree == 0] = "<<leafNodeCount(root)<<endl;
    cout<<"Sum of Values at Nodes = "<<Sum(root)<<endl;

}