#include <bits/stdc++.h>

using namespace std;

const int MAX = 100005;
int m;
long long n, tab[MAX], sums[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        for (int i = 1; i <= m; i++)
            cin >> tab[i];

        sort(tab + 1, tab + 1+m);

        sums[1] = tab[1];
        for (int i = 2; i <= m; i++)
            sums[i] = sums[i - 1] + tab[i];

        int res = 0;

        if (sums[m] < n)
        {
            cout << "-1\n";
            continue;
        }

        for (int i = m; i > 0; i--)
        {
            if (tab[i] <= n)
            {
                n -= tab[i];
                continue;
            }

            // tab[i] > n then
            while (sums[i - 1] < n) // muszę dzielić
            {
                tab[i] /= 2;
                if (tab[i] <= n)
                {
                    n -= tab[i];
                }
                res++;
            }

            // sums[i] >= n  --> pomijam
        }

        cout << res << "\n";
    }

    return 0;
}