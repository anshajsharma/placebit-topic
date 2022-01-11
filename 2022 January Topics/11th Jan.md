# Constructor & Destructor

```c++
// Node
struct node
{

  // Constructor
  node(){
    cout<<"Object Created!!\n";
  }

  // Destructor
  ~node(){
    cout<<"Object Destroyed!!\n";
  }

};

void solve()
{
   {
     // Local, static allocation of memory(stack)
     node a;
     cout<<"Here\n";
   }
   node *temp;
   cout<<"\n";
   {
     // Local, dynamic allocation of memory(heap)
     node *a = new node();
     temp = a;
     cout<<"Here\n";
   }
   delete temp; 
}
```

# Traversals + Cloning of a BT

```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Node
struct node
{
  int data;
  node *left,*right;

  // Constructors
  node(){
    data = 0;
    left = NULL;
    right = NULL;
  }

  node(int d){
    data = d;
    left = NULL;
    right = NULL;
  }

  node(int d,node* l,node* r){
    data = d;
    left = l;
    right = r;
  }

  // methods
  void setLeft(node *l){
    left = l;
  }

  void setRight(node *r){
    right = r;
  }
};

// Printing of tree
void printTree(node *root)
{
  if(!root) return;
  cout<<root->data<<" ";
  printTree(root->left);
  printTree(root->right);
}

// inorder of tree
void inorder(node *root)
{
  if(!root) return;
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

// clone of tree
node* clone(node *root)
{
  if(!root) return NULL;
  return new node(root->data, clone(root->left) , clone(root->right) );
}

// preorder of tree
void preOrder(node *root)
{
  if(!root) return;
  cout<<root->data<<" ";
  preOrder(root->left);

  preOrder(root->right);
}

// postorder of tree
void postOrder(node *root)
{
  if(!root) return;
  postOrder(root->left);
  postOrder(root->right);
  cout<<root->data<<" ";
}

void solve()
{
  node *root = new node(1);
  node *b = new node(2);

  b->setLeft(new node(4));
  b->setRight(new node(5));

  node *c = new node(3);
  c->setLeft(new node(6));

  root->setLeft(b);
  root->setRight(c);

  printTree(root);
  cout<<"\n";
  inorder(root);
  cout<<"\n";
  preOrder(root);
}
```
