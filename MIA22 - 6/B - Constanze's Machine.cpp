#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 100005;
const int mod = 1000000007;
long long nfib[MAX];
string s;
 
void prep(int n)
{
    nfib[0] = nfib[1] = 1;
    nfib[2] = 2;
 
    for (int i = 3; i <= n; i++)
        nfib[i] = (nfib[i - 1] + nfib[i - 2]) % mod;
 
    return;
}
 
long long solve()
{
    long long res = 1ll;
    int length = 1;
 
    if (s[0] == 'm' || s[0] == 'w')
        return 0ll;
    
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == 'm' || s[i] == 'w')
            return 0ll;
        
        if (s[i] == 'n' && s[i - 1] == 'n')
            length++;
        
        else if (s[i] == 'u' && s[i - 1] == 'u')
            length++;
        
        else
        {
            res = (res * nfib[length]) % mod;
            length = 1;
        }
    }
    return res;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> s;
    s += "#";
    prep(s.size());
    cout << solve();
 
    return 0;
}