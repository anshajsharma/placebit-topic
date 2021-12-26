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

