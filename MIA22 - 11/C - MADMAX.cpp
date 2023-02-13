#include <bits/stdc++.h>

using namespace std;

const int MAX = 102;
int n, m, a, b;
char c;
vector<pair<int, char>> graf[MAX];
map<pair<int, int>, char> M;
int dp[MAX][MAX][27][2]; // dp[v][u][c][g] = czy Max moze wygrać będąc w wierzchołku v, gdy Lucas jest w wierzchołku u,
                         // mają do dyspozycji litery powyżej c i teraz jest ruch gracza g (g=1=Max, g=0=Lucas)

int dfs(int u, int v, char c, bool kto) // kto = 1 = Max, kto = 0 = Lucas
{
    int &res = dp[u][v][c - 'a'][kto];

    if (res != -1)
        return res;

    res = !kto;
    if (kto)
    {
        for (auto ppp : graf[u])
            if (ppp.second >= c)
                res |= dfs(ppp.first, v, ppp.second, !kto);
    }
    else
    {
        for (auto ppp : graf[v])
            if (ppp.second >= c)
                if (!dfs(u, ppp.first, ppp.second, !kto))
                    res = 0;
    }

    dp[u][v][c - 'a'][kto] = res;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        graf[a].push_back({b, c});
    }

    fill_n(&dp[0][0][0][0], MAX * MAX * 27 * 2, -1);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dfs(i, j, 'a', 1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << (dp[i][j][0][1] ? "A" : "B");

        cout << '\n';
    }

    return 0;
}