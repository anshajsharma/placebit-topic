# Find first set bit 
**QLink:** https://practice.geeksforgeeks.org/problems/find-first-set-bit-1587115620/1#

```c++
unsigned int getFirstSetBit(int n)
{
    if(n==0) return 0;
    for(unsigned int i=0;i<32;i++)
        if(n>>i & 1) return i+1;

    return 0;
}
```

# Rightmost different bit
**QLink:** https://practice.geeksforgeeks.org/problems/rightmost-different-bit-1587115621/1#

```c++
int posOfRightMostDiffBit(int m, int n)
{
    if(n==m) return -1;
    for(unsigned int i=0;i<32;i++)
        if( (n>>i & 1) ^ (m>>i & 1) ) return i+1;

    return 0;
}
```

# Set kth bit
**QLink:** https://practice.geeksforgeeks.org/problems/set-kth-bit3724/1#

```c++
int setKthBit(int N, int K)
{
    // Write Your Code here
    return N | (1 << K);
}
```

#
**QLink:**

```c++

```
