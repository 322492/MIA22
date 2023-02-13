#include <bits/stdc++.h>
 
using namespace std;
 
int n, m, a, b;
int v[1003];
vector<int> graf[1003];
bool usuniety[1003];
int wynik = 0;
 
int computeCost(int x)
{
    int w = 0;
    for (auto u : graf[x])
        if (!usuniety[u])
            w += v[u];
 
    return w;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> m;
 
    for (int i = 1; i <= n; i++)
        cin >> v[i];
 
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
 
    priority_queue<pair<int, int>> kol;
    for (int i = 1; i <= n; i++)
        kol.push({v[i], i});
 
    int wynik = 0;
    while (!kol.empty())
    {
        auto p = kol.top();
        kol.pop();
        int wierz = p.second;
        usuniety[wierz] = true;
 
        wynik += computeCost(wierz);
    }
 
    cout << wynik;
 
    return 0;
}