#include <bits/stdc++.h>

using namespace std;

string s;
int tab[30];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;

    for (int i = 0; i < s.size(); i++)
        tab[s[i] - 'a']++;

    int ile = 0;

    for (int i = 0; i <= 26; i++)
        ile += (tab[i] % 2);

    if (ile == 0 || (ile - 1) % 2 == 0)
        cout << "First";
    else
        cout << "Second";

    return 0;
}