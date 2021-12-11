# 56. Merge Intervals
**QLink:** https://leetcode.com/problems/merge-intervals/

```c++
bool comp(vector<int> &a,vector<int> &b)
{
      if(a[0]!=b[0]) return a[0]<b[0];
      else return a[1]<b[1];
}
class Solution {
public:
   
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end(),comp);
        
        int n=intervals.size();
        int st=intervals[0][0],end = intervals[0][1];
        for(int i=0;i<n-1;i++)
        {
            if(end>=intervals[i+1][0]){
              end = max(end,intervals[i+1][1]);
            }else{
              vector<int> v = {st,end};
              ans.push_back(v);
              st  = intervals[i+1][0];
              end = intervals[i+1][1];
            }
        }
        vector<int> v = {st,end};
        ans.push_back(v);

        return ans;
        
    }

};
```

# Majority Element
**QLink:** https://leetcode.com/problems/majority-element/
```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Note: Way 1 & Way 4 won't work if majority element is not present
        // Way 1
        // TC: O(n*logn) 
        // SC: o(n) o(1)
        // sort(nums.begin(),nums.end());
        // return nums[nums.size()/2];
        
        // Way 2
        // TC: O(n*logn)
        // SC: O(n)
        // map<int,int> m;
        // for(auto i:nums) m[i]++;
        // for(auto p:m) if(p.second > nums.size()/2) return p.first;
        // return -1;
        
        // Way 3
        // TC: O(n)
        // SC: O(n)
        // unordered_map<int,int> m;
        // for(auto i:nums) m[i]++;
        // for(auto p:m) if(p.second > nums.size()/2) return p.first;
        // return -1;
        
        // Way 4
        // TC: O(n)
        // SC: O(1)
        int maj = nums[0];
        int sum=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==maj){
                sum++;
            }else{
                if(sum)
                sum--;
                if(sum==0)
                {
                    maj = nums[i+1];
                }
            }
        }
        return maj;
        
        
    }
};


```

# Minimum Platform
**QLink:** https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
```c++
int findPlatform(int arr[], int dep[], int n)
{
  // Your code here
  vector< pair<int,char> > v;
  for(int i=0;i<n;i++)
  {
      v.push_back({arr[i],'A'});
      v.push_back({dep[i],'D'});
  }
  sort(v.begin(),v.end());
  int c=0,ans=0;
  for(auto p:v)
  {
      if(p.second == 'A'){
          c++;
      }else{
          c--;
      }
      ans = max(ans,c);
  }
  return ans;
}
```

