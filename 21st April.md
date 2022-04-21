# SCC

```c++
#include<bits/stdc++.h>
using namespace std;

std::vector<int> edges[100001];
vector<int> vis(100001,0);

stack<int> s;
vector<int> SCC[100];
int sccCount = 0;

void dfs(int root)
{
  vis[root] = 1;
  for(auto i:edges[root])
    if(!vis[i]) dfs(i);

  // ans.push_back(root);
  s.push(root);
}

std::vector<int> revEdges[100001];
vector<int> revVis(100001,0);

void revDFS(int root)
{
  SCC[sccCount].push_back(root);
  revVis[root] = 1;
  for(auto i:revEdges[root])
    if(!revVis[i]) revDFS(i);
}

void solve(){
  
  int n,e;
  cin>>n>>e;

  for(int i=0;i<e;i++)
  {
    int x,y;
    cin>>x>>y;

    // add edge in graph
    edges[x].push_back(y);

    // add edge in reverse graph
    revEdges[y].push_back(x);
  }

  for(int i=1;i<=n;i++)
    if(!vis[i]) dfs(i);

  while(!s.empty())
  {
    int root = s.top();
    s.pop();

    if(!revVis[root]) {revDFS(root); sccCount++;}
  }

  cout<<sccCount<<endl;

  for(int i=0;i<sccCount;i++)
  {
    for(auto j:SCC[i])
      cout<<j<<" ";
    cout<<endl;
  }

}


int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt" , "r" , stdin);
  freopen("op3.txt" , "w" , stdout);
#endif
    
    int t=1;
    while(t--){
      solve();
    }

  return 0;
}

```
