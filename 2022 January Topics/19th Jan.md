# 113. Path Sum II
**QLink:** https://leetcode.com/problems/path-sum-ii/

```c++
std::vector<int> v;
vector<vector<int>> path;

void printPATH(TreeNode *root,int k)
{
  if(!root) return;
  v.push_back(root->val);
  printPATH(root->left,k);
  printPATH(root->right,k);
  if(root->left == NULL && root->right == NULL){
    int sum = 0;
      for(auto i:v) sum+=i;
      if(sum == k) path.push_back(v);
  }

  v.pop_back();
}
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        path.clear();
        printPATH(root,targetSum);
        return path;
    }
};
```

# Trim a Binary Search Tree
**QLink:** https://leetcode.com/problems/trim-a-binary-search-tree/

```c++
int l,h;
TreeNode* valid(TreeNode *root)
{
    if(!root) return nullptr;
    else if(root->val > h)
        return valid(root->left);
    else if(root->val < l) 
        return valid(root->right);
    else return root;
}
void fn(TreeNode *newRoot)
{
    if(!newRoot) return;
    newRoot->left = valid(newRoot->left);
    newRoot->right = valid(newRoot->right);
    fn(newRoot->left);
    fn(newRoot->right);
}
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        l = low;
        h = high;
        TreeNode *ans = valid(root);
        fn(ans);
        return ans;
    }
};
```

