#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int c[n]; //differences
    int k = k1+k2;
    for (int i = 0; i < n; ++i) cin >> c[i];
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        c[i] = abs(c[i] - x);
    }
    while (k--)
    {
        //std::max_element
        int maxi = -1, maxv = -1;
        for (int i = 0; i < n; ++i) {
            if (c[i] > maxv) {
                maxi = i;
                maxv = c[i];
            }
        }
        //
        c[maxi] = abs(c[maxi] - 1);
    }
    long long z = 0;
    for (int d : c) z += (long long)d * (long long)d;
    cout << z;
}
