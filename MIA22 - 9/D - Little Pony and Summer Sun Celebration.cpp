#include <bits/stdc++.h>

using namespace std;

const int MAX = 100005;
int n, m, a, b;
vector<int> graf[MAX];
vector<int> res;
bool cel[MAX], ile[MAX], vis[MAX];

void PUSH(int x)
{
    res.push_back(x);
    ile[x] = !ile[x];
    return;
}

void dfs(int v, int p)
{
    vis[v] = true;
    PUSH(v);

    for (auto u : graf[v])
    {
        if (!vis[u])
        {
            dfs(u, v);
            PUSH(v);
            if (cel[u] != ile[u])
            {
                PUSH(u);
                PUSH(v);
            }
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        cin >> cel[i];

    for (int i = 1; i <= n; i++)
        if (cel[i] != ile[i])
        {
            dfs(i, -1);
            if (cel[i] != ile[i])
                res.pop_back();
            break;
        }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && cel[i])
        {
            cout << "-1";
            return 0;
        }
    }

    cout << res.size() << "\n";
    for (auto a : res)
        cout << a << " ";

    return 0;
}