#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define M_PI 3.14159265358979323846

const int MAX = 100004, LG = 20, BZ = 1 << 19;
int n, b;
long long a, aktmax, r, h;
vector<pair<long long, int>> vols; //<volume, -position>
long long dp[1 << LG];

long long query(int a, int b)
{
    a += BZ;
    b += BZ;
    long long res = max(dp[a], dp[b]);

    while (a / 2 != b / 2)
    {
        if (a % 2 == 0)
            res = max(res, dp[a + 1]);
        if (b % 2 == 1)
            res = max(res, dp[b - 1]);

        a /= 2;
        b /= 2;
    }

    return res;
}

void update(int i, long long x)
{
    i += BZ;
    dp[i] = x;
    i /= 2;

    while (i > 0)
    {
        dp[i] = max(dp[i * 2], dp[i * 2 + 1]);
        i /= 2;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> r >> h;
        vols.push_back({r * r * h, -(i + 1)});
    }

    sort(vols.begin(), vols.end());

    for (int i = 0; i < n; i++)
    {
        a = vols[i].f;
        b = -vols[i].s;

        aktmax = query(1, b);
        update(b, a + aktmax);
    }

    cout << setprecision(10) << M_PI * query(1, n);

    return 0;
}