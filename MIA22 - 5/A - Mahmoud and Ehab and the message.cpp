#include <bits/stdc++.h>

using namespace std;

int n, k, m, ile, a;
const int MAX = 100005;
string slowa[MAX], s;
int koszt[MAX];
int opt[MAX];
vector<int> v;
map<string, int> M;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        M.insert({s, i});
    }
    for (int i = 1; i <= n; i++)
        cin >> koszt[i];

    for (int i = 0; i < k; i++)
    {
        cin >> ile;
        v.clear();
        for (int j = 0; j < ile; j++)
        {
            cin >> a;
            v.push_back(a);
        }
        int mn = koszt[v[0]];
        for (int j = 0; j < ile; j++)
            mn = min(mn, koszt[v[j]]);
        for (int j = 0; j < ile; j++)
            opt[v[j]] = mn;
    }

    long long w = 0ll;
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        auto p = M.find(s);
        w += opt[p->second];
    }

    cout << w;

    return 0;
}