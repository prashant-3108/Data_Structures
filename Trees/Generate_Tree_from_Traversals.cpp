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

int searchInorder(int inArray[], int inStart, int inEnd, int data){
    for (int i=inStart; i<=inEnd; i++){
        if (inArray[i] == data){
            return i;
        }
    }
    return -1;
}
 
node* generateFromTraversal(int *inorder, int *preorder, int inStart, int inEnd) 
{
    static int preIndex = 0;
 
    if (inStart > inEnd)
    {
        return nullptr;
    }
 
    node* n = new node;
    n->data = preorder[preIndex];
    preIndex++;
 
    if (inStart == inEnd)
    {
        return n;
    }
 
    int splitIndex = searchInorder(inorder, inStart, inEnd, n->data);
    n->left = generateFromTraversal(inorder, preorder, inStart, splitIndex-1);
    n->right = generateFromTraversal(inorder, preorder, splitIndex+1, inEnd);
 
    return n;
}



int main()
{
    node *root;

    int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};

    root = generateFromTraversal(inorder,preorder,0,sizeof(inorder)/sizeof(inorder[0])-1);

    for(int i = 0;i<9;i++)
    {
        cout<<preorder[i]<<" \n"[i==8];
    }
    preorder_traveral(root);
    cout<<endl<<endl;
    for(int i =0;i<9;i++)
    {
        cout<<inorder[i]<<" \n"[i==8];
    }
    Inorder_traveral(root);
    cout<<endl<<endl;
}