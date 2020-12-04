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

void preorder_traveral(node *r)
{
    if(r)
    {
        cout<<r->data<<" ";
        preorder_traveral(r->left);
        preorder_traveral(r->right);
    }
}

void Inorder_traveral(node *r)
{
    if(r)
    {
        Inorder_traveral(r->left);
        cout<<r->data<<" ";
        Inorder_traveral(r->right);
    }
}

void Postorder_traveral(node *r)
{
    if(r)
    {
        Postorder_traveral(r->left);
        Postorder_traveral(r->right);
        cout<<r->data<<" ";
    }
}

void level_traversal(node *r)
{
    queue<node*> q;
    cout<<r->data<<" ";
    q.emplace(r);
    node *p;

    while(!q.empty())
    {
        p = q.front();
        q.pop();
        if(p->left)
        {
            cout<<p->left->data<<" ";
            q.emplace(p->left);
        }
        if(p->right)
        {
            cout<<p->right->data<<" ";
            q.emplace(p->right);
        }
    }
}

void Iterative_Preorder_traversal(node *p)
{
    stack<node*> s;
    while(p!=NULL || !s.empty())
    {
        if(p)
        {
            cout<<p->data<<" ";
            s.push(p);
            p=p->left;
        }
        else
        {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
}

void Iterative_Inorder_traversal(node *p)
{
    stack<node*> s;
    while(p!=NULL || !s.empty())
    {
        if(p)
        {
            // cout<<p->data<<" ";
            s.push(p);
            p=p->left;
        }
        else
        {
            p = s.top();
            s.pop();
            cout<<p->data<<" ";
            p = p->right;
        }
    }
}

void Iterative_Postorder_traversal(node *p)
{
    stack<long long> s;
    long long address;

    while(p!=NULL || !s.empty())
    {
        if(p)
        {
            s.push((long long)p);
            p = p->left;
        }
        else
        {
            address = (long long)s.top();
            s.pop();
            if(address>0)
            {
                s.push(-address);
                p = ((node*)address)->right;
            }
            else
            {
                cout<<(((node*)(-1*address))->data)<<" ";
            }
        }
        
    }
}

void DestroyTree(node *p)
{
    if ( p!= nullptr)
    {
        DestroyTree(p->left);
        DestroyTree(p->right);
        delete p;
    }
}

int main()
{
    create();
    preorder_traveral(root);
    cout<<endl;
    Inorder_traveral(root);
    cout<<endl;
    Postorder_traveral(root);
    cout<<endl;
    level_traversal(root);
    cout<<endl;

    Iterative_Preorder_traversal(root);
    cout<<endl;
    Iterative_Inorder_traversal(root);
    cout<<endl;
    Iterative_Postorder_traversal(root);
    cout<<endl;

    DestroyTree(root);
}