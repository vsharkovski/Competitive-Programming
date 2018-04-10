#include <bits/stdc++.h>
using namespace std;
 
int k;
 
inline bool OK(int n)
{
    return n*(n+1)/2 == k;
}
 
int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    cin >> k;
    int n = (-1 + sqrt(8*k+1)) / 2;
    if (OK(n))
    {
        cout << n;
    }
    else
    {
        for (int i = n-100; i < n+101; ++i)
        {
            if (OK(i))
            {
                cout << i;
                break;
            }
        }
    }
}
