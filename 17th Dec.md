# Reverse words in a given string 
**QLink:** https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

```c++
string reverseWords(string S) 
{ 
    // code here 
    vector<string> v;
    string temp="";
    for(int i=0;i<S.size();i++)
    {
        if(S[i]=='.') {
            v.push_back(temp);
            temp = "";
        }else{
            temp += S[i];
        }
    }
    v.push_back(temp);
    string ans="";
    reverse(v.begin(),v.end());
    // for(auto i:v){
    //     ans += i;
    //     ans += ".";
    // }
    // ans.pop_back();
    for(int i=0;i<v.size();i++)
    {
        ans += v[i];
        if(i != v.size()-1) ans+='.';
    }
    return ans;
} 
```

# Check if string is rotated by two places 
**QLink:** https://practice.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places-1587115620/1

```c++
bool isClockWiseRotated(string str1, string str2)
{
    int n=str1.size();
        str1+=str1;
        for(int i=0;i<n;i++)
        {
            if(str2[i] != str1[(i+2)]) return 0;
        }
        
        return 1;
}

bool isAntiClockWiseRotated(string str1, string str2)
{
    int n=str1.size();
    swap(str1,str2);
    str1+=str1;
        for(int i=0;i<n;i++)
        {
            if(str2[i] != str1[(i+2)]) return 0;
        }
        
        return 1;
}

class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        int n=str1.size(),m=str2.size();
        if(n!=m) return 0;
        
        return isClockWiseRotated(str1,str2) || isAntiClockWiseRotated(str1,str2);
    }

};
```

# Anagram
**QLink:** https://practice.geeksforgeeks.org/problems/anagram-1587115620/1#

```c++
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // WAY 1
        int freqa[26]={0},freqb[26]={0};
        for(auto i:a) freqa[i-'a']++;
        for(auto i:b) freqb[i-'a']++;
        for(int i=0;i<26;i++)
        {
            if(freqa[i]!=freqb[i]) return 0;
        }
        return 1;
        
        // WAY 2
        int freq[26]={0};
        for(auto i:a) freq[i-'a']++;
        for(auto i:b) freq[i-'a']--;
        for(int i=0;i<26;i++)
        {
            if(freq[i]) return 0;
        }
        return 1;
        
        // WAY 3
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        return a == b;
        
    }

};
```

# Implement Atoi 
**QLink:** https://practice.geeksforgeeks.org/problems/implement-atoi/1#

```c++
class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int ans=0;
        int f=1;
        int i=0;
        
        if(s[0]=='-') {
            f = -1;
            i++;
        }
        
        // -12
        // 12
        for(;i<s.size();i++)
        {
            if(s[i]<'0'||s[i]>'9') return -1;
            ans = ans*10 + s[i]-'0';
        }
        return f*ans;
    }
};
```
# Longest Common Prefix in an Array 
**QLink:** https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1#

```c++
class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        string ans="";
        for(int i=0;;i++)
        {
            int f=1;
            if(i>=arr[0].size()) break;
            for(int j=1;j<N;j++)
            {
                if( arr[j].size() > i && arr[j][i] == arr[0][i]) ;
                else f=0;
            }
            if(f==1){
                ans += arr[0][i];
            }else{
                break;
            }
        }
        if(ans=="") return "-1";
        return ans;
    }
};
```
# 
**QLink:**

```c++

```
# 
**QLink:**

```c++

```
