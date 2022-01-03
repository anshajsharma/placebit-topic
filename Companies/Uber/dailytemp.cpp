//daily temperature
//*QLink*  https://leetcode.com/problems/daily-temperatures/

#include<bits/stdc++.h>


#define input(v,n)              int n; cin>> n; vector<int>v(n); for(int i = 0;i<n;i++) cin>>v[i];
#define output(v)               for(auto i : v) cout<<i<<" ";cout<<endl;
#define outputm(v)              for(auto i : v) cout<<i.first<<" "<<i.second<<endl;
#define pb(n)  				    push_back(n);
#define ar2di(v,n,m)            int n,m; cin>>n>>m; vector<vector<int>>v(n,vector<int>(m)); for(int i=0;i<n;i++){for(int j=0;j<m;j++) cin>>v[i][j];}
#define ar2do(v)                for(int i=0; i<v.size();i++) {for(int j=0;j<v[i].size();j++) cout<<v[i][j]<<" ";  cout<<endl;}
#define M                       100000007;
typedef long long  ll;


using namespace std;

void solve()
{
	input(t,n);

	stack<int>s;
	vector<int>ans(n,0);

	for(int i=t.size()-1;i>=0;i--)
	{
		while(!s.empty() && t[s.top()]<=t[i])
			s.pop();

		if(!s.empty())
			ans[i] = s.top()-i;

		s.push(i);

	}

	output(ans);

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