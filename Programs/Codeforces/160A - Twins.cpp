#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a+n);
    int sum1 = 0, i = n-1, steps = 0;
    while (sum1 <= sum && i >= 0)
    {
        sum1 += a[i];
        sum -= a[i];
        --i;
        ++steps;
    }
    cout << steps;
}
