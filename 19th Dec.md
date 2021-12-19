# Recursively remove all adjacent duplicates 
```c++
string remove(string s){
    // code here
    // return "ASD";
    int n=s.size();
    stack< pair<char,int> > st;
    for(int i=0;i<n;i++)
    {

        int f=0;
        while(i+1 < n && s[i]==s[i+1]) {i++; f = 1;}
        if(f==0){
            if(st.empty()){
                st.push({s[i],0});
            }else if(st.top().first == s[i]){
                st.pop();
                st.push({s[i],2});
            }else if(st.top().second == 2){
                while(!st.empty() && st.top().second == 2)
                        st.pop();
                if(!st.empty() && st.top().first == s[i]){
                    st.pop();
                    st.push({s[i],2});
                }else{
                    st.push({s[i],0});
                }
            }else{
                st.push({s[i],0});
            }
        }
    }

    string ans="";

    while(!st.empty()){
      if(st.top().second == 0)    ans+=st.top().first;
      st.pop();
    }

    reverse(ans.begin(),ans.end());

    return ans;

}
```
