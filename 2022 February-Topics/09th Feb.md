# Largest Number

```c++
bool comp(int a,int b)
{
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        sort(nums.begin(),nums.end(),comp);
        string ans="";
        for(auto i:nums) ans+=to_string(i);
        
        int f=0;
        for(auto i:ans) if(i!='0') f=1;
        if(!f) ans = "0";
        
        return ans;
    }
};
```

# Gas Station (Array Circle Problem)

```c++
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int n=gas.size();
        // for(int i=0;i<n;i++)
        // {
        //     gas.push_back(gas[i]);
        //     cost.push_back(cost[i]);
        // }
        int i=0;
        int gasSum = 0, costSum = 0;
        for(;i<n;i++)
        {
            int cnt = 0;
            gasSum = 0, costSum=0;
            int tempI = i;
            while(i<2*n && gasSum +  gas[i%n] >= costSum + cost[i%n] ) {
                cnt++;
                gasSum +=  gas[i%n];
                costSum += cost[i%n];
                i++;
            }
            if(cnt>n){
                return tempI;
            }
        }
        return -1;
    }
};
```
