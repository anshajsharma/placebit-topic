//Count distinct elements in every window 
//https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1#

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
typedef long long  ll;

using namespace std;

void solve()
{

	input(a,n);

	int k;
	cin>>k;

	vector<int>ans;
        int i = 0;

        map<int,int>m;
        
     for( i=0;i<k;i++)
        {
            m[a[i]]++;
        }
        ans.push_back(m.size());
       
           for(i=1;i<n-k+1;i++)
            {
               m[a[i-1]]--;
               m[a[i+k-1]]++;
               if(m[a[i-1]]==0)
               {
                m.erase(a[i-1]);
                cout<<i<<" "<<m.size()<<endl;

               }
               ans.push_back(m.size());
    
            }
            

            output(ans);

}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        // cout<<solve()<<endl;
        solve();
    }

    // solve();

    return 0;
}