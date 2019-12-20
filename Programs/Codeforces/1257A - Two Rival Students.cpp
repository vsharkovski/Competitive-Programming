#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x, a, b;
        cin >> n >> x >> a >> b;
        if (a > b) swap(a, b);
        int ans = b - a;
        if (x >= a-1) {
            x -= a - 1;
            ans += a - 1;
            a = 1;
            if (x >= n - b) {
                x -= n - b;
                ans += n - b;
                b = n;
            } else {
                b += x;
                ans += x;
                x = 0;
            }
        } else {
            ans += x;
            a -= x;
            x = 0;

        }
        cout << ans << endl;
    }


}
