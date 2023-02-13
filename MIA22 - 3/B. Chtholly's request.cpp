#include <bits/stdc++.h>
 
using namespace std;
 
int p, n = 1;
string s, rs;
long long k, res = 0;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> p >> k;
 
    for (int i = 1; i <= p; i++)
    {
        s = to_string(n);
        rs = s;
        reverse(rs.begin(), rs.end());
        s += rs;
        res = (stoll(s) % k + res) % k;
        n++;
    }
 
    cout << res;
 
    return 0;
}