#include <bits/stdc++.h>

using namespace std;

int n;
int p[1003];
bool b[1003];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> p[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            b[j] = false;

        int v = p[i];
        b[i] = true;
        while (!b[v])
        {
            b[v] = true;
            v = p[v];
        }

        cout << v << " ";
    }

    return 0;
}