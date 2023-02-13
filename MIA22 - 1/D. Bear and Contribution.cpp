#include <bits/stdc++.h>

using namespace std;

const int MAX = 200005;
const long long INF = 1e18;
long long res = INF;
long long n, k, b, c;
long long wej[MAX];

long long calc(int r)
{
    long long x = INF + r;   // do tej wartosci wyrownuje
    long long wyn = INF + r; // najmniejszy wynik dotychczas
    long long w = 0ll;       // aktualny wynik, kandydat na najlepszego
    priority_queue<long long> Q;

    for (int i = 0; i < k; i++)
    {
        long long q = (x - wej[i]) / 5 * b + (x - wej[i]) % 5 * c;
        Q.push(q);
        w += q;
    }
    wyn = w - (x - wej[k - 1]) / 5 * b * k;

    for (int i = k; i < n; i++)
    {
        long long q = (x - wej[i]) / 5 * b + (x - wej[i]) % 5 * c;
        w += q;
        Q.push(q);
        w -= Q.top();
        Q.pop();
        wyn = min(wyn, w - (x - wej[i]) / 5 * b * k);
    }

    return wyn;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> b >> c;

    for (int i = 0; i < n; i++)
        cin >> wej[i];

    b = min(b, 5 * c);
    sort(wej, wej + n);

    for (int r = 0; r < 5; r++)
        res = min(res, calc(r));

    cout << res;

    return 0;
}