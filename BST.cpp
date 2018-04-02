#include<iostream>
using namespace std;

class node
{
   public:
   int data;
   node *parent,*left,*right;
   node()
   {
      parent=NULL;
      left=NULL;
      right=NULL;
      data=0;
   }
};

class bsTree
{
   public:
   node* root=NULL;


void insert(node* v, int data)
{ 
   node* temp=new node;
   temp->data=data;
   if(root==NULL)
   {
     root=temp;
   }
   else
   {
   if(v->data>=data)
   {
     if(v->left!=NULL)
     {
       insert(v->left,data);
     }
     else
     {
        v->left=temp;
        temp->parent=v;
     }
   }  
   else
   {
     if(v->right!=NULL)
     { 
       insert(v->right, data);
     }
     else
     {
       v->right=temp;
       temp->parent=v;
     } 
   }
 }
}


void display(node* v)
  {  
   if(v==NULL)
   {
     return;
   }
   display(v->left);
   cout<<v->data<<"\t";
   display(v->right);
 }


void deletenode(int key, node* v)
{
  node* temp=root;
  if(v==NULL)
  {
    cout<<"\n \nElement not found !!!\nCan not delete the data entered !";
    return;
  }
  
  if(v->left==NULL && v->right==NULL)
  {
    node* par;
    par=v->parent;
    if(par->data>=v->data)
    {
      par->left=NULL;
    }
    else
      par->right=NULL;
    delete v;
    
  }
  else if((v->left==NULL || v->right==NULL ))
   {
     node* par;
     node* schild;
     par=v->parent; 
     if(v->left==NULL)
      schild=v->right;
     else
      schild=v->left;

     if(par->data>=v->data)
     {
       par->left=schild;
       schild->parent=par;
     }
     else
     {
       par->right=schild;
       schild->parent=par;
     }
    delete v;
   }
  else
  {
    node* maxleft;
    maxleft=v->left;
    while(maxleft->right!=NULL)
    {
      maxleft=maxleft->right;
    }
   if(maxleft->left==NULL)
   {
     node* par=maxleft->parent;
     par->right=NULL;
     v->data=maxleft->data;
   }
   else
   {
     if(maxleft->left
   }
  }
}


node* searchnode(node* v, int data)
{
   node* temp=v;
if(v!=NULL)
{
   if(temp->data==data)
   {
     cout<<"\nElement found !!!";
     return temp;
   }
   else if(temp->data>data)
     return searchnode(temp->left,data);
   else
     return searchnode(temp->right, data);
}
else
{ 
  cout<<"\nElement not found !";
  return NULL;
}
}
};

int main()
{
   bsTree BT;
   int n;
   cout<<"\n \nEnter the number of entries you want to enter: ";
   cin>>n;
   for(int i=0;i<n;i++)
   { cout<<"\nDATA "<<(i+1)<<": ";
     int num=0;
     cin>>num;
     BT.insert(BT.root,num);
   }
   BT.display(BT.root);
   cout<<"\n \nEnter the element to be found: ";
   cin>>n;   
   node* x1=BT.searchnode(BT.root,n);
   cout<<"\n \n";
   cout<<"\n \nEnter the node to be deleted: ";
   cin>>n;
   node* x3=BT.searchnode(BT.root,n);
   BT.deletenode(n,x3);
   BT.display(BT.root);
   return 0;
}
