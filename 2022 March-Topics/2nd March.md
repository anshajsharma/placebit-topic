# 416. Partition Equal Subset Sum

```c++
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // if odd sum return 0
        
        int sum = 0;
        
        for(auto i:nums) sum+=i;
        
        if(sum%2) return 0;
        
        int reqSum = sum/2;
        int n = nums.size();
        vector< vector<int> > dp(n+1,vector<int>(reqSum+1,0));
        dp[0][0] = 1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=reqSum;j++)
            {
                dp[i][j] = dp[i-1][j];  // without using 
                if(j>=nums[i-1]){
                    dp[i][j] |= dp[i-1][j-nums[i-1]]; // using
                }
            }
        }
        return dp[n][reqSum];
    }
};
```

# 1262. Greatest Sum Divisible by Three

https://leetcode.com/problems/greatest-sum-divisible-by-three/

```c++
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // if odd sum return 0
        
        int sum = 0;
        
        for(auto i:nums) sum+=i;
        
        if(sum%2) return 0;
        
        int reqSum = sum/2;
        int n = nums.size();
        vector< vector<int> > dp(n+1,vector<int>(reqSum+1,0));
        dp[0][0] = 1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=reqSum;j++)
            {
                dp[i][j] = dp[i-1][j];  // without using 
                if(j>=nums[i-1]){
                    dp[i][j] |= dp[i-1][j-nums[i-1]]; // using
                }
            }
        }
        return dp[n][reqSum];
    }
};
```
