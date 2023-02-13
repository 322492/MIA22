#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 300'005;
int n, m; // liczba wierzcholkow i krawedzi w grafie
vector<int> topsort;
vector<int> graf[MAX];  // graf
vector<int> rgraf[MAX]; // odwrócony graf
int tab[MAX][27]; // tab[i][j] - maksymalna liczba wystąpień litery (o indeksie) j podczas rozpatrywania wierzchołka i
int ile[MAX]; //liczba wejścia wierzchołka
string s;
int a, b, res = 0;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> m >> s;
    s = ' ' + s;
 
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graf[a].push_back(b);
        rgraf[b].push_back(a);
        ile[b]++;
    }
 
    for (int i = 1; i <= n; i++)
    {
        if (ile[i] == 0)
            topsort.push_back(i);
    }
 
    for (int i = 0; i < n; i++)
    {
        if (topsort.size() <= i)
        {
            cout << -1;
            return 0;
        }
        a = topsort[i];
        for (auto x : graf[a])
        {
            ile[x]--;
            if (ile[x] == 0)
                topsort.push_back(x);
        }
        for (auto y : rgraf[a])
        {
            for (int k = 0; k <= 26; k++)
            {
                tab[a][k] = max(tab[a][k], tab[y][k]);
                res = max(res, tab[a][k]);
            }
        }
        tab[a][s[a] - 'a']++;
        res = max(res, tab[a][s[a] - 'a']);
    }
 
    cout << res;
    return 0;
}