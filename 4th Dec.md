# Sort an array according to the other placebit-topic
**QLink:** https://practice.geeksforgeeks.org/problems/relative-sorting4323/1#  

```c++
map<int,int> m;

bool comp(const int &a,const int &b)
{
    if( m.find(a) == m.end() && m.find(b) == m.end() ) 
        return a<b;
    if( m.find(a) != m.end() && m.find(b) == m.end() )
        return true;
    
    if( m.find(a) == m.end() && m.find(b) != m.end() )
        return false;
    
    return m[a] < m[b];
}

class Solution{
    public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]
    
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
        //Your code 
        m.clear();
        for(int i=0;i<M;i++)
        {
            if(m.find(A2[i]) == m.end()){
                m[A2[i]] = i;
            }
        }
        
        sort(A1.begin(),A1.end(),comp);
        
        return A1;
    } 
};
```
# Array Pair Sum Divisibility Problem 
**QLink:** https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1

```c++
bool canPair(vector<int> nums, int k) {
    // Code here.
    map<int,int> m;
    for(auto i:nums)
    {
        m[i%k]++;
    }
    int f=1;
    for(int i=0;i<k;i++)
    {
        if(i==0){
         if(m[i] & 1) f=0;   
        }else if(k%2 == 0 && i == k/2){
            if(m[i] & 1) f=0; 
        }else{
            if(m[i] != m[k-i]) f=0;
        }
    }
    return f;
}
```
