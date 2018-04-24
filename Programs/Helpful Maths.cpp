#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    string s;
    cin >> s;
    int data[4] = {};
    int numop = 0;
    for (char c : s)
    {
        if (c == '+') continue;
        ++data[ c-'0' ];
    }
    bool first = 1;
    for (int startx = 1; startx < 4; ++startx)
    {
        if (data[startx] == 0) continue;
        if (first)
        {
            cout << startx;
            first = 0;
        }
        else
        {
            cout << "+" << startx;
        }
        for (int i = 1; i < data[startx]; ++i)
        {
            cout << "+" << startx;
        }
    }

}
