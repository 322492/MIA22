#include <bits/stdc++.h>

using namespace std;

const int MAX = 200005, INF = INT_MAX;
int n, w;
int weja[MAX], wejb[MAX];
vector<int> s, wz; // słowo i szukany wzorzec
vector<int> x;

int ps[2 * MAX]; // tablica prefiksosufiksowa, ps[i] - maksymalna długość prefikso-sufiksu kończącego się na pozycji i
vector<int> wyn; // wektor wyniku, którym są kolejne indeksy słowa s, w których zaczyna się wzorzec (indeksy od 1)

void KMP() // funkcja prefikso-sufiksowa - zwraca wypełnioną tabelę ps[]
{
    ps[0] = 0;
    int t = 0;

    for (int i = 1; i < x.size(); i++)
    {
        while (t > 0 && x[i] != x[t])
            t = ps[t - 1];

        if (x[i] == x[t])
            t++;

        ps[i] = t;
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> w;

    for (int i = 0; i < n; i++)
        cin >> weja[i];
    for (int i = 0; i < w; i++)
        cin >> wejb[i];

    for (int i = 1; i < n; i++)
        s.push_back(weja[i] - weja[i - 1]);
    for (int i = 1; i < w; i++)
        wz.push_back(wejb[i] - wejb[i - 1]);

    x = wz;
    x.push_back(INF);
    x.insert(x.end(), s.begin(), s.end());
    KMP();

    int wyn = 0;

    for (int i = wz.size(); i < x.size(); i++) // odczytywanie odpowiedzi
        if (ps[i] == wz.size())
            wyn++;

    cout << wyn;

    return 0;
}