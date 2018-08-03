#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    string ns;
    cin >> ns;

    int len = ns.length();
    char a[11] = {};
    for (int i = 0, j = len-1; i < len && j >= 0; ++i, --j)
    {
        a[i] = ns[j];
    }

    int minsteps = 1000;
    long long maxmask = 1 << len;
    for (long long mask = 0; mask < maxmask; ++mask)
    {
        int steps = 0;
        string xs = "";
        for (int i = len-1; i >= 0; --i)
        {
            if ((mask & (1 << i)) == 0) //ith bit is
            {
                xs += a[i];
            }
            else
            {
                ++steps;
            }
        }
        if (xs != "")
        {
            int x = stoi(xs);
            int root = sqrt(x);
            if (xs[0] != '0' && root*root == x)
            {
                minsteps = min(steps, minsteps);
            }
        }
    }

    if (minsteps == 1000) minsteps = -1;
    cout << minsteps << '\n';
}
