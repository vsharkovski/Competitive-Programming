#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n;
    cin >> n;
    int capacity = 0, load = 0;
    for (int i = 0; i < n; ++i)
    {
        int entering, exiting;
        cin >> exiting >> entering;
        load = load - exiting + entering;
        capacity = max(capacity, load);
    }
    cout << capacity;
}
