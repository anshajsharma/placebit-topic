# Level Order Traversal

```c++
vector<int> levelOrder(Node* root)
{
  //Your code here
  vector<int> ans;
  if(!root) return ans;
  queue<Node *> q;
  q.push(root);
  while(!q.empty()){
    Node *temp = q.front();
    q.pop();
    ans.push_back(temp->data);
    if(temp->left) q.push(temp->left);
    if(temp->right) q.push(temp->right);
  }
  return ans;
}
```

# Reverse Level Order Traversal 
**QLink:** https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1#

```c++
vector<int> reverseLevelOrder(Node *root)
{
    // code here
      vector<int> ans;
      if(!root) return ans;
      queue<Node *> q;
      q.push(root);
      while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        ans.push_back(temp->data);
        if(temp->right) q.push(temp->right);
        if(temp->left) q.push(temp->left);
      }
      reverse(ans.begin(),ans.end());
      return ans;
}
```
