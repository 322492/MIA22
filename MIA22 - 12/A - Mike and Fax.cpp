#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    string s;
    cin >> s >> k;
    n = s.size();

    if (n % k != 0)
    {
        cout << "NO";
        return 0;
    }
    k = n / k;

    for (int i = 0; i < n; i += k)
    {
        for (int j = i, m = 1; j < i + k; j++, m++)
        {
            if (s[j] != s[i + k - m])
            {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";

    return 0;
}