#include<stdio.h>
#include<bits/stdc++.h>
#include<limits>
#include<vector>
#include<iostream>

#define input(v,n)              int n; cin>>n; vector<int>v(n); for(int i = 0;i<n;i++) cin>>v[i];
#define output(v)               for(auto i : v) cout<<i<<" ";cout<<endl;
#define outputm(v)              for(auto i : v) cout<<i.first<<" "<<i.second<<endl;
#define pb(n)  				    push_back(n);
#define ar2di(v,n,m)            int n,m; cin>>n>>m; vector<vector<int>>v(n,vector<int>(m)); for(int i=0;i<n;i++){for(int j=0;j<m;j++) cin>>v[i][j];}
#define ar2do(v)                for(int i=0; i<v.size();i++) {for(int j=0;j<v[i].size();j++) cout<<v[i][j]<<" ";  cout<<endl;}
typedef long long  ll;

using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<string>words;
	while(n--)
	{
		string a;
		cin>>a;
		words.push_back(a);
	}
	
	vector<int>a(26,0);
        
        for(auto i : words[0])
            a[i-'a']++;
        
        for(int i=1;i<words.size();i++)
        {
            vector<int>b(26,0);
            
            for(auto j : words[i])
            b[j-'a']++;
            
            for(int k=0;k<26;k++)
            {
                if(a[i]!=0 && b[i]!=0 && a[i]!=b[i])
                a[i] = min(a[i],b[i]);
                
            }
            
        }
        
        vector<string>ans;
        
        for(int i=0;i<26;i++)
        {
            if(a[i]!=0)
            {
                while(a[i]--)
                {
                    ans.push_back(string(1,'a'+ i));
                }
            }
        }

        for(auto i : ans)
        	cout<<i<<" ";


}

int main()
{
	// int t;
	// cin>>t;

	// while(t--)
	// {
	// 	solve();
	// }

	solve();

	return 0;
}