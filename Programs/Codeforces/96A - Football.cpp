#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    string s;
    cin >> s;
    bool done = 0;
    int streak = 0, sign = 0;
    for (char c : s)
    {
        int x = c-'0';
        if (sign == x)
        {
            ++streak;
        }
        else
        {
            streak = 1;
            sign = x;
        }
        if (streak == 7)
        {
            cout << "YES";
            done = 1;
            break;
        }
    }
    if (!done)
        cout << "NO";
}
