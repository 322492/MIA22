#include <bits/stdc++.h>
 
using namespace std;
 
long long n, m;
 
long long f(long long x)
{
    return (x * (x + 1)) / 2ll;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> m;
 
    long long k = n / m;
    long long r = n - (k * m);
 
    cout << r * f(k) + (m - r) * f(k - 1) << " ";
 
    k = n - (m - 1);
 
    cout << f(k - 1);
 
    return 0;
}