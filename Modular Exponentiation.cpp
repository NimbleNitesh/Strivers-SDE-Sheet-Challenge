#include <bits/stdc++.h>
long long binpow(long long num, int pow, int mod)
{
	long long res=1;
	while(pow)
	{
		if(pow&1)
		{
			pow--;
			res=(res*num)%mod;
		}
		else
		{
			pow=(pow>>1);
			num=(num*num)%mod;
		}
	}
	return res;
}
int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	return binpow(x, n, m);
}