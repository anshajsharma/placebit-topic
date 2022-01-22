# Left View

```c++
map<int,int> m;
void solve(Node *root,int lev)
{
    if(!root) return;
    
    if(m.find(lev) == m.end()) m[lev] = root->data;
    
    solve(root->left,lev+1);
    solve(root->right,lev+1);
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   m.clear();
   
   solve(root,0);
   vector<int> ans;
   for(pair<int,int> i:m)
   {
       ans.push_back(i.second);
   }
   return ans;
}
```

# Right View

```c++
map<int,int> m;
void solve(Node *root,int lev)
{
    if(!root) return;
    
    if(m.find(lev) == m.end()) m[lev] = root->data;
    
    solve(root->right,lev+1);
    solve(root->left,lev+1);
    
}
// Should return  right view of tree
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       m.clear();
   
       solve(root,0);
       vector<int> ans;
       for(pair<int,int> i:m)
       {
           ans.push_back(i.second);
       }
        return ans;
    }
};
```
# Top View

```c++
map<int,pair<int,int>> m;
void solve(Node *root,int vLev,int hLev)
{
    if(!root) return;
    
    if(m.find(vLev) == m.end()) m[vLev] = make_pair(root->data,hLev) ;
    else if( m[vLev].second > hLev) m[vLev] = make_pair(root->data,hLev);
    
    solve(root->left,vLev-1,hLev+1);
    solve(root->right,vLev+1,hLev+1);
}
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        m.clear();
   
       solve(root,0,0);
       vector<int> ans;
       for(auto i:m)
       {
           ans.push_back(i.second.first);
       }
       return ans;
    }
};
```

# Bottom View

```c++
map<int,pair<int,int>> m;
void solve(Node *root,int vLev,int hLev)
{
    if(!root) return;
    
    if(m.find(vLev) == m.end()) m[vLev] = make_pair(root->data,hLev) ;
    else if( m[vLev].second <= hLev) m[vLev] = make_pair(root->data,hLev);
    
    solve(root->left,vLev-1,hLev+1);
    solve(root->right,vLev+1,hLev+1);
}
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        m.clear();
   
       solve(root,0,0);
       vector<int> ans;
       for(auto i:m)
       {
           ans.push_back(i.second.first);
       }
       return ans;
        
    }
};
```
