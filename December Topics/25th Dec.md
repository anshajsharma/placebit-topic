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
