#include <bits/stdc++.h>
 
using namespace std;
 
int n;
int wej[2003], diffs[5005];
long double prob[5005];
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> wej[i];
 
    sort(wej, wej + n);
 
    int a = n * (n - 1) / 2;
 
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            diffs[abs(wej[j] - wej[i])]++;
 
    long double res = 0;
 
    for (int i = 1; i <= 5000; i++)
    {
        for (int j = 1; j <= 5000; j++)
        {
            if (i + j <= 5000)
                prob[i + j] += (long double)diffs[i] / (long double)a * (long double)diffs[j] / (long double)a;
 
            if (j > i)
                res += (long double)prob[i] * (long double)diffs[j] / (long double)a;
        }
    }
 
    cout << setprecision(10) << res;
 
    return 0;
}