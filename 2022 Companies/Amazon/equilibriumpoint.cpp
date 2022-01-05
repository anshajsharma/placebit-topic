#include<stdio.h>
#include<bits/stdc++.h>
#include<limits>
#include<vector>
#include<iostream>

#define input(v,n)              int n; cin>> n; vector<int>v(n); for(int i = 0;i<n;i++) cin>>v[i];
#define output(v)               for(auto i : v) cout<<i<<" "; cout<<endl;
#define outputm(v)              for(auto i : v) cout<<i.first<<" "<<i.second<<endl;
#define ll                      long long;
#define pb(n)  				    push_back(n);

using namespace std;

void solve()
{
	input(v,n);

	int suffix=0,prefix=0;
	for(auto i : v) suffix += i;

		for( int i=1;i<n;i++)
		{
			prefix += v[i-1]; 
			if(prefix == suffix-v[i]-prefix)
			{
				cout<<" Equiblirium point is "<<v[i]<<" at index "<<i<<endl;
				break;
			}
		}
}


int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		solve();
	}
	return 0;
}