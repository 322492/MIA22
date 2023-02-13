#include <bits/stdc++.h>

using namespace std;

struct rect
{
    long long x1, y1, x2, y2;
};

long long area(rect a)
{
    return (a.x2 - a.x1) * (a.y2 - a.y1);
}

rect inter(rect a, rect b)
{
    rect res;

    res.x1 = max(a.x1, b.x1);
    res.x2 = min(a.x2, b.x2);

    res.y1 = max(a.y1, b.y1);
    res.y2 = min(a.y2, b.y2);

    if (res.x1 >= res.x2 || res.y1 >= res.y2)
        res = {0, 0, 0, 0};

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    rect w, b1, b2;

    cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;
    cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
    cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;

    rect wb1 = inter(w, b1), wb2 = inter(w, b2), interse = inter(w, inter(b1, b2));

    if (area(w) > area(wb1) + area(wb2) - area(interse))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}