#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, x;
    cin >> t;
    while (t--)
    {
        cin >> n;
        long long w = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            w = w | x;
        }
        cout << w << "\n";
    }

    return 0;
}