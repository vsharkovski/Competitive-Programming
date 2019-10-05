#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int a, b, k1, k2, n;
    cin >> a >> b >> k1 >> k2 >> n;
    if (k1 > k2) swap(a, b), swap(k1, k2);
    // k1 <= k2
    int m = (k1-1)*a + (k2-1)*b;
    if (n <= m) {
        cout << 0 << " ";
    } else {
        cout << n-m << " ";
    }
    int cnt = n/k1;
    if (cnt <= a) {
        cout << cnt << endl;
    } else {
        // cnt >= a
        n -= k1*a;
        cnt = n/k2;
        if (cnt <= b) {
            cout << a + cnt << endl;
        } else {
            cout << a + b << endl;
        }
    }
}
