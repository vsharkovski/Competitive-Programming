#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int c, m, x;
        cin >> c >> m >> x;
        int a = min({c, m, (x+c+m)/3});
        cout << a << endl;
    }
}
