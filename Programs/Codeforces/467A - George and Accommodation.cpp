#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n;
    cin >> n;
    int cnt = 0;
    while (n--)
    {
        int p, q;
        cin >> p >> q;
        if (p + 2 <= q)
        {
            ++cnt;
        }
    }
    cout << cnt;
}
