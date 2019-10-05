#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        int cnt[12] = {};
        while (n--) {
            int x, p = 0;
            cin >> x;
            while ((1 << p) < x) {
                ++p;
            }
            if (p <= 11) {
                ++cnt[p];
            }
        }
        for (int i = 0; i < 11; ++i) {
            cnt[i+1] += cnt[i]/2;
            cnt[i] %= 2;
        }
        if (cnt[11] > 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
