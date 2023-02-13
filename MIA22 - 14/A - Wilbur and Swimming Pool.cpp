#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

const int MAX = 10000;
pair<int, int> p[5] = {{MAX, MAX}}, ld, lu, rl, ru;
int Mx = -MAX, mx = MAX, My = -MAX, my = MAX;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;

    for (int i = 0; i < n; i++)
    {
        Mx = max(Mx, p[i].x);
        mx = min(mx, p[i].x);
        My = max(My, p[i].y);
        my = min(my, p[i].y);
    }

    int res = (Mx - mx) * (My - my);

    cout << (res == 0 ? -1 : res);

    return 0;
}