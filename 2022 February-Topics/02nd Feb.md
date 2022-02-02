# Reorganize String

```c++
string reorganizeString(string s) {

    int n=s.size();
    map<char,int> m;
    for(auto i:s) m[i]++;

    vector< pair<int,char> > v;
    for(auto p:m){
        int freq = p.second;
        char c = p.first;
        if(freq > (n+1)/2) return "";
        v.push_back({freq,c});
    }
    sort(v.rbegin(),v.rend());
    int i = 0;
    int maxFreq = v[0].first;
    string ans="";

    vector<string> strs(maxFreq,"");

    for(auto p:v)
    {
        int freq = p.first;
        while(freq--){
            strs[i % maxFreq] += p.second;
            i++;
            // if(i==maxFreq) i = 0;
        }
    }

    for(auto i:strs) ans += i;

    return ans;
}
```

# Nth Magical Number
```c++
#include <bits/stdc++.h>
typedef long long ll;
ll check(vector<int> &p,long mid)
{
    ll n = p.size();
    ll ans=0;
    for(int i=1;i<1<<n;i++)
    {
        ll prod = 1,c=0;
        for(int j=0;j<n;j++)
        {
            if(i>>j & 1) {
                c++;
                if(prod<=mid){
                    prod = (prod*p[j])/__gcd(prod,1ll*p[j]);
                }
            }
        }
        if(c%2) ans += (mid/prod);
        else ans -= (mid/prod);
    }
    // cout<<ans<<" "<<mid<<" ";
    return ans;
}
class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long ans = 0;
        long low = 2,high = 1e14;
        vector<int> v = {a,b};
        while(low <= high)
        {
            long mid = (low+high)/2;
            long numberInSetTillMid = check(v,mid);
            if(numberInSetTillMid>=n){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        int mod = 1e9 + 7;
        return ans%(mod);
    }
};
```
