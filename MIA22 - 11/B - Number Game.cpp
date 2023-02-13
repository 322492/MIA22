#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

bool f(int x)
{
    if (__builtin_popcount(x) == 1 && x != 2)
        return true;
    if (x % 2 == 0 && x / 2 >= 3 && isPrime(x / 2))
        return true;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, x;
    cin >> t;

    while (t--)
    {
        cin >> x;
        if (f(x))
            cout << "FastestFinger\n";
        else
            cout << "Ashishgup\n";
    }

    return 0;
}