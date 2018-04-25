#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> a = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};
    bool ok = 0;
    for (int x : a)
    {
        if (n % x == 0)
        {
            ok = 1;
            break;
        }
    }
    if (ok) cout << "YES";
    else cout << "NO";
}
