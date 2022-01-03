#include<stdio.h>
#include<bits/stdc++.h>
#include<limits>
#include<vector>
#include<iostream>

using namespace std;


int main()
{
	long long n,m;
	cin>>n>>m;

	vector<long long >v(n);

    long long i;

	for(i=0;i<n;i++) cin>>v[i];

		cout<<endl<<m;



		sort(v.begin(),v.end());
		
		long long strt=0,end=m-1,ans=INT_MAX,dif;

		// for(auto  i : v) cout<< i<<" ";

	    while(end<n)
	    {
	    	dif = v[end] - v[strt];
	    	ans = min(ans,dif);

	    	strt++;
	    	end++;
	    }

	    cout<<endl;

	    cout<<ans;

			

}