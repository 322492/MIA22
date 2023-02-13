#include <bits/stdc++.h>

using namespace std;

struct point
{
    double x, y, z;
};

const int MAX = 10004;
const double EPS = 0.0000001;
int n;
double vs, vp, maks_s = 0.0;
point wej[MAX];
point P, gdzie;

double dist(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}

point miejsce_znicza(double t)
{
    double akt, curt;

    for (int i = 0; i <= n; i++)
    {
        akt = dist(wej[i], wej[i + 1]);
        curt = akt / vs;
        if (curt > t)
        {
            point res = wej[i];
            res.x += (wej[i + 1].x - wej[i].x) * t / curt;
            res.y += (wej[i + 1].y - wej[i].y) * t / curt;
            res.z += (wej[i + 1].z - wej[i].z) * t / curt;
            return res;
        }
        t -= curt;
    }

    return wej[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    cin >> wej[0].x >> wej[0].y >> wej[0].z;
    for (int i = 1; i <= n; i++)
    {
        cin >> wej[i].x >> wej[i].y >> wej[i].z;
        maks_s += dist(wej[i - 1], wej[i]);
    }

    cin >> vp >> vs;
    cin >> P.x >> P.y >> P.z;

    double L = 0.0, R = maks_s / vs + 1.0, M;
    int counter = 0;
    while (counter++ <= 60)
    {
        M = (L + R) / 2.0;
        cout << fixed << setprecision(9);
        gdzie = miejsce_znicza(M);
        //cout << gdzie.x << " " << gdzie.y << " " << gdzie.z << "\n";

        if (dist(P, gdzie) / vp <= M)
            R = M;
        else
            L = M;
    }

    if (L > maks_s/vs + EPS)
    {
        cout << "NO\n";
        return 0;
    }

    cout << fixed << setprecision(9);
    cout << "YES\n"
         << M << "\n"
         << gdzie.x << " " << gdzie.y << " " << gdzie.z;

    return 0;
}