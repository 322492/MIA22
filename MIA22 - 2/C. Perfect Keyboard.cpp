#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> graf[30];
bool vis[30];
bool bylo[30];
 
string addd(int i, string s)
{
    s += (char)(i + 'a');
    bylo[i] = 1;
    for (auto u : graf[i])
        if (!bylo[u])
            s = addd(u, s);
 
    return s;
}
 
void printans()
{
    string w = "";
    for (int i = 0; i <= 25; i++)
    {
        if (graf[i].size() == 1 && bylo[i] == 0)
            w = addd(i, w);
    }
    for (int i = 0; i <= 25; i++)
    {
        if (bylo[i] == 0)
            w += (char)(i + 'a');
    }
    cout << w << "\n";
}
 
bool dfs(int v, int p)
{
    vis[v] = 1;
    for (auto u : graf[v])
    {
        if (u != p)
        {
            if (vis[u] == 1)
                return true;
            else
                dfs(u, v);
        }
    }
    return false;
}
 
bool iscycle()
{
    for (int i = 0; i <= 25; i++)
        if (vis[i] == 0 && dfs(i, -1))
            return true;
 
    return false;
}
 
bool another()
{
    for (int i = 0; i <= 25; i++)
    {
        if (graf[i].size() > 2)
            return true;
    }
    return false;
}
 
void solve(string s)
{
    for (int i = 0; i < s.size() - 1; i++)
    {
        graf[s[i] - 'a'].push_back(s[i + 1] - 'a');
        graf[s[i + 1] - 'a'].push_back(s[i] - 'a');
    }
    for (int i = 0; i <= 25; i++)
    {
        sort(graf[i].begin(), graf[i].end());
        graf[i].resize(unique(graf[i].begin(), graf[i].end()) - graf[i].begin()); // funckje zwracają mi wektor wartości bez powtórzeń posortowany rosnąco
    }
    if (iscycle() || another())
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        printans();
    }
    return;
}
 
void clean()
{
    for (int i = 0; i <= 26; i++)
    {
        graf[i].clear();
        vis[i] = 0;
        bylo[i] = 0;
    }
 
    return;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int T;
    string s;
    cin >> T;
    while (T--)
    {
        cin >> s;
        solve(s);
        clean();
    }
 
    return 0;
}