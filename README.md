<h1 align="center">
    PLACEBIT CODESHARES
 </h1>

# QUESTIONS
1. ***QUEUE/STACK Intro***
```c++
void queueIntro()
{
  queue<int> q;

  int n; cin >> n;

  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    q.push(temp);
  }

  // .front()

  while (!q.empty()) {
    cout << q.front() << endl;
    q.pop();
  }
}

void stackIntro()
{
  stack<int> s;

  int n; cin >> n;

  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    s.push(temp);
  }

  // .top()

  while (!s.empty()) {
    cout << s.top() << endl;
    s.pop();
  }
}
```
<hr/>  

##  Remove All Adjacent Duplicates In String   

// QLink: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/  
```c++
string removeDuplicates(string s) {
    stack<char> st;
    for(auto i:s)
    {
       if(st.empty()){
           st.push(i);
       }else if(st.top() != i){
           st.push(i);
       }else{
           st.pop();
       }
    }
    string ans="";
    while(!st.empty()){
        // cout<< s.top() <<endl;
        ans = st.top() + ans; 
        st.pop();
    }
    return ans;
}
```  


## Minimum Size Subarray Sum
// QLink: https://leetcode.com/problems/minimum-size-subarray-sum/
```c++
// -------------------USING TWO POINTER -------------------------
int minSubArrayLen(int k, vector<int>& nums) {
    // queue<int> q;
    int i=0,j=0;
    int n = nums.size(); 
    int ans= INT_MAX;
    long long currSum = 0;

    while(i<=j && j<n){
        currSum += nums[j];
        while(currSum - nums[i] >= k){
            currSum -= nums[i];
            i++;
        }
        if(currSum>=k){
            ans = min(ans,j-i+1);
        }
        j++;
    }

    // if(ans==0) ans = 1;
    // cout<<ans<<" ";
    return ans == INT_MAX ? 0 :ans;
}
// -------------------USING STACK -------------------------
int minSubArrayLen(int k, vector<int>& nums) {
  queue<int> q;
  int n = nums.size();
  int ans = INT_MAX;
  long long currSum = 0;

  for (auto i : nums)
  {
    currSum += i;
    q.push(i);
    while (currSum - q.front() >= k && !q.empty()) {
      currSum -= q.front();
      q.pop();
    }
    if (currSum >= k) {
      int  m = q.size();
      ans = min(ans, m);
    }
  }
  return ans == INT_MAX ? 0 : ans;
}
```
