#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
//    std::ios::sync_with_stdio(false);
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int a[4];
    for (int i = 0; i < 4; ++i) cin >> a[i];
    sort(a, a+4);
    cout << a[0]*a[2];
}
