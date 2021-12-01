# Distribute Candies

```c++  

class Solution {
public:
    vector<int> distributeCandies(int c, int n) {
        
        vector<int> ans(n,0);
        int currCandy=1;
        int currInd=0;
        while( c > 0 ){
            if(currCandy >= c){
                ans[currInd] += c;
                break;
            }else{
                ans[currInd] += currCandy;
            }
            currInd++;
            c -= currCandy;
            currCandy++;
            currInd%=n;
        }
        // for(int i=0;i<n;i++){
        //     ans[i] = ?
        // }
        return ans;
    }
};

```
