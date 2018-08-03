#include <bits/stdc++.h>
using namespace std;



int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n, s;
    cin >> n >> s;
    set<int> times;
    int ph = -1, pm = -1;
    for (int i = 0; i < n; ++i)
    {
        int h, m;
        cin >> h >> m;
        if (ph*60 + pm > h*60 + m)
        {
            h += 24;
        }
        ph = h; pm = m;
        times.insert(h*60+m);
    }
    if (*times.begin()-1 >= s)
    {
        cout << 0 << " " << 0 << '\n';
    }
    else
    {
        for (auto it = times.begin(); it != times.end(); ++it)
        {
            if (next(it) != times.end())
            {
                auto nextit = next(it);
                if (*nextit - *it >= s+s+1+1)
                {
                    int t = *it + s + 1;
                    int h = t / 60;
                    int m = t % 60;
                    cout << h << " " << m;
                    break;
                }
            }
            else
            {
                int t = *it + s + 1;
                int h = t / 60;
                int m = t % 60;
                cout << h << " " << m;
                break;
            }
        }
    }

}
