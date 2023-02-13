#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n, v;
    cin >> n >> v;
 
    int w = min(n - 1, v);
    for (int i = 2; i <= n - v; i++)
        w += i;
 
    cout << w;
 
    return 0;
}