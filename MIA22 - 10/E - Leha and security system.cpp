#include <bits/stdc++.h>

using namespace std;

int n, l, r, x, y, q, c;
const int MAX = (1 << 17), ten = 10;
long long sum[2 * MAX][ten]; // sum[np][i] - ile wnosi cyfra i do sumy w weźle np
// przykładowo w liściu a, w którym jest liczba 827 niezerowe pola sum to: sum[a][8] = 100, sum[a][2] = 10, sum[a][7] = 1
int nxt[2 * MAX][ten];    // nxt[np][i] - jaką cyfrą jest zastąpiona cyfra i w podrzewie węzła np
int wej[MAX][ten];        // wejście przygotowane tak jak tabela sum
int aux1[ten], aux2[ten]; // tablice pomocnicze do propagacji
long long aux3[ten];      // jak wyżej
int tens[ten] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

void init_trees() // inicjalizacja drzew sum i nxt odpowiednimi wartościami
{
    for (int j = 0; j < 10; j++) // numeruje od zera i to się nie uzupełniło w main'ie
        nxt[MAX][j] = j;         // na początku cyfry są niezmienione

    for (int i = MAX - 1; i >= 1; i--)
    {
        for (int j = 0; j < 10; j++)
            nxt[i][j] = j; // na początku cyfry są niezmienione

        for (int j = 0; j < 10; j++)
            sum[i][j] = sum[i * 2][j] + sum[i * 2 + 1][j];
    }
}

void prop(int np)
{
    if (np < MAX) // jeśli można to zepchnięcie informacji w dół
    {
        for (int i = 0; i < 10; i++)
        {
            aux1[i] = nxt[np][nxt[2 * np][i]];
            aux2[i] = nxt[np][nxt[2 * np + 1][i]];
        }
        for (int i = 0; i < 10; i++)
        {
            nxt[2 * np][i] = aux1[i];
            nxt[2 * np + 1][i] = aux2[i];
        }
    }

    for (int i = 0; i < 10; i++) // wyczyszczenie tablicy
        aux3[i] = 0;

    for (int i = 0; i < 10; i++)
        aux3[nxt[np][i]] += sum[np][i];

    for (int i = 0; i < 10; i++)
    {
        sum[np][i] = aux3[i];
        nxt[np][i] = i; // wszystko aktualne
    }

    return;
}

void update(int a, int b, int x, int y, int np, int L, int P)
// a-poczatek przedziału, który mnie interesuje, b-jego koniec, x-wartość, którą zmieniam, y-wartość, na którą zamieniam,
// np-numer komórki drzewa, w której jest, L-poczatek poddrzewa komórki, P-koniec przedziału tego poddrzewa
{
    prop(np);

    if (L > b || P < a) // rozpatrywany przedział (L-P) jest poza przedziałym bazowym (a-b), po za tym który nas interesuje
        return;

    if (L >= a && P <= b) // rozpatrywany przedział jest w całości w przedziale bazowym
    {
        nxt[np][x] = y; // zmiana i zepchnięcie w dół
        prop(np);
        return;
    }

    // jeśli przedział bazowy jest tylko w części w rozpatrywanym przedziale to dzielę ten przedział dalej

    update(a, b, x, y, np * 2, L, (L + P) / 2);
    update(a, b, x, y, np * 2 + 1, (L + P) / 2 + 1, P);

    for (int i = 0; i < 10; i++) // aktualizacja drzewa sum, gdy jego dzieci są już aktualne
        sum[np][i] = sum[2 * np][i] + sum[2 * np + 1][i];

    return;
}

long long query(int a, int b, int np, int L, int P)
{
    prop(np);

    if (L > b || P < a) // rozpatrywany przedział (L-P) jest poza przedziałym bazowym (a-b), po za tym który nas interesuje
        return 0;

    if (L >= a && P <= b) // rozpatrywany przedział jest w całości w przedziale bazowym
    {
        long long res = 0ll;
        for (int i = 1; i < 10; i++)
            res += (long long)i * (long long)sum[np][i];

        return res;
    }

    return (query(a, b, np * 2, L, (L + P) / 2) + query(a, b, np * 2 + 1, (L + P) / 2 + 1, P));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        cin >> x;

        for (int j = 0; j < 9; j++)
        {
            wej[i][x % 10] += tens[j];
            x /= 10;
            if (x == 0)
                break;
        }

        for (int j = 0; j < 10; j++)
        {
            sum[i + MAX][j] = wej[i][j];
            nxt[i + MAX][j] = j; // na początku cyfry są niezmienione
        }
    }

    init_trees();

    while (q--)
    {
        cin >> c;

        if (c == 1)
        {
            cin >> l >> r >> x >> y;
            update(l + MAX, r + MAX, x, y, 1, MAX, 2 * MAX - 1);
        }
        else
        {
            cin >> l >> r;
            cout << query(l + MAX, r + MAX, 1, MAX, 2 * MAX - 1) << "\n";
        }
    }
    return 0;
}