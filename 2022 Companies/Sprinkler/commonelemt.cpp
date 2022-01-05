// Common Elements
// https://practice.geeksforgeeks.org/problems/common-elements5420/1
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
	input(b,m);
	input(c,o);

	int i=0,j=0,k=0;

	set<int>s;

	while(i<n && j<m && k<o)
	{
		if(a[i]==b[j] && b[j]==c[k])
		{
			s.insert(a[i]);
			i++,j++,k++;
		}
		else
		{
			if(a[i]>b[j])
			{
				if(a[i]==c[k])
				j++;
				else
				{
					if(a[i]>c[k])
					j++,k++;
					else 
					i++,j++;
				}

			}
			else if (a[i]<b[j])
			{
				if(b[j]==c[k])
					i++;
				else
				{
				if(b[j]>c[k])
					i++,k++;
				else 
					j++,i++;
				}
			}
			else if (a[i]==b[j])
			{
				if(a[i]>c[k])
					k++;
				else 
					i++,j++;
			}

		}


	}
	vector<int>ans;

	for(auto i : s) ans.pb(i);

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