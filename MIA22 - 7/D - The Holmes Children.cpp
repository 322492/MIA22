#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 1000000007;
 
long long f(long long n)
{
	long long wyn = n;
	for (long long i = 2; i * i <= n; i++)
		if (n % i == 0)
		{
			while (n % i == 0)
				n /= i;
			wyn -= wyn / i;
		}
	if (n > 1)
		wyn -= wyn / n;
	return wyn;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	long long n, k;
	cin >> n >> k;
	long long res = n;
	k = (k + 1) / 2;
 
	while (k--)
	{
		res = f(res);
		if (res == 1)
			break;
	}
 
	cout << res % mod;
 
	return 0;
}