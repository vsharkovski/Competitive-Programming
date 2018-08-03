#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    string s;
    cin >> s;
    int cnt = 0;
    for (char c : s)
    {
        if (c == '4' || c == '7')
            ++cnt;
    }
    string scnt = to_string(cnt);
    bool lucky = 1;
    for (char c : scnt)
    {
        if (c != '4' && c != '7')
        {
            lucky = 0;
            break;
        }
    }
    if (lucky) cout << "YES";
    else cout << "NO";
}
