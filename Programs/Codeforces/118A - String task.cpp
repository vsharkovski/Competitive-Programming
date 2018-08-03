#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    string s;
    cin >> s;
    for (char c : s)
    {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'y' || c == 'i' || c == 'o' || c == 'u')
            continue;
        cout << '.' << c;
    }
}
