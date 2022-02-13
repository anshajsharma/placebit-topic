# Dynamic Programming Introduction

```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;

std::vector<ll> fact(1e5),inverseFact(1e5);


ll power(ll n,ll m)
{
  if(m==0) return 1;
  else if(m%2) return (n*power((n*n)%mod,m/2))%mod;
  else return power((n*n)%mod,m/2);
}

void preProcess()
{
  fact[0] = 1;
  fact[1] = 1;
  for(ll i=2;i<1e5;i++)
  {
    fact[i] = (i*fact[i-1])%mod;
  }
  inverseFact[1e5 - 1] = power( fact[1e5 - 1] , mod - 2 );
  for(ll i=1e5-2;i>=0;i--)
  {
    inverseFact[i] = ((i+1)*inverseFact[i+1])%mod;
  }
}


void solve()
{
  // clear fib
  ll n,r;
  cin>>n>>r;
  // you have to print nCr
  ll ans = fact [n];
  ans = (ans * inverseFact[r])%mod;
  ans = (ans * inverseFact[n-r])%mod;
  cout<<ans<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt" , "r" , stdin);
  freopen("op3.txt" , "w" , stdout);
#endif
 
      
    
    ll t;
    cin>>t;
    preProcess();
    while(t--){
      // clear fib
      solve();
    }
    


  return 0;
}

```
