#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 100005;
int wej[MAX];
bool czy[MAX];
int sumy[MAX];
int n, k, res = 0;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> wej[i];
 
    for (int i = 1; i <= n; i++)
    {
        cin >> czy[i];
        sumy[i] = sumy[i - 1];
        if (czy[i])
            sumy[i] += wej[i];
        wej[i] += wej[i - 1];
    }
 
    for (int i = 1; i <= n - k + 1; i++)
    {
        int tmp = wej[i + k - 1] - wej[i - 1] + sumy[i - 1] + sumy[n] - sumy[i + k - 1];
        res = max(res, tmp);
    }
 
    cout << res;
 
    return 0;
}