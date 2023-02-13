#include <bits/stdc++.h>

using namespace std;

const int MAX = 1 << 19;
int n, a, l, r, x, q, c, i, y;
int tree[2 * MAX];

void update(int i, int x)
{
    i += MAX;
    tree[i] = x;
    i /= 2;

    while (i > 0)
    {
        tree[i] = __gcd(tree[i * 2], tree[2 * i + 1]);
        i /= 2;
    }

    return;
}

int query(int a, int b, int x, int np, int L, int P)
// a-poczatek przedziału, który mnie interesuje, b-jego koniec, x-wartość oczekiwana gcd, np-numer komórki drzewa, w której jestem, L-poczatek poddrzewa komórki, P-koniec przedziału tego poddrzewa
{
    if (L > b || P < a) // rozpatrywany przedział (L-P) jest poza przedziałym bazowym (a-b), po za tym który nas interesuje
        return 0;

    if (L >= a && P <= b) // rozpatrywany przedział jest w całości w przedziale bazowym
    {
        if (tree[np] % x == 0)
            return 0;
        else
        {
            while (np < MAX)
            {
                if (tree[2 * np] % x != 0)
                {
                    if (tree[2 * np + 1] % x != 0)
                    {
                        return 2;
                    }
                    np *= 2;
                }
                else
                {
                    np = 2 * np + 1;
                }
            }
            return 1;
        }
    }

    int ile = 0;

    ile += query(a, b, x, np * 2, L, (L + P) / 2);
    if (ile > 1)
        return ile;
    ile += query(a, b, x, np * 2 + 1, (L + P) / 2 + 1, P);
    return ile;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        update(i, a);
    }

    cin >> q;

    while (q--)
    {
        cin >> c;

        if (c == 1)
        {
            cin >> l >> r >> x;
            int wyn = query(l + MAX, r + MAX, x, 1, MAX, 2 * MAX - 1);
            wyn <= 1 ? cout << "YES\n" : cout << "NO\n";
        }
        else
        {
            cin >> i >> y;
            update(i, y);
        }
    }

    return 0;
}