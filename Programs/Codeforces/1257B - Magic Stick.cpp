#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll x, y;
        cin >> x >> y;
        if (y == 3) {
            if (x > 1) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            continue;
        }
        while (x < y && x > 3) {
            if (x % 2 == 0) {
                x = 3 * x / 2;
            } else {
                x -= 1;
            }
        }
        if (x < y) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}
