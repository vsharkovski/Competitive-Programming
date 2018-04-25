#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n, t;
    cin >> n >> t;
    string a, a1, blank;
    cin >> a;
    blank.resize(a.size(), ' ');
    a1 = blank;
    for (int i = 0; i < t; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            if (a[j-1] == 'B' && a[j] == 'G')
            {
                a1[j-1] = 'G';
                a1[j] = 'B';
            }
            else
            {
                a1[j] = a[j];
            }
        }
        if (a1[0] == ' ') a1[0] = a[0];
        a = a1;
        a1 = blank;
    }
    cout << a;
}
