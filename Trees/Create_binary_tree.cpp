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

int main()
{
    create();
    preorder_traveral(root);
    cout<<endl;
    Inorder_traveral(root);
    cout<<endl;
    Postorder_traveral(root);
    cout<<endl;
}