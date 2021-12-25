# Bit Masking ( Subset Printing )

```c++
void printAllSubsetOfASet(vector<int> v,int n)
{

  for(int i=0;i<(1<<n);i++)
  {
    vector<int> subset;
    for(int j=0;j<n;j++)
    {
      if( (i>>j) & 1) subset.push_back(v[j]);
    }
    for(auto i:subset) cout<<i<<" ";
    cout<<endl;
  }
}

void solve()
{
    
  int n;
  cin>>n;

  vector<int> v(n);
  for(auto &i:v) cin>>i;

  printAllSubsetOfASet(v,n);

}
```
# sum 0 By Altering Signs (Bit Mask)
```c++
bool sum0ByAlteringSigns(vector<int> v, int n)
{

  for (int i = 0; i < (1 << n); i++)
  {
    int sum = 0;
    for (int j = 0; j < n; j++)
    {
      if ( (i >> j) & 1) sum += v[j];
      else sum -= v[j];
    }
    if (sum == 0) return true;
  }
  return false;
}

void solve()
{

  int n;
  cin >> n;

  vector<int> v(n);
  for (auto &i : v) cin >> i;

  // printAllSubsetOfASet(v,n);

  if (sum0ByAlteringSigns(v, n)) cout << "Yes";
  else cout << "No";
  cout << endl;

}
```

# 953. Verifying an Alien Dictionary
**QLink:** https://leetcode.com/problems/verifying-an-alien-dictionary/

```c++
class Solution {
public:
    bool isAlienSorted(vector<string>& s, string o) {
        map<char,char> m;
        for(int i=0;i<26;i++)
        {
            m[o[i]] = char(i+'a');
        }
        for(int i=0;i<s.size();i++)
        {
            string temp="";
            for(auto j:s[i])
            {
                temp += m[j];
            }
            s[i] = temp;
        }
        
        for(int i=1;i<s.size();i++)
        {
            if(s[i] < s[i-1]) return false;
        }
        return true;
        
    }
};
```
# Happy Number

```c++
int sumOfSquareOfDigits(int n)
{
    int sum=0;
    while(n>0){
        sum+=((n%10)*(n%10));
        n/=10;
    }
    return sum;
}
class Solution {
public:
    bool isHappy(int n) {
        map<int,int> m;
        int currSum = n;
        while(1){
            currSum = sumOfSquareOfDigits(currSum);
            m[currSum]++;
            if(currSum==1) return true;
            else if(m[currSum] > 1) return false;
        }
        return false;
    }
};
```

