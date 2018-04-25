#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    string s, t;
    cin >> s >> t;
    bool ok = 1;
    for (int i = 0, j = t.length()-1; i < s.length() && j >= 0; ++i, --j)
    {
        if (s[i] != t[j])
        {
            ok = 0;
            break;
        }
    }
    if (ok) cout << "YES";
    else cout << "NO";
}
