# Nth Magical Number
**QLink:** https://leetcode.com/problems/nth-magical-number/
```c++
class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long ans = 0;
        long low = 2,high = 1e14;
        while(low <= high)
        {
            long mid = (low+high)/2;
            long numberInSetTillMid = mid/a + mid/b - (mid*__gcd(a,b))/(a*b);
            if(numberInSetTillMid>=n){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        int mod = 1e9 + 7;
        return ans%(mod);
    }
};
```
# Recursion Introduction

```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// TC: O(2^n)
int fibRecur(int n)
{
  if(n==0) return 0;
  if(n==1) return 1;
  return fibRecur(n-1) + fibRecur(n-2);
}

// TC: O(n)
int fibItr(int n)
{
  if(n==0) return 0;
  if(n==1) return 1;
  int c=1,a=1,b=0;
  for(int i=0;i<n-1;i++)
  {
    c = a+b;
    b = a;
    a = c;
  }
  return c;
}
// TC: O(n)
int factRecur(int n)
{
  if(n==0) return 1;
  return n*factRecur(n-1);
}


void solve()
{

  int n;
  cin>>n;

  cout<<fibRecur(n)<<endl;
  cout<<fibItr(n)<<endl;
  cout<<factRecur(n)<<endl;
}

```

# Memorization Technique
```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll fib[100];
// TC: O(n)
// Momorization Technique
ll fibRecurMemo(int n)
{
  cerr<<n<<" ";
  if(n==0) return 0;
  if(n==1) return 1;
  if(fib[n]) return fib[n];
  fib[n] = fibRecurMemo(n-1) + fibRecurMemo(n-2);
  return fib[n];
}

void solve()
{
  fib[0] = 0;
  fib[1] = 1;
  int n;
  cin>>n;

  cout<<fibRecurMemo(n)<<endl;
}
```

# Subset Sum equals k using recursion

```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll fib[100];
int n;
// O(n*2^n)
void subSethavingSumk(int index,vector<int> &originalV,vector<int> currVec,int sum)
{

  if(index == n){
    int vecSum = 0;
    for(auto i:currVec) vecSum+=i;
    if(sum == vecSum){
      for(auto i:currVec) cout<<i<<" ";
      cout<<endl;
    }

    return;
  }

  subSethavingSumk(index+1,originalV,currVec,sum);

  currVec.push_back(originalV[index]);

  subSethavingSumk(index+1,originalV,currVec,sum);

}

void solve()
{

  cin>>n;

  vector<int> v(n);
  for(auto &i:v) cin>>i;

  vector<int> temp;
  subSethavingSumk(0,v,temp,7);
}
```
# Special Keyboard 
**QLink:** https://practice.geeksforgeeks.org/problems/special-keyboard3018/1#
```c++
class Solution{
public:
    long long int optimalKeys(int N){
        // code here
        vector<int> dp(N+1,0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i=4;i<=N;i++)
        {
            dp[i] = i;
            for(int j=i-3;j>=1;j--)
            {
                dp[i] = max(dp[i],dp[j]*(i-j-1));
            }
        }
        return dp[N];
    }
};
```
