#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    for (char ch : s)
    {
        if (ch == 'a') ++a;
        else if (ch == 'b') ++b;
        else if (ch == 'c') ++c;
    }
    if (a >= 1 && b >= 1 && (c == a || c == b))
    {
        string s1 = s;
        sort(s1.begin(), s1.end());
        if (s1 == s)
        {
            cout << "YES";
        } else { cout << "NO"; }
    } else { cout << "NO"; }
}
