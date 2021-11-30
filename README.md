# Super Power of 2
Link: https://www.hackerearth.com/problem/algorithm/help-odin-again/

```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(i,j,n)    for(ll i=j;i<n;i++)
#define tc           ll t1; cin>>t1; while(t1--)
#define inp          ll n; cin>>n; ll a[n]; fr(i,0,n) cin>>a[i];
#define inp1         ll n1; cin>>n1; ll a[n1]; fr(i,0,n1) cin>>a[i];
#define vec          vector<ll>
#define pb           push_back
#define pii          pair<ll,ll>
#define mp           make_pair
#define F            first
#define S            second
#define fast         ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define srt(v)       sort(v.begin(),v.end())
#define srte(v)      sort(v.rbegin(),v.rend())
#define maxx         1000005
#define lb(v,n)      lower_bound(v.begin(),v.end(),n)-v.begin()
#define ub(v,n)      upper_bound(v.begin(),v.end(),n)-v.begin()
#define inf          LONG_MAX
#define zer          LONG_MIN
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
