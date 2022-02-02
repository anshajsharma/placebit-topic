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
