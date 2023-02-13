#include <bits/stdc++.h>
#include <numeric>
 
using namespace std;
 
int n;
 
int LCM(long long x, long long y)
{
    return x * y / __gcd(x, y);
}
 
bool check()
{
    vector<int> tab;
    int a, bfst, bsnd;
    tab.push_back(1);
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        tab.push_back(a);
    }
    tab.push_back(1);
 
    bfst = LCM(tab[0], tab[1]);
 
    for (int i = 2; i <= n + 1; i++)
    {
        bsnd = LCM(tab[i - 1], tab[i]);
        if (tab[i - 1] != __gcd(bfst, bsnd))
            return false;
 
        bfst = bsnd;
    }
    return true;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t;
    cin >> t;
 
    while (t--)
    {
        cin >> n;
        if (check())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
 
    return 0;
}