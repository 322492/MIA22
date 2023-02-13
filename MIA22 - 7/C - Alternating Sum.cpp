#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 1000000009;
long long n, a, b, k;
vector<int> c;
 
long long potmod(long long a, long long b)
{
    long long bity = b;
    long long wynik = 1;
    a = a % mod;
 
    while (bity > 0)
    {
        if (bity % 2 == 1)
        {
            wynik = (wynik * a) % mod;
        }
        bity = bity / 2;
        a = (a * a) % mod;
    }
 
    return wynik;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> a >> b >> k;
 
    for (int i = 0; i < k; i++)
    {
        char cc;
        cin >> cc;
        cc == '+' ? c.push_back(1) : c.push_back(-1);
    }
 
    long long q = potmod(a / b, k);
 
    q = ((potmod(b, k) * potmod(potmod(a, k), mod - 2)) % mod + mod) % mod;
 
    long long Z = 0;
 
    for (int i = 0; i < k; i++)
    {
        Z += c[i] * (potmod(a, n - i) * potmod(b, i)) % mod;
        Z = (Z + mod) % mod;
    }
 
    long long SUM = 0;
 
    if (q == 1ll)
        SUM = (((n + 1) / k) * Z) % mod;
    else
        SUM = ((((potmod(q, ((n + 1) / k)) - 1 + mod) % mod) * potmod(((q - 1 + mod) % mod), mod - 2)) % mod * Z) % mod;
 
    cout << SUM;
 
    return 0;
}