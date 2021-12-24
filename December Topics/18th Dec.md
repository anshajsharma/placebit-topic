# Find first set bit 
**QLink:** https://practice.geeksforgeeks.org/problems/find-first-set-bit-1587115620/1#

```c++
unsigned int getFirstSetBit(int n)
{
    if(n==0) return 0;
    for(unsigned int i=0;i<32;i++)
        if(n>>i & 1) return i+1;

    return 0;
}
```

# Rightmost different bit
**QLink:** https://practice.geeksforgeeks.org/problems/rightmost-different-bit-1587115621/1#

```c++
int posOfRightMostDiffBit(int m, int n)
{
    if(n==m) return -1;
    for(unsigned int i=0;i<32;i++)
        if( (n>>i & 1) ^ (m>>i & 1) ) return i+1;

    return 0;
}
```

# Set kth bit
**QLink:** https://practice.geeksforgeeks.org/problems/set-kth-bit3724/1#

```c++
int setKthBit(int N, int K)
{
    // Write Your Code here
    return N | (1 << K);
}
```

# Bit Difference 
**QLink:** https://practice.geeksforgeeks.org/problems/bit-difference-1587115620/1

```c++
int countBitsFlip(int a, int b){

    // Your logic here
    int c = a^b;
    int ans=0;
    while(c>0)
    {
        if(c%2) ans++;
        c/=2;
    }

    return ans;
}
```
# Set Matrix
**Qlink** https://leetcode.com/problems/set-matrix-zeroes/

```c++
#include<stdio.h>
#include<bits/stdc++.h>
#include<limits>
#include<vector>
#include<iostream>
#include<cmath>

#define input(v,n)              int n; cin>> n; vector<int>v(n); for(int i = 0;i<n;i++) cin>>v[i];
#define output(v)               for(auto i : v) cout<<i<<" ";cout<<endl;
#define outputm(v)              for(auto i : v) cout<<i.first<<" "<<i.second<<endl;
#define pb(n)                   push_back(n);
#define ar2di(v,n,m)            int n,m; cin>>n>>m; vector<vector<int>>v(n,vector<int>(m)); for(int i=0;i<n;i++){for(int j=0;j<m;j++) cin>>v[i][j];}
#define ar2do(v)                for(int i=0; i<v.size();i++) {for(int j=0;j<v[i].size();j++) cout<<v[i][j]<<" ";  cout<<endl;}
typedef long long  ll;

using namespace std;

void solve()
{
    ar2di(v,r,c);

    unordered_set<int>sr;
    unordered_set<int>sc;

 int i=0,j;

 while (i<r)
 {
    for(j=0;j<c;j++)
    {
        if(v[i][j]==0)
        {
            sr.insert(i);
            sc.insert(j);
        }

    }
    i++;
 }

 for(auto i : sr)
 {
    for(int j=0;j<v[i].size();j++)
        v[i][j]=0;
 }

 for(auto i: sc) cout<<i<<" ";
    cout<<endl;

 for(auto i: sc)
 {
    for(int j=0;j<v.size();j++)
        v[j][i]=0;
 }

 ar2do(v);



}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        solve();
    }

    // solve();

    return 0;
}





```