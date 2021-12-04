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
# Find Common Characters
**QLink:** https://leetcode.com/problems/find-common-characters/

```c++
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        
        map<int,int> m[n];
        for(int i=0;i<n;i++)
        {
            for(auto j:words[i]) {
                m[i][j-'a']++;
            }
        }
        map<int,int> t;
        for(int i=0;i<26;i++)
        {
            int mini = INT_MAX;
            for(int j=0;j<n;j++)
            {
                mini = min(mini,m[j][i]);
            }
            if(mini) t[i] = mini;
        }
        vector<string> ans;
        for( auto i: t )
        {
            int c = i.second;
            while(c--){
                string temp = "";
                temp += char(i.first+'a');
                ans.push_back(temp);
            }
        }
        return ans;
    }
};

// Type 2
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        map<int,int> t;
        for(int i='a';i<='z';i++)
        {
            char reqChar = char(i);
            int mini = INT_MAX;
            for(int j=0;j<words.size();j++)
            {
                int c=0;
                for(int k=0;k<words[j].size();k++)
                {
                    if(words[j][k] == reqChar) c++;
                }
                mini = min(mini,c);
            }
            
            if(mini) t[i-'a']=mini;
                
        }
        
        vector<string> ans;
        for( auto i: t )
        {
            int c = i.second;
            while(c--){
                string temp = "";
                temp += char(i.first+'a');
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
```

# Remove Outermost Parentheses
**QLink:** https://leetcode.com/problems/remove-outermost-parentheses/

```c++
class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(st.empty()||s[i]=='('){
                st.push(i);
            }else if( s[st.top()] == '(' && s[i] == ')' ){
                if(st.size() == 1){
                    for(int j=st.top()+1;j<i;j++){
                        ans += s[j];
                    }
                }   
                st.pop();
            }
        }
        
        return ans;
        
    }
};
```
# Daily Temperatures
**QLink:** https://leetcode.com/problems/daily-temperatures/

```c++
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        vector<int> ans(n,0);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && t[s.top()] <= t[i])
                s.pop();
            if(!s.empty()){
                ans[i] = s.top() - i; 
            }
            s.push(i);
        }
        return ans;
    }
};
```
