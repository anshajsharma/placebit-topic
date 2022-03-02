# 880. Decoded String at Index
**QLink:** https://leetcode.com/problems/decoded-string-at-index/
```c++
typedef long long ll;
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        vector<pair<string,ll>> v;
        string temp = "";
        // leet23code3
        // {"leet", 6} , {"code",3}
        for(int i=0;i<s.size();i++)
        {
            if(s[i] >= '0' && s[i] <='9' ){
                ll num  = s[i] - '0';
                if(temp == ""){
                    if(v.size()){
                        v[v.size()-1].second *= num;
                    }
                }else{
                    v.push_back({temp,num});
                }
                temp = "";
            }else{
                temp += s[i];
            }
        }
        
        if(temp != "") v.push_back({temp,1});
        
        ll cIndex = 0;
        
        // kth-index
        
        string ans = "";
        
        int i=0;
        ll maxPossibleIndex=0,sumOfStringLen;
        // leet2code3 30
        // {leet 2},{code,3}
        // 6
        while(1)
        {  
            if((maxPossibleIndex + v[i].first.size()) * v[i].second >= k){
                k %= (maxPossibleIndex + v[i].first.size());
                if(k==0) k = (maxPossibleIndex + v[i].first.size());
                int l = v[i].first.size();
                if(k>maxPossibleIndex && k<=(maxPossibleIndex + l)){
                    int ind = (k-maxPossibleIndex-1+l)%l;
                    ans += v[i].first[ind];
                    return ans;
                }
                i=0;
                maxPossibleIndex = 0;
                continue;
            }
            maxPossibleIndex = (maxPossibleIndex + v[i].first.size()) * v[i].second;
            i++;
        }
        
        return ans;
        
        
        
    }
};
```
