#include <bits/stdc++.h>

using namespace std;

const int MAX = 1 << 20;
int n, m, t, x, y, k, np = 1;
vector<pair<int, int>> queries;
int tree[2 * MAX];
int a[MAX], b[MAX];

void update(int p, int k, int x)
{
    p += MAX;
    k += MAX;

    tree[p] = x;
    tree[k] = x;

    while (k / 2 != p / 2)
    {
        if (p % 2 == 0)
            tree[p + 1] = x;
        if (k % 2 == 1)
            tree[k - 1] = x;
        p /= 2;
        k /= 2;
    }
    return;
}

int query(int x)
{
    int res = 0;
    x += MAX;

    res = tree[x];
    x /= 2;

    while (x > 0)
    {
        res = max(res, tree[x]);
        x /= 2;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    for (int i = 0; i < m; i++)
    {
        cin >> t;

        if (t == 1)
        {
            cin >> x >> y >> k;
            queries.push_back({x, y});
            update(y, y + k - 1, np);
            np++;
        }
        if (t == 2)
        {
            cin >> x;
            k = query(x);
            k--;

            if (k == -1) // nie zaszły żadne zmiany
                cout << b[x] << '\n';
            else
            {
                int tmp = x - queries[k].second;
                cout << a[queries[k].first + tmp] << "\n";
            }
        }
    }

    return 0;
}