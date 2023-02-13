#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 1e6;
int n, k, chce, a, b, lg;
vector<int> tree[MAX + 6];
int depth[MAX + 6];
int ancestors[MAX + 6][21];
bool biore[MAX + 6];
 
void dfs(int v, int p)
{
    depth[v] = depth[p] + 1;
    ancestors[v][0] = p;
 
    for (int i = 1; i <= lg; i++)
        ancestors[v][i] = ancestors[ancestors[v][i - 1]][i - 1];
 
    for (auto u : tree[v])
    {
        if (u != p)
            dfs(u, v);
    }
    return;
}
 
int first_in(int v)
{
    while (true)
    {
        if (biore[v])
            return v;
        v = ancestors[v][0];
    }
}
 
int find_first_anc(int v)
{
    if (v == n)
        return n;
    for (int i = 0; i <= 20; i++)
    {
        if (biore[ancestors[v][i]] || ancestors[v][i] == 0)
            if (i == 0)
                return ancestors[v][i];
            else
                return find_first_anc(ancestors[v][i - 1]);
    }
    return n;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> k;
    chce = n - k;
    lg = ceil(log2(n));
 
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
 
    dfs(n, 0);
 
    biore[n] = 1;
    chce--;
 
    for (int i = n - 1; i >= 1; i--)
    {
        int v = find_first_anc(i);
        if (depth[i] - depth[v] <= chce)
        {
            int u = i;
            while (true)
            {
                if (biore[u])
                    break;
                biore[u] = true;
                chce--;
                u = ancestors[u][0];
            }
        }
    }
 
    for (int i = 1; i <= n; i++)
        if (!biore[i])
            cout << i << " ";
 
    return 0;
}