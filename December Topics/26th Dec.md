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
