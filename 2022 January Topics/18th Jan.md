# 236. Lowest Common Ancestor of a Binary Tree
**Qlink:** https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

```c++
// ------------------------ TYPE 1 --------------------------------------
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* a, TreeNode* b) {
        if(!root) return NULL;
        if(root == a||root == b) return root;
        TreeNode *l = lowestCommonAncestor(root->left,a,b);
        TreeNode *r = lowestCommonAncestor(root->right,a,b);

        if(l&&r) return root;
        else if(l) return l;
        else if(r) return r;
        else return NULL;
    }
};

// ------------------------ TYPE 2 --------------------------------------
std::vector<TreeNode *> v;
vector<TreeNode *> path;

void printPATH(TreeNode *root,TreeNode* k)
{
  if(!root) return;
  v.push_back(root);
  printPATH(root->left,k);
  printPATH(root->right,k);
  if(root == k){
    path = v;
  }

  v.pop_back();
}
TreeNode* LCA(TreeNode *root,TreeNode* a,TreeNode* b)
{
  printPATH(root,a);
  vector<TreeNode*> p1 = path;
  printPATH(root,b);
  vector<TreeNode*> p2 = path;

  if(p1.size() > p2.size()) swap(p1,p2);

  for(int i=0;i<p1.size()-1;i++)
  {
    if(p1[i+1] != p2[i+1]) return p1[i];
  }

  return p1[p1.size()-1];

}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* a, TreeNode* b) {
        return LCA(root,a,b);
    }
};
```
