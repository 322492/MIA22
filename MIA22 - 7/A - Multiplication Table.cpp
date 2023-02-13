#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n, x;
    cin >> n >> x;
 
    int res = 0;
 
    for (int i = 1; i * i <= x && i <= n; i++)
        if (x % i == 0 && x / i <= n)
        {
            res += 2;
            if (i * i == x)
                res--;
        }
 
    cout << res;
 
    return 0;
}