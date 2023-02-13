#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000;
int n, m, k, b;
long long wyn = 0ll;
int wej[MAX + 5];
vector<int> wek;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
        cin >> wej[i];

    for (int i = 1; i < n; i++)
        wek.push_back(wej[i] - wej[i - 1]);

    sort(wek.begin(), wek.end(), greater<int>());

    for (int i = k - 1; i < wek.size(); i++)
        wyn += wek[i];

    cout << wyn + k;

    return 0;
}