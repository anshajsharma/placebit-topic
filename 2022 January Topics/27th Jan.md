# Diameter of Binary Tree
**QLink:** https://leetcode.com/problems/diameter-of-binary-tree/
```c++
int ans;
int helper(TreeNode* root)
{
    if(!root) return 0;
    int lh = helper(root->left);
    int rh = helper(root->right);
    ans = max(ans,lh+rh+1);
    return 1 + max(lh,rh); 
}
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans=0;
        helper(root);
        return ans-1;
    }
};
```

# Longest Univalue Path
**Qlink:** https://leetcode.com/problems/longest-univalue-path/

```c++
int ans;
int helper(TreeNode* root,TreeNode* parent)
{
    if(!root) return 0;
    int lh = helper(root->left,root);
    int rh = helper(root->right,root);
    ans = max(ans,lh+rh+1);
    if(!parent) return 0;
    if( root->val == parent->val ) return 1 + max(lh,rh);
    else return 0;
}

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        ans=0;
        helper(root,NULL);
        return ans-1;
    }
};
```


