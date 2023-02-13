#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

struct UF
{
    int parent; // ojciec
    int sz;     // rozmiar
    list<int> LL;
};
UF tab[150003];
int n, a, b;

void init()
{
    for (int i = 1; i <= n; i++)
    {
        tab[i].parent = i; // uznajemy, że korzeń jest swoim własnym ojcem
        tab[i].sz = 1;     // rozmiar każdej składowej to 1
        tab[i].LL = {i};
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
    tab[x].LL.splice(tab[x].LL.end(), tab[y].LL);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    init();

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        Union(a, b);
    }

    for (int i = 1; i <= n; i++)
        if (tab[i].LL.size() == n)
        {
            for (auto x : tab[i].LL)
                cout << x << " ";
            
            break;
        }

    return 0;
}