#include <bits/stdc++.h>
using namespace std;

bool comp(int a, int b)
{
    return a > b;
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n, A, B;
    cin >> n >> A >> B;
    vector<int> v;
    double s0;
    cin >> s0;
    int S = s0;
    for (int i = 1; i < n; ++i)
    {
        int x;
        cin >> x;
        S += x;
        v.push_back(x);
    }
    sort(v.begin(), v.end(), comp);
    int i = 0;
    while (((double)s0 * (double)A / (double)S) < B && i < n)
    {
        S -= v[i];
        ++i;
    }
    cout << i;
}
