#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int posi, posj;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                posi = i;
                posj = j;
            }
        }
    }
    int moves = 0;
    while (posi != 2 || posj != 2)
    {
        if (posi < 2)
        {
            ++posi;
            ++moves;
        }
        else if (posi > 2)
        {
            --posi;
            ++moves;
        }
        if (posj < 2)
        {
            ++posj;
            ++moves;
        }
        else if (posj > 2)
        {
            --posj;
            ++moves;
        }
    }
    cout << moves;
}
