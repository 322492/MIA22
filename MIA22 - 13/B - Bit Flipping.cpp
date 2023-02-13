#include <bits/stdc++.h>

using namespace std;

const int MAX = 200005;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, x, k;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> s;
        int tab[MAX] = {0};
        if (k % 2 == 1)
        {
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '0')
                    s[i] = '1';
                else
                    s[i] = '0';
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0' && k > 0)
            {
                s[i] = '1';
                k--;
                tab[i]++;
            }
        }
        if (k > 0)
        {
            tab[n - 1] += k;
            if (k % 2 == 1)
                s[n - 1] = '0';
        }
        cout << s << "\n";
        for (int i = 0; i < n; i++)
            cout << tab[i] << " ";
        cout << "\n";
    }

    return 0;
}