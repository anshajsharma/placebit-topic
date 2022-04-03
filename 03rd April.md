# Shortest Path

```c++
#include<bits/stdc++.h>
using namespace std;

const int N = 100001;
typedef long long ll;
vector<pair<int,int>> edges[N];

void addEdges(int x,int y,int wt)
{
  edges[x].push_back({y,wt});
  edges[y].push_back({x,wt}); // if undirected
}


// TC: O(n*n)
// dfs implementation
vector<int> dis(N,INT_MAX);
void disCalculator(int root)
{
  queue<int> q;
  q.push(root);
  dis[root] = 0;
  while(!q.empty())
  {
    int currNode = q.front();
    q.pop();
    for(auto child:edges[currNode])
    {
      int ch = child.first;
      int wt = child.second;
      if(dis[ch] > dis[currNode] + wt){
        dis[ch] = dis[currNode] + wt;
        q.push(ch);
      }
    }
  }

}


void solve(){
  
  int n,e;

  cin>>n>>e;

  for(int i=0;i<e;i++)
  {
    int x,y,wt;
    cin>>x>>y>>wt;
    addEdges(x,y,wt);
  }

  disCalculator(1);

  for(int i=1;i<=n;i++)
  {
    cout<<"Dis of node " << i <<" => "<<dis[i]<<endl;
  }


}


int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt" , "r" , stdin);
  freopen("op3.txt" , "w" , stdout);
#endif
 
      
    
    int t=1;
    // cin>>t;
    // preProcess();
    while(t--){
      // clear fib
      solve();
    }
    


  return 0;
}

```

# Dijkstra Algorithm

```c++
#include<bits/stdc++.h>
using namespace std;

const int N = 100001;
typedef long long ll;
vector<pair<int,int>> edges[N];

void addEdges(int x,int y,int wt)
{
  edges[x].push_back({y,wt});
  edges[y].push_back({x,wt}); // if undirected
}


// TC: O(n*logn)
vector<int> dis(N,INT_MAX);
void dikshtraSSSP(int root)
{
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > q;
  q.push({0,root});
  dis[root] = 0;
  while(!q.empty())
  {
    int currNode = q.top().second;
    int parentDis = q.top().first;
    q.pop();
    for(auto child:edges[currNode])
    {
      int ch = child.first;
      int wt = child.second;
      if(dis[ch] > parentDis + wt){
        dis[ch] = parentDis + wt;
        q.push({dis[ch],ch});
      }
    }
  }

}


void solve(){
  
  int n,e;

  cin>>n>>e;

  for(int i=0;i<e;i++)
  {
    int x,y,wt;
    cin>>x>>y>>wt;
    addEdges(x,y,wt);
  }

  dikshtraSSSP(1);

  for(int i=1;i<=n;i++)
  {
    cout<<"Dis of node " << i <<" => "<<dis[i]<<endl;
  }


}


int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt" , "r" , stdin);
  freopen("op3.txt" , "w" , stdout);
#endif
 
      
    
    int t=1;
    // cin>>t;
    // preProcess();
    while(t--){
      // clear fib
      solve();
    }
    


  return 0;
}

```
