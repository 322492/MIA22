#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second

int n, c, x, y, np = 1;
pair<int, int> tab[102];
vector<int> graf[102];
bool vis[102];

void wstaw(int x, int y)
{
    tab[np].f = x;
    tab[np].s = y;

    for (int i = 1; i < np; i++)
    {
        if ((x < tab[i].f && tab[i].f < y) || (x < tab[i].s && tab[i].s < y))
            graf[i].push_back(np);
        if ((tab[i].f < x && x < tab[i].s) || (tab[i].f < y && y < tab[i].s))
            graf[np].push_back(i);
    }
    return;
}

void dfs(int v)
{
    vis[v] = true;

    for (auto u : graf[v])
    {
        if (!vis[u])
            dfs(u);
    }
}

bool find(int x, int y)
{

    for (int i = 1; i < np; i++)
        vis[i] = false;

    dfs(x);

    return vis[y];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> c >> x >> y;

        if (c == 1)
        {
            wstaw(x, y);
            np++;
        }
        if (c == 2)
        {
            if (find(x, y))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}