# Heap Sort Implementation using Array
```c++
int parent(int ind)
{
  return (ind-1)/2;
}
class Solution
{
    public:
    //Heapify function to maintain heap property.

    void heapify(int arr[], int n, int currInd)  
    {
      // Your Code Here
      while(currInd>0 && arr[currInd] < arr[parent(currInd)] ){
        swap(arr[currInd],arr[parent(currInd)]);
        currInd = parent(currInd);
      }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
        for(int i=0;i<n;i++){
            heapify(arr,n,i);
        }
    }
    
    void deleteFromHeap(int arr[], int n)
    {
      if(n<=0) return;
      swap(arr[0],arr[n]);

    
      int currInd = 0;
    //   n--;
      while(2*currInd+1<n)
      {
        int f=0;
        int mini = arr[2*currInd+1];
        if(2*currInd+2<n && arr[2*currInd+2] <= mini 
          && arr[2*currInd+2] < arr[currInd] ) {
          swap(arr[currInd],arr[2*currInd+2]);
          currInd = 2*currInd + 2;
        }else if(mini < arr[currInd]){
          swap(arr[currInd],arr[2*currInd+1]);
          currInd = 2*currInd + 1;
        }else{
          break;
        }
      }
    }
    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        // here --------------------------
        buildHeap(arr,n);
        // for(int i=0;i<n;i++)
        // cout<<arr[i]<<" ";
        for(int i=0;i<n;i++)
        {
            deleteFromHeap(arr,n-1-i);
        }
        
        for(int i=0;i<n/2;i++)
         swap(arr[i],arr[n-1-i]);
        
    }
};

```

# Kth Largest Element
```c++
vector<int> kthLargest(int k, int arr[], int n) {
    // code here
    priority_queue<int,vector<int>,greater<int> > pq;

    vector<int> ans;
    for(int i=0;i<k-1;i++){
        pq.push(arr[i]);
        ans.push_back(-1);
    }
    pq.push(arr[k-1]);
    ans.push_back(pq.top());
    for(int i=k;i<n;i++)
    {
        if(pq.top()<arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
        ans.push_back(pq.top());
    }

    return ans;
}
```

# Last Stone Weight

```c++
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto i:stones) pq.push(i);
        
        int ans=0;
        
        while(pq.size()>1){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if(x!=y) pq.push(y-x);
        }
        
        if(pq.size()) ans = pq.top();
        
        return ans;
        
    }
};
```
