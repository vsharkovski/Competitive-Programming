#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    string p;
    cin >> p;
    bool ok = 0;
    for (char c : p)
    {
        if (c == 'H' || c == 'Q' || c == '9')
        {
            ok = 1;
            break;
        }
    }
    if (ok)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}
