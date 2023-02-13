#include <bits/stdc++.h>

using namespace std;

const int MAX = 100005;
int n, m, a, b, Res = 0;
vector<int> graf[MAX];
vector<int> rev[MAX];
bool coproc[MAX];
int res[MAX];
int wej[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> coproc[i];
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graf[b].push_back(a);
        rev[a].push_back(b);
        wej[a]++;
    }

    queue<int> kol;

    for (int i = 0; i < n; i++)
    {
        if (wej[i] == 0)
        {
            kol.push(i);
            res[i] = coproc[i];
        }
    }

    while (!kol.empty())
    {
        int v = kol.front();
        kol.pop();

        for (auto u : graf[v])
        {
            wej[u]--;
            if (wej[u] == 0)
            {
                for (auto z : rev[u])
                    if (coproc[u] && !coproc[z])
                        res[u] = max(res[u], res[z] + 1);
                    else
                        res[u] = max(res[u], res[z]);
                kol.push(u);
            }
        }
    }

    for (int i = 0; i < n; i++)
        Res = max(Res, res[i]);

    cout << Res;

    return 0;
}