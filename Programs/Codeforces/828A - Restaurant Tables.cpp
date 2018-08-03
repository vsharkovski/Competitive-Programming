#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n, ones, twos, denials = 0, twos_used_as_ones = 0;
    cin >> n >> ones >> twos;
    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            if (ones > 0)
            {
                --ones;
            }
            else if (twos > 0)
            {
                --twos;
                ++twos_used_as_ones;
            }
            else if (twos_used_as_ones > 0)
            {
                --twos_used_as_ones;
            }
            else
            {
                ++denials;
            }
        } else
        {
            if (twos > 0)
            {
                --twos;
            }
            else
            {
                denials += 2;
            }
        }
    }
    cout << denials;
}
