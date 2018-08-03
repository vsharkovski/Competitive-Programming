#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    string target = "hello";
    int ti = 0, tlen = target.length();
    string s;
    cin >> s;
    bool ok = 0;
    for (char c : s)
    {
        if (target[ti] == c)
        {
            ++ti;
            if (ti == tlen)
            {
                ok = 1;
            }
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
