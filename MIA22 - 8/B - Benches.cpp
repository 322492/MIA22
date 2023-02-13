#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
 
    long long res = n;
 
    for (int i = 1; i <= 4; i++)
        res *= (n - i);
 
    res /= 120;
 
    for (int i = 0; i <= 4; i++)
        res *= (n - i);
 
    cout << res;
 
    return 0;
}