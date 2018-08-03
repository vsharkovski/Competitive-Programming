#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    string w;
    cin >> w;
    bool allCaps = true;
    for (int i = 1; i < w.length(); ++i)
    {
        if (tolower(w[i]) == w[i])
        {
            allCaps = false;
            break;
        }
    }
    if (allCaps)
    {
        if (w[0] == tolower(w[0]))
        {
            cout << (char)toupper(w[0]);
        }
        else
        {
            cout << (char)tolower(w[0]);
        }
        for (int i = 1; i < w.length(); ++i)
        {
            cout << (char)tolower(w[i]);
        }
    }
    else
    {
        cout << w;
    }
}
