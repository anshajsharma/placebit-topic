# Convert Sorted Array to Binary Search Tree
**QLink:** https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
```c++
TreeNode* createBST(vector<int>& nums,int low,int high)
{
    
    if(low>high) return NULL;
    int mid = (low+high)/2;
    TreeNode *node = new TreeNode(nums[mid]);
    
    node->left = createBST(nums,low,mid-1);
    node->right = createBST(nums,mid+1,high);
    
    return node;
    
}
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createBST(nums,0,nums.size()-1);
    }
};
```
# Average of Levels in Binary Tree
**QLink:** https://leetcode.com/problems/average-of-levels-in-binary-tree/
```c++
unordered_map<int,long long> sum,cnt;
int maxLev=0;
void fillV(TreeNode* root,int level)
{
    if(!root) return;
    // v.push_back({root->val,level});
    sum[level] += root->val;
    cnt[level]++;
    maxLev = max(maxLev,level);
    // 3 9 20 15 7
    fillV(root->left,level+1);
    fillV(root->right,level+1);
}
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        sum.clear();
        cnt.clear();
        maxLev=0;
        fillV(root,0);
        vector<double> ans;
        for(int i=0;i<=maxLev;i++)
        {
            double temp = (sum[i] * 1.0) / cnt[i];
            ans.push_back(temp);
        }
        return ans;
    }
};
```

# Convert Sorted Array to Binary Search Tree
**QLink:** https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
```c++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val) swap(p,q);
        TreeNode *temp = root;
        while(1){
            if(temp->val > q->val){
                temp = temp->left;
            }else if(temp->val < p->val){
                temp = temp->right;
            }else{
                return temp;
            }
        }
    }
};
```

