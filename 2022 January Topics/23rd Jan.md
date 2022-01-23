# Subtree of Another Tree
**QLink:** https://leetcode.com/problems/subtree-of-another-tree/ 
```c++
// TC: O(n*n)
bool helper(TreeNode* root, TreeNode* subroot) {
    if(!root && subroot) return false;
    if(root && !subroot) return false;
    if(!root && !subroot) return true;
    if(root->val != subroot->val) return false;
    else return helper(root->left,subroot->left) && helper(root->right,subroot->right);
}


class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(!subroot) return true;
        if(!root) return false;
        return helper(root,subroot) || isSubtree(root->left,subroot) || isSubtree(root->right,subroot);
    }
};
```

# 404. Sum of Left Leaves

```c++
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        if(root->left && root->left->left == NULL && root->left->right == NULL){
            return root->left->val + sumOfLeftLeaves(root->right);
        }else{
            return sumOfLeftLeaves(root->right) + sumOfLeftLeaves(root->left);
        }
    }
};
```

