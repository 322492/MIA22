#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 505;
int n, m;
int a[MAX][MAX], b[MAX][MAX];
 
bool check()
{
 
    for (int i = 0; i < n; i++)
    {
        int wiersz = i;
        int kolumna = 0;
        vector<int> A, B;
        while (wiersz >= 0 && kolumna < m)
        {
            A.push_back(a[wiersz][kolumna]);
            B.push_back(b[wiersz][kolumna]);
            wiersz--;
            kolumna++;
        }
 
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
 
        if (A != B)
            return false;
    }
 
    for (int j = 1; j < m; j++)
    {
        int wiersz = n - 1;
        int kolumna = j;
 
        vector<int> A, B;
        while (wiersz >= 0 && kolumna < m)
        {
            A.push_back(a[wiersz][kolumna]);
            B.push_back(b[wiersz][kolumna]);
            wiersz--;
            kolumna++;
        }
 
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
 
        if (A != B)
            return false;
    }
 
    return true;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> m;
 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> b[i][j];
 
    if (check())
        cout << "YES";
    else
        cout << "NO";
 
    return 0;
}