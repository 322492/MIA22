#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 1; i <= n / 2 - 1; i++)
            cout << 2 * i << " " << 2 * i - 1 << " ";
        if (n % 2)
            cout << n << " " << n - 2 << " " << n - 1;
        else
            cout << n << " " << n - 1;
        cout << "\n";
    }

    return 0;
}