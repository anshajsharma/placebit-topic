# Course Schedule - 1

```c++
typedef long long ll;


void moveElement(int num,set<int>& a,set<int>& b )
{
  a.erase(num); b.insert(num);
}
bool dfs(set<int> &whiteSet,set<int> &greySet,set<int> &blackSet,int root,vector<ll> adj[])
{
    moveElement(root,whiteSet,greySet);
    for(auto i : adj[root])
    {
      if(blackSet.find(i)!=blackSet.end())
      {
        continue;
      }
      else if(greySet.find(i)!=greySet.end())
      {
        return true;
      }else if(dfs(whiteSet,greySet,blackSet,i,adj)){
        return true;
      }
    }
    moveElement(root,greySet,blackSet);
    return false;
}
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      vector<ll> adj[numCourses];
        
      set<int> whiteSet;  // Contains Unvisited vertices
      set<int> greySet;   // Contains in use vertices
      set<int> blackSet;  // Contains explored vertices

      for(int i=0;i<prerequisites.size();i++) {
          adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
      }
        
      for(int i=0;i<numCourses;i++){  // for 0 based indexing
        whiteSet.insert(i);
      }
        
      int f=0;
      while(whiteSet.size()>0){
        int root  = *whiteSet.begin();
        if(dfs(whiteSet,greySet,blackSet,root,adj)) f=1;
      }

      return !f;
    }
};
```

# Course Schedule 2

```c++
typedef long long ll;


void moveElement(int num,set<int>& a,set<int>& b )
{
  a.erase(num); b.insert(num);
}
bool dfs(set<int> &whiteSet,set<int> &greySet,set<int> &blackSet,int root,vector<ll> adj[])
{
    moveElement(root,whiteSet,greySet);
    for(auto i : adj[root])
    {
      if(blackSet.find(i)!=blackSet.end())
      {
        continue;
      }
      else if(greySet.find(i)!=greySet.end())
      {
        return true;
      }else if(dfs(whiteSet,greySet,blackSet,i,adj)){
        return true;
      }
    }
    moveElement(root,greySet,blackSet);
    return false;
}

void topological_sort(int root,vector<int> &v,vector<int> &vis,vector<ll> edges[])
{
    vis[root] = 1;
    for(auto child:edges[root])
    {
        if(!vis[child]){
            vis[child] = 1;
            topological_sort(child,v,vis,edges);
        }
    }
    v.push_back(root);
}
// void dfs(int root)
// {
//     vis[root] = 1;
//     for(auto child:edges[root])
//     {
//         if(!vis[child]){
//             vis[child] = 1;
//             dfs(child);
//         }
//     }
// }
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      vector<int> ans;
      vector<ll> adj[numCourses];
      vector<int> vis(numCourses,0);
        
      set<int> whiteSet;  // Contains Unvisited vertices
      set<int> greySet;   // Contains in use vertices
      set<int> blackSet;  // Contains explored vertices

      for(int i=0;i<prerequisites.size();i++) {
          adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
      }
        
      for(int i=0;i<numCourses;i++){  // for 0 based indexing
        whiteSet.insert(i);
      }
        
      int f=0;
      while(whiteSet.size()>0){
        int root  = *whiteSet.begin();
        if(dfs(whiteSet,greySet,blackSet,root,adj)) f=1;
      }

      if(f) return ans;
      else{
          for(int i=0;i<numCourses;i++)
          if(!vis[i]) topological_sort(i,ans,vis,adj);
          reverse(ans.begin(),ans.end());
          return ans;
      }
    }
};
```
