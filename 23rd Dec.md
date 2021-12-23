# 775. Global and Local Inversions
**QLink:** https://leetcode.com/problems/global-and-local-inversions/

```c++
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n=nums.size();
        // int leftMax[n]={0};
        vector<int> leftMax(n,0);
        int currMax = 0;
        for(int i=0;i<n;i++)
        {
            currMax = max(currMax,nums[i]);
            leftMax[i] = currMax;
        }
        for(int i=2;i<n;i++)
        {
            if(leftMax[i-2]>nums[i]) return false;
        }
        return true;
    }
};
```
