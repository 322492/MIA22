#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 8 * 100000 + 5;
int n, q, co, k, l, r, w;
map<int, int> M;  // mapa wysokosc -> pozycja (id)
int tab[MAX];     // union find
int wej[MAX];     // wysokości
int current[MAX]; // current[i] = obecny numer wierzchołka i
 
int Find(int x)
{
    if (tab[x] != x)
        tab[x] = Find(tab[x]);
 
    return tab[x];
}
 
void insert(int i)
{
    if (M.count(wej[i]))
        tab[i] = Find(M[wej[i]]);
    else
        M.insert({wej[i], i});
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n;
 
    for (int i = 1; i <= n; i++)
    {
        cin >> wej[i];
        tab[i] = i;
        current[i] = i;
 
        insert(i);
    }
 
    cin >> q;
    while (q--)
    {
        cin >> co;
        if (co == 1)
        {
            cin >> k >> w;
            int newid = ++n;
            current[k] = newid;
            tab[newid] = newid;
            wej[newid] = w;
            insert(newid);
        }
        if (co == 2)
        {
            cin >> k;
            cout << wej[Find(current[k])] << "\n";
        }
        if (co == 3)
        {
            cin >> l >> r;
 
            for (auto it = M.lower_bound(l); it != M.upper_bound(r); it++)
            {
                int key = it->first;    // wysokość
                int value = it->second; // pozycja
                if (key <= (l + r) / 2) // równam w dół
                    wej[value] = l - 1;
                else
                    wej[value] = r + 1;
 
                insert(value);
            }
        }
    }
 
    return 0;
}
