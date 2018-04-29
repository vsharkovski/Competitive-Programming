#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    int a[n] = {};
    while (m--) {
        int c;
        cin >> c;
        a[c-1]++;
    }
    int mini = 1000069;
    for (int x : a) {
        if (x < mini) mini = x;
    }
    cout << mini;
}
