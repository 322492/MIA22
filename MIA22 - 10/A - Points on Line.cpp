#include <bits/stdc++.h>

using namespace std;

const int MAX = 100005;
int n, d, a;
long long res = 0, k;
vector<int> wej;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> d;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        wej.push_back(a);
    }

    if (wej.size() < 2)
    {
        cout << "0";
        return 0;
    }

    for (auto it = wej.begin() + 2; it != wej.end(); it++)
    {
        auto left = lower_bound(wej.begin(), it, *it - d);

        k = it - left;

        res += (k * (k - 1)) / 2;
    }

    cout << res;

    return 0;
}