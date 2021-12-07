# DI String Match
**QLink:** https://leetcode.com/problems/di-string-match/

```c++
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int i=0,j=s.size(),k=0;
        vector<int> ans;
        while(i<j){
            if(s[k]=='D'){
                ans.push_back(j);
                j--;
            }else{
                ans.push_back(i);
                i++;
            }
            k++;
        }
        ans.push_back(i);
        return ans;
    }
};
```

# Minimum Moves to Equal Array Elements
**QLink:** https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

```c++
class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long ans=0,mini=INT_MAX,cuSum=0;
        int n=nums.size();
        for(auto i:nums){
            mini = min(i*1ll,mini);
            cuSum+=i;
        }
        ans = cuSum - n*mini;
        return ans;
    }
};
```
