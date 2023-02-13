#include <bits/stdc++.h>

using namespace std;

int n, roznych, wyn = 1000009, akt = 0;
string wej, junik;
map<char, int> M;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> wej;

    junik = wej;

    sort(junik.begin(), junik.end());
    junik.resize(unique(junik.begin(), junik.end()) - junik.begin()); // zwraca mi słowo różnych wartości bez powtórzeń posortowany rosnąco

    roznych = junik.size();

    for (char c : junik)
        M[c] = 0;

    int a = 0, b = 0;

    while (a <= b && b <= n)
    {
        if (akt < roznych)
        {
            if (b<n && M[wej[b]] == 0)
                akt++;
            M[wej[b]]++;
            b++;
        }
        else
        {
            wyn = min(wyn, b - a);
            if (M[wej[a]] == 1)
                akt--;
            M[wej[a]]--;
            a++;
        }
    }

    cout << wyn;

    return 0;
}