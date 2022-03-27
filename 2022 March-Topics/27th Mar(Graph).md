# BFS, Levelling, Parent, Root to any vertices path

```c++
#include<bits/stdc++.h>
using namespace std;

const int N = 100001;

vector<int> edges[N];

void addEdges(int x,int y)
{
  edges[x].push_back(y);
  edges[y].push_back(x); // if undirected
}


// bfs implementation

vector<int> vis(N,0);
vector<int> level(N,-1);
vector<int> parent(N,-1);
void bfs(int root)  // breadth first search => level order traversal
{
  if(vis[root]) return;
  vis[root] = 1;
  level[root] = 0;
  queue<int> Q;
  Q.push(root);

  while(!Q.empty()){
    int currNode = Q.front();
    Q.pop();
    cout<<currNode<<" ";
    for(auto child:edges[currNode])
    {
      if(vis[child]==0){
        vis[child] = 1;
        Q.push(child);
        
        // levelling of tree
        level[child] = level[currNode] + 1;
        
        // parent
        parent[child] = currNode;
      }
    }
  }
  cout<<endl;
}

// src is always root node
void printPath(int src,int dest)
{
  vector<int> path;
  while(dest!=-1){
    path.push_back(dest);
    dest = parent[dest];
  }
  reverse(path.begin(), path.end());
  for(auto i:path) cout<<i<<" ";
}

void solve(){
  int v,e;
  cin>>v>>e;

  for(int i=0;i<e;i++){
    int x,y;
    cin>>x>>y;
    addEdges(x,y);
  }

  // Now we have virtual graph
  // on which we can perform required operations

  for(int i=1;i<v;i++)
   if(!vis[i]) bfs(i);

  printPath(1,6);
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

# number of connected components

```c++
#include<bits/stdc++.h>
using namespace std;

const int N = 100001;

vector<int> edges[N];

void addEdges(int x,int y)
{
  edges[x].push_back(y);
  edges[y].push_back(x); // if undirected
}


// bfs implementation

vector<int> vis(N,0);
void bfs(int root)  
{
  if(vis[root]) return;
  vis[root] = 1;
  queue<int> Q;
  Q.push(root);

  while(!Q.empty()){
    int currNode = Q.front();
    Q.pop();
    for(auto child:edges[currNode])
    {
      if(vis[child]==0){
        vis[child] = 1;
        Q.push(child);
      }
    }
  }
}



void solve(){
  int v,e;
  cin>>v>>e;

  for(int i=0;i<e;i++){
    int x,y;
    cin>>x>>y;
    addEdges(x,y);
  }

  // Now we have virtual graph
  // on which we can perform required operations
  
  int ncc=0;  // number of connected components
  for(int i=1;i<v;i++)
   if(!vis[i]) {bfs(i); ncc++;}

  cout<<ncc<<endl;
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

# Detect the cycle using bfs
https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1#
```c++
// bfs implementation
int f=0;

void bfs(int root,vector<int> adj[],vector<int> &vis)  
{
  if(vis[root]) return;
  vis[root] = 1;
  queue<pair<int,int>> Q;
  Q.push({root,-1});

  while(!Q.empty()){
    int currNode = Q.front().first;
    int parent = Q.front().second;
    Q.pop();
    for(auto child:adj[currNode])
    {
      if( vis[child] == 1 && child != parent ) f=1;
      if(vis[child]==0){
        vis[child] = 1;
        Q.push({child,currNode});
      }
    }
  }
}

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        f=0;
        vector<int> vis(V+10,0);
        for(int i=0;i<V;i++)
            if(!vis[i]) bfs(i,adj,vis); 
    
        return f;
    }
};
```
