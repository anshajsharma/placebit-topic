# Heap Sort Implementation using Min-Heap

```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> heap;
// int sizeOfHeap = 0;
int parent(int ind)
{
  return (ind-1)/2;
}
void insertInHeap(int n)
{
  heap.push_back(n);
  int currInd = heap.size() - 1;
  while(currInd>0 && n < heap[parent(currInd)] ){
    swap(heap[currInd],heap[parent(currInd)]);
    currInd = parent(currInd);
  }
}
vector<int> sortedArray;
void deleteFromHeap()
{
  if(heap.size()==0) return;
  int  n = heap.size();
  sortedArray.push_back(heap[0]);
  if(n==1) return;
  heap[0] =  heap[n-1];
  heap.pop_back();

  int currInd = 0;

  while(2*currInd+1<n)
  {
    int f=0;
    int mini = heap[2*currInd+1];
    if(2*currInd+2<n && heap[2*currInd+2] <= mini 
      && heap[2*currInd+2] < heap[currInd] ) {
      swap(heap[currInd],heap[2*currInd+2]);
      currInd = 2*currInd + 2;
    }else if(mini < heap[currInd]){
      swap(heap[currInd],heap[2*currInd+1]);
      currInd = 2*currInd + 1;
    }else{
      break;
    }
  }
}

void solve()
{

  int n;
  cin>>n;


  for(int i=0;i<n;i++)
  {
    int ele;
    cin>>ele;
    insertInHeap(ele);
  }

  for(auto i:heap) cout<<i<<" ";

  for(int i=0;i<n;i++) deleteFromHeap();
  cout<<"\n";
  for(auto i:sortedArray) cout<<i<<" ";

}
```

# Priority Queue STL( Max Heap )

```c++
void solve()
{

  priority_queue<int> pq;

  pq.push(10);
  pq.push(5);
  pq.push(15);

  cout<<pq.top()<<"\n";
  cout<<pq.size()<<"\n";
  cout<<pq.empty()<<"\n";
  pq.pop();
  cout<<pq.top()<<"\n";
}
```
# Priority Queue STL( Min Heap )

```c++
void solve()
{
  vector<int> v = {1,5,8,4,1,6,2,8};

  // sort(v.begin(), v.end());

  // Decreasing Order
  // sort(v.rbegin(), v.rend());
  sort(v.begin(), v.end(), greater<int>());

  for(auto i:v) cout<<i<<" ";

  cout<<"\n";

  priority_queue<int,vector<int>,greater<int> > pq;

  pq.push(10);
  pq.push(5);
  pq.push(15);

  cout<<pq.top()<<"\n";
  cout<<pq.size()<<"\n";
  cout<<pq.empty()<<"\n";
  pq.pop();
  cout<<pq.top()<<"\n";
}
```
