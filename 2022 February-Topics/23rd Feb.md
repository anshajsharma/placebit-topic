# Coin Change

```c++
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> dp(amount+1,INT_MAX);
        sort(coins.begin(),coins.end());
        dp[0] = 0;
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i-coins[j]>=0 && dp[i-coins[j]] != INT_MAX){
                    dp[i] = min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
```

# Coin change 2

```c++
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        // dp[0] = 1;
        for(int i=0;i<=n;i++) dp[i][0] = 1;
        
        
            for(int i=1;i<=n;i++)
                for(int j=1;j<=amount;j++)
            {
                dp[i][j] = dp[i-1][j];
                if(j-coins[i-1]>=0){
                    dp[i][j] += dp[i][j-coins[i-1]];
                }
            }
        
  
        return dp[n][amount];
    }
};
```
