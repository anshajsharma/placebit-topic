# Super Power of 2
Link: https://www.hackerearth.com/problem/algorithm/help-odin-again/

```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long           mod = pow(10, 9) + 7;



ll stringModuloM(string s,ll m)
{
  ll ans=0;
  for(int i=0;i<s.size();i++)
  {
    ans = ans * 10 + (s[i]-'0');
    ans %= m;
  }
  return ans;
}

ll powerModuloM(ll a,ll b,ll m)
{
  if(b==0) return 1;
  if(b%2) return (a*powerModuloM((a*a)%m,b/2,m))%m;
  else return powerModuloM((a*a)%m,b/2,m) %m;
}


void solve()
{
  string a;
  long long b;
  cin>>a;
  cin>>b;

  cout << powerModuloM(2,powerModuloM(stringModuloM(a,mod-1),b,mod-1),mod)<<endl;
}


int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt" , "r" , stdin);
  freopen("op3.txt" , "w" , stdout);
#endif
  int t = 1;
  cin>>t;
  while (t--) {
    solve();
  }
  return 0;
}
```

# nCr
```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long           mod = pow(10, 9) + 7;



ll stringModuloM(string s,ll m)
{
  ll ans=0;
  for(int i=0;i<s.size();i++)
  {
    ans = ans * 10 + (s[i]-'0');
    ans %= m;
  }
  return ans;
}

ll powerModuloM(ll a,ll b,ll m)
{
  if(b==0) return 1;
  if(b%2) return (a*powerModuloM((a*a)%m,b/2,m))%m;
  else return powerModuloM((a*a)%m,b/2,m) %m;
}

ll moduloInverse(ll a,ll m)
{
  return powerModuloM(a,m-2,m);
}

ll fact[101];

ll nCr(ll n,ll r)
{
  if(r>n) return 0;
  ll ans = fact[n];
  ans = (ans * moduloInverse(fact[r],mod) ) %mod;
  ans = (ans * moduloInverse(fact[n-r],mod) ) %mod;

  return ans;
}

void solve()
{

  ll n,k;
  cin>>n>>k;

  vector<ll> v(n);
  int evenC=0;
  for(int i=0;i<n;i++) cin>>v[i];

  for(auto i:v) if(i%2 == 0) evenC++;

  
  // cout<<evenC<<endl;
  fact[0] = 1;

  for(ll i=1;i<101;i++)
  {
    fact[i] = i * fact[i-1];
    fact[i] %= mod;
  }

  cout<<nCr(evenC,k);

}


int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt" , "r" , stdin);
  freopen("op3.txt" , "w" , stdout);
#endif
  int t = 1;
  // cin>>t;
  while (t--) {
    solve();
  }
  return 0;
}
```
