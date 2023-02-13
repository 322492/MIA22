#include <bits/stdc++.h>

using namespace std;

struct UF
{
    int parent;   // ojciec
    long long sz; // rozmiar
};
int n, m, a, b;
const int MAX = 150003;
UF tab[MAX];
long long edges[MAX], C_edges[MAX]; // ile krawędzi wychodzi z wierzchołka i oraz ile krawędzi jest w podgrafie o ojcu i

void init()
{
    for (int i = 1; i <= n; i++)
    {
        tab[i].parent = i; // uznajemy, że korzeń jest swoim własnym ojcem
        tab[i].sz = 1ll;   // rozmiar każdej składowej to 1
    }
}

int Find(int x)
{
    if (tab[x].parent != x)
        tab[x].parent = Find(tab[x].parent);

    return tab[x].parent;
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x == y)
        return;
    if (tab[x].sz < tab[y].sz)
        swap(x, y);
    tab[y].parent = x;
    tab[x].sz += tab[y].sz;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    init();

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        edges[a]++;
        edges[b]++;
        Union(a, b);
    }

    for (int i = 1; i <= n; i++)
    {
        int pp = Find(i);
        C_edges[pp] += edges[i];
    }

    for (int i = 1; i <= n; i++)
    {
        int pp = Find(i);
        long long sizz = tab[pp].sz;
        if (C_edges[pp] != sizz * (sizz - 1))
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}