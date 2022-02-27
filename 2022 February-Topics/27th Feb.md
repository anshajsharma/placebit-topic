# Matrix Exponentiation
https://www.codechef.com/problems/TILE  
https://www.spoj.com/problems/SPP/  

```c++
const int N=3;
struct matrix
{
    ll mat[N][N];
    void null()
    {
        memset(mat,0,sizeof(mat));
    }
    void identity()
    {
        null();
        rep(i,0,N)
        mat[i][i]=1;
    }
    matrix operator *(const matrix &mat1)
    {
        matrix res;
        rep(i,0,N)
        {
            rep(j,0,N)
            {
                res.mat[i][j]=0;
                rep(k,0,N)
                res.mat[i][j]=(res.mat[i][j]+(mat[i][k]*mat1.mat[k][j])%mod)%mod;
            }
        }
        return res;
    }
};
matrix mat_exp(ll n,matrix a)
{
    matrix res;
    res.identity();
    while(n)
    {
        if(n&(ll)1)
        res=res*a;
        a=a*a;
        n>>=(ll)1;
    }
    return res;
}
int main()
{
 
    return 0;   
}
```


# Longest Palindromic Sunsequence
```c++
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        // subseq of size 1
        for(int i=0;i<n;i++) dp[i][i] = 1;
        
        // subseq of size 2
        for(int i=0;i<n-1;i++) if(s[i]==s[i+1]) dp[i][i+1] = 2; else dp[i][i+1] = 1;
        
        int colStart = 2;
        
        while(colStart<n)
        {
            
            int i = 0, j = colStart;
            
            while(j<n)
            {
                if(s[i]==s[j]){
                    dp[i][j] = 2 + dp[i+1][j-1];
                }else{
                    dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
                }
                i++; j++;
            }
            
            colStart++;
        }
        return dp[0][n-1];
    }
};
```
