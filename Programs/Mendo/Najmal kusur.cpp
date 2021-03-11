#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int b1, b2, b3, m;
    cin >> b1 >> b2 >> b3 >> m;
    int ans = m, f1 = 0, f2 = 0, f3 = 0;
    for (int c1 = 0; c1 <= 1000; ++c1) {
        for (int c2 = 0; c2 <= 1000; ++c2) {
            int mnow = m - c1*b1 - c2*b2;
            if (mnow < 0) continue;
            int c3 = mnow/b3;
            mnow %= b3;
            if (mnow < ans) {
                ans = mnow;
                f1 = c1, f2 = c2, f3 = c3;
            }
        }
    }
    cout << ans << '\n' << f1 << ' ' << f2 << ' ' << f3 << '\n';
}
