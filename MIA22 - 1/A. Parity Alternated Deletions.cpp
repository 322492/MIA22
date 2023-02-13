#include <bits/stdc++.h>

using namespace std;

vector<int> p, np;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a % 2 == 0)
            p.push_back(-a);
        else
            np.push_back(-a);
    }

    sort(p.begin(), p.end());
    sort(np.begin(), np.end());

    int par = p.size();
    int npar = np.size();

    if (abs(npar - par) <= 1)
    {
        cout << "0";
        return 0;
    }

    int wyn = 0;
    if (npar > par)
    {
        for (int i = np.size() - 1; i > par; i--)
        {
            wyn += np[i];
        }
    }
    else
    {
        for (int i = p.size() - 1; i > npar; i--)
        {
            wyn += p[i];
        }
    }

    cout << -wyn;

    return 0;
}