#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;
int n, m, a, b, v, ile_kraw = 0;
queue<int> Q; // kolejka pomocnicza do łączenia wierzchołków o stopniu nieparzystym
unordered_multiset<int> graf[MAX];
vector<int> cykl; // tworzony cykl Eulera
stack<int> S; // stos pomocniczy do tworzenia cyklu Eulera

void find_cycle()
{
    while (!S.empty())
    {
        v = S.top();

        if (graf[v].size() == 0)
        {
            cykl.push_back(v);
            S.pop();
        }
        else
        {
            int w = *graf[v].begin();
            graf[v].erase(graf[v].begin());
            graf[w].erase(graf[w].find(v));

            S.push(w);
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
        graf[a].insert(b);
        graf[b].insert(a);
        ile_kraw++;
    }

    //dodawanie krawędzi między wierzchołkami o nieparzystym stopniu
    for (int i = 1; i <= n; i++)
        if (graf[i].size() % 2)
        {
            if (!Q.empty())
            {
                a = Q.front();
                Q.pop();
                b = i;
                graf[a].insert(b);
                graf[b].insert(a);
                ile_kraw++;
            }
            else
                Q.push(i);
        }

    // dodanie ewentualnej pętelki, aby cykl Eulera miał parzystą długość
    if (ile_kraw % 2)
    {
        graf[1].insert(1);
        graf[1].insert(1);
        ile_kraw++;
    }

    S.push(1);
    find_cycle();

    cout << cykl.size() - 1 << "\n";

    bool z = 1;
    for (int i = 0; i < cykl.size() - 1; i++)
    {
        if (z)
            cout << cykl[i] << " " << cykl[i + 1] << "\n";
        else
            cout << cykl[i + 1] << " " << cykl[i] << "\n";

        z = !z;
    }

    return 0;
}