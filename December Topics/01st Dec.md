# Distribute Candies

```c++  

class Solution {
public:
    vector<int> distributeCandies(int c, int n) {
        
        vector<int> ans(n,0);
        int currCandy=1;
        int currInd=0;
        while( c > 0 ){
            if(currCandy >= c){
                ans[currInd] += c;
                break;
            }else{
                ans[currInd] += currCandy;
            }
            currInd++;
            c -= currCandy;
            currCandy++;
            currInd%=n;
        }
        // for(int i=0;i<n;i++){
        //     ans[i] = ?
        // }
        return ans;
    }
};

```
# Complement of Base 
**QLink:** https://leetcode.com/problems/complement-of-base-10-integer/  
```c++
class Solution {
public:
    int bitwiseComplement(int n) {
        int ans = 0;
        // while(n>0){
        //     ans+=char(n%2+'0');
        //     n/=2;
        // }
        if(n==0) return 1;
        int f=0;
        for(int i=30;i>=0;i--)
        {
            if( (n>>i & 1) == 0 && f){
                // cout<<i<<" ";
                ans += (1<<i);
                // ans += pow(2,i);
            }else if( (n>>i & 1) == 1 ){
                f=1;
            }
        }
        return ans;
    }
};
```
# Surface Area of 3D Shapes
**QLink:**  https://leetcode.com/problems/surface-area-of-3d-shapes/  

```c++
bool check(int i,int j,int n)
{
    return (i>=0 && i<n) && (j>=0 && j<n);
}

class Solution {
public:
    int surfaceArea(vector<vector<int>>& v) {
        int ans=0;
        int n=v.size();
        // ans += (2*n*n);
        // int m= grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(check(i-1,j,n)){
                  if(v[i][j] > v[i-1][j])  ans += (v[i][j] - v[i-1][j]); 
                }else{
                  ans += v[i][j];
                }
                if(check(i+1,j,n)){
                  if(v[i][j] > v[i+1][j])  ans += (v[i][j] - v[i+1][j]); 
                }else{
                  ans += v[i][j];
                }
                if(check(i,j-1,n)){
                  if(v[i][j] > v[i][j-1])  ans += (v[i][j] - v[i][j-1]); 
                }else{
                  ans += v[i][j];
                }
               if(check(i,j+1,n)){
                  if(v[i][j] > v[i][j+1])  ans += (v[i][j] - v[i][j+1]); 
                }else{
                  ans += v[i][j];
                }
                if(v[i][j]) ans+=2;
            }
        }
        return ans;
    }
};
```
# Largest Perimeter Triangle
**QLink:** https://leetcode.com/problems/largest-perimeter-triangle/  

```c++
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i+2<(int)nums.size();i++)
        {
            if(nums[i+2] < nums[i]+nums[i+1]){
                ans = nums[i]+nums[i+1]+nums[i+2];
            }
        }
        return ans;
    }
};
```
# Prime Arrangements
**QLink:** https://leetcode.com/problems/prime-arrangements/
```c++
bool isPrime(int n)
{
    if(n==1) return 0;
    for(int i=2;i*i<=n;i++)
        if(n%i == 0) return 0;
    return 1;
}
const long mod = 1e9 + 7;
class Solution {
public:
    int numPrimeArrangements(int n) {
        long long fact[101];
        fact[0] = 1;
        for(int i=1;i<101;i++)
        {
            fact[i] = i * fact[i-1];
            fact[i]%=mod;
        }
        int numberOfPrimes = 0;
        for(int i=1;i<=n;i++)
        {
            if(isPrime(i)) numberOfPrimes++;
        }
        
        return (fact[numberOfPrimes] * fact[n-numberOfPrimes])%mod;
        
    }
};
```
