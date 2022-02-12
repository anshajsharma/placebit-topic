# 2D Vector Printing

```c++
bool isvalid(int i,int j,int r,int c)
{
  return (i>=0 && i<r) && (j>=0 && j<c);
}

void solve()
{
  int r,c;
  cin>>r>>c;
  std::vector< std::vector<int> > v (r,std::vector<int> (c,INT_MAX)) ;
  queue< pair<int,int> > q;
  if(r%2 && c%2){
    v[r/2][c/2] = 0;
    q.push({r/2,c/2});
  }else if( r%2 && c%2==0){
    v[r/2][c/2] = 0;
    v[r/2][c/2-1] = 0;
    q.push({r/2,c/2});
    q.push({r/2,c/2-1});
  }else if( r%2==0 && c%2){
    v[r/2][c/2] = 0;
    v[r/2-1][c/2] = 0;
    q.push({r/2,c/2});
    q.push({r/2-1,c/2});
  }else{
    v[r/2][c/2] = 0;
    v[r/2-1][c/2] = 0;
    v[r/2][c/2-1] = 0;
    v[r/2-1][c/2-1] = 0;

    q.push({r/2,c/2});
    q.push({r/2-1,c/2});
    q.push({r/2,c/2-1});
    q.push({r/2-1,c/2-1});
  }

  while(!q.empty()){
      auto p = q.front();
      q.pop();
      if(isvalid(p.first-1,p.second,r,c)){
        if(v[p.first-1][p.second] == INT_MAX){
          v[p.first-1][p.second] = v[p.first][p.second] + 1;
          q.push({p.first-1,p.second});
        }
      }
      if(isvalid(p.first+1,p.second,r,c)){
        if(v[p.first+1][p.second] == INT_MAX){
          v[p.first+1][p.second] = v[p.first][p.second] + 1;
          q.push({p.first+1,p.second});
        }
      }
      if(isvalid(p.first,p.second-1,r,c)){
        if(v[p.first][p.second-1] == INT_MAX){
          v[p.first][p.second-1] = v[p.first][p.second] + 1;
          q.push({p.first,p.second-1});
        }
      }
      if(isvalid(p.first,p.second+1,r,c)){
        if(v[p.first][p.second+1] == INT_MAX){
          v[p.first][p.second+1] = v[p.first][p.second] + 1;
          q.push({p.first,p.second+1});
        }
      }
  }

  for(auto i:v){
    for(auto j:i){
      cout<<j<<" ";
    }
    cout<<endl;
  }
  
}
```

# Rotten Orange

```c++
bool isvalid(int i,int j,int r,int c)
{
  return (i>=0 && i<r) && (j>=0 && j<c);
}

class Solution {
public:
    int orangesRotting(vector<vector<int>>& v) {
          int r=v.size() ,c = v[0].size() ;

          std::vector< std::vector<int> > dis (r,std::vector<int> (c,INT_MAX)) ;
          queue< pair<int,int> > q;

          for(int i=0;i<r;i++)
          {
            for(int j=0;j<c;j++)
            {
              if(v[i][j]==2){
                q.push({i,j});
                dis[i][j] = 0;
              }
              if(v[i][j]==0){
                dis[i][j] = -1;
              }
            }
          }

          while(!q.empty()){
              auto p = q.front();
              q.pop();
              if(isvalid(p.first-1,p.second,r,c)){
                if(dis[p.first-1][p.second] == INT_MAX){
                  dis[p.first-1][p.second] = dis[p.first][p.second] + 1;
                  q.push({p.first-1,p.second});
                }
              }
              if(isvalid(p.first+1,p.second,r,c)){
                if(dis[p.first+1][p.second] == INT_MAX){
                  dis[p.first+1][p.second] = dis[p.first][p.second] + 1;
                  q.push({p.first+1,p.second});
                }
              }
              if(isvalid(p.first,p.second-1,r,c)){
                if(dis[p.first][p.second-1] == INT_MAX){
                  dis[p.first][p.second-1] = dis[p.first][p.second] + 1;
                  q.push({p.first,p.second-1});
                }
              }
              if(isvalid(p.first,p.second+1,r,c)){
                if(dis[p.first][p.second+1] == INT_MAX){
                  dis[p.first][p.second+1] = dis[p.first][p.second] + 1;
                  q.push({p.first,p.second+1});
                }
              }
          }
          int maxi=0;
          for(auto i:dis){
            for(auto j:i){
              maxi = max(maxi,j);
            }
          }

        return maxi == INT_MAX ? -1 : maxi ;
    }
};
```

# Split Array

```c++
bool check(vector<int> &v,int m,int mid)
{
    int currSum  = 0;
    int n = v.size();
    
    int i=0;
    int noOfSplits = 0;
    while(i<n){
        currSum += v[i];
        if(currSum>mid){
            noOfSplits++;
            currSum = 0;
            continue;
        }
        i++;
    }
    noOfSplits++; 
    return noOfSplits <= m; 
}

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int low=*max_element(nums.begin(),nums.end());
        int high = 1e9;
        int ans = 1e9;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(nums,m,mid)){
                ans = mid; // 
                high = mid-1;
            }else{
                low = mid + 1;
            }
        }
        
        return ans;
    }
};
```
