#include<stdio.h>
#include<bits/stdc++.h>
#include<limits>
#include<vector>
#include<iostream>

using namespace std;

int main()
{
	int a,c,m,sum=0,j;

	cin>>a>>c>>m;

	j = a/c;
	sum = j;

	while(j>=m)
	{
		sum += j/m;
		j = j/m + j%m;

	}

	cout<<sum;

return 0;

}