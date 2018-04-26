#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> v(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        sum += v[i];
    }
    ll sum1 = 0;
    for (int i = 0; i < n; ++i)
    {
        sum1 += v[i];
        if (sum1+sum1 >= sum)
        {
            cout << i+1;
            break;
        }
    }
}
