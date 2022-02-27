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
