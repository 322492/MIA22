#include <bits/stdc++.h>
 
using namespace std;
 
int n, q, t, x, poz1 = 0, poz2 = 1;
int res[1000006];
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> q;
 
    for (int i = 1; i <= q; i++)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> x;
            if (x < 0)
                x += n;
            poz1 += x;
            poz2 += x;
            poz1 = poz1 % n;
            poz2 = poz2 % n;
        }
        if (t == 2)
        {
            if (poz1 % 2 == 0)
                poz1++;
            else
                poz1--;
            if (poz2 % 2 == 0)
                poz2++;
            else
                poz2--;
        }
    }
 
    for (int i = 1, j = 2, poz = poz1, pozz = poz2; i < n, j <= n, poz < poz1 + n, pozz < poz2 + n; poz += 2, pozz += 2, j += 2, i += 2)
    {
        res[poz % n] = i;
        res[pozz % n] = j;
    }
 
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
 
    return 0;
}