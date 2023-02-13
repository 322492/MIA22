#include <bits/stdc++.h>
 
using namespace std;
 
int n, a[502];
 
bool check(int x)
{
    if (x == 0)
        return true;
    for (int i = 0; i < n; i++)
        if (x * ceil((float)a[i] / (float)(x + 1)) > a[i])
            return false;
    
    return true;
}
 
long long count(int x)
{
    long long wyn = 0ll;
    for (int i = 0; i < n; i++)
        wyn += (long long)ceil((float)((float)a[i] / (float)(x + 1)));
    
    return wyn;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
 
    sort(a, a + n);
 
    int X = sqrt(a[0]);
    for (int x = 1; x <= sqrt(a[0]); x++)
    {
        if (check(a[0] / x))
            X = max(X, a[0] / x);
 
        if (check(a[0] / x - 1))
            X = max(X, a[0] / x - 1);
    }
 
    cout << count(X);
 
    return 0;
}