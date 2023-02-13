#include <bits/stdc++.h>
 
using namespace std;
 
int r, c, n, k, x, y, res = 0;
bool tab[11][11];
 
bool check(int a, int b, int c, int d)
{
    if ((c - a + 1) * (d - b + 1) < k)
        return false;
    int jest = 0;
    for (int i = a; i <= c; i++)
        for (int j = b; j <= d; j++)
            jest += tab[i][j];
 
    return jest >= k;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> r >> c >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        tab[x][y] = true;
    }
 
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            for (int ii = i; ii <= r; ii++)
                for (int jj = j; jj <= c; jj++)
                    if (check(i, j, ii, jj))
                        res++;
 
    cout << res;
 
    return 0;
}