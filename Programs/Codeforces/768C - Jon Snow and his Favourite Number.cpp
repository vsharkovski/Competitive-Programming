#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;






int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    const int maxval = 1024;

    int n, k, x;
    cin >> n >> k >> x;

    int a[maxval] = {}, b[maxval] = {};
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        ++a[t];
    }

    while (k--) {
        memset(b, 0, sizeof(b));
        int idx = 0;
        for (int i = 0; i < maxval; ++i) {
            if (a[i] % 2 == 0) {
                int c = a[i]/2;
                b[i^x] += c;
                b[i] += c;
            } else {
                int c = a[i]/2 + 1 - idx;
                b[i^x] += c;
                b[i] += a[i] - c;
                idx = 1 - idx;
            }
        }
        swap(a, b);
    }

    int mini = maxval, maxi = -1;
    for (int i = 0; i < maxval; ++i) {
        if (a[i] > 0) {
            mini = min(mini, i);
            maxi = max(maxi, i);
        }
    }

    cout << maxi << ' ' << mini << '\n';

}
