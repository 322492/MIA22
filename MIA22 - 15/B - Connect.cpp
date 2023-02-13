#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second

const int MAX = 55, INF = 1e9;

int n, r1, c1, r2, c2;
char wej[MAX][MAX];
int vis[MAX][MAX];

void proc(int x, int y, int prt);
void dfs(int x, int y, int prt);

int dist(pair<int, int> A, pair<int, int> B)
{
    return (A.f - B.f) * (A.f - B.f) + (A.s - B.s) * (A.s - B.s);
}

void proc(int x, int y, int prt)
{
    if (x < 1 || x > n || y < 1 || y > n)
        return;

    if (vis[x][y] == prt)
        return;

    if (wej[x][y] == '0')
        dfs(x, y, prt);
    return;
}

void dfs(int x, int y, int prt)
{
    vis[x][y] = prt;

    proc(x - 1, y, prt);
    proc(x + 1, y, prt);
    proc(x, y - 1, prt);
    proc(x, y + 1, prt);

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> r1 >> c1 >> r2 >> c2;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> wej[i][j];

    dfs(r1, c1, 1);
    dfs(r2, c2, 2);

    int res = INF;

    if (vis[r1][c1] == 2)
    {
        cout << "0";
        return 0;
    }

    for (int a = 1; a <= n; a++)
        for (int b = 1; b <= n; b++)
            for (int c = 1; c <= n; c++)
                for (int d = 1; d <= n; d++)
                    if (vis[a][b] == 1 && vis[c][d] == 2)
                        res = min(res, dist({a, b}, {c, d}));

    cout << res;

    return 0;
}