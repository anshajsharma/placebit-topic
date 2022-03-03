# Bell Number
https://www.geeksforgeeks.org/bell-numbers-number-of-ways-to-partition-a-set/
```c++
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;

ll fact[100005];
ll invfact[100005];
ll power(ll x,ll y)
{
    if(y==0)
    return 1;
    
    if(y%2==0)
    return power((x*x)%mod,y/2)%mod;
    else
    return (x*power((x*x)%mod,y/2))%mod;
}
ll ncr(ll n,ll r)
{
  if(r==0) return 1;
    ll ans=1;
    ans=(ans*fact[n])%mod;
    ans=(ans*invfact[r])%mod;
    ans=(ans*invfact[n-r])%mod;
    
    return ans;
}

void solve()
{
    fact[1]=1;
    fact[0]=1;
    for(int i=2;i<100005;i++)
    fact[i]=(fact[i-1]*i)%mod;
    
    invfact[100004]=power(fact[100004],mod-2)%mod;
    for(int i=100004;i>=1;i--)
    {
        invfact[i-1]=(invfact[i]*i)%mod;
    }
    int n;
    cin>>n;
    std::vector<ll> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
      for(int j=i-1;j>=0;j--)
      {
        dp[i] = ( dp[i] + ncr(i-1,i-j-1) * dp[j]  )%mod;
      }
    }

    cout<<dp[n]<<" ";

}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt" , "r" , stdin);
  freopen("op3.txt" , "w" , stdout);
#endif
 
      
    
    ll t=1;
    // cin>>t;
    // preProcess();
    while(t--){
      // clear fib
      solve();
    }
    


  return 0;
}

```
