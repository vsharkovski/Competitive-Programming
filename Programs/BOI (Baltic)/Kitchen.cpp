#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n+1), b(m+1);
    int a_sum = 0, a_min = 1e5, b_sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a_sum += a[i];
        a_min = min(a_min, a[i]);
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
        b_sum += b[i];
    }
    if (a_min < k || b_sum < a_sum) {
        cout << "Impossible\n";
        return 0;
    }
    vector<int> pre(b_sum+1, -1e5), cur;
    pre[0] = 0;
    for (int i = 1; i <= m; ++i) {
        cur.assign(b_sum+1, -1e5);
        for (int h = 0; h <= b_sum; ++h) {
            if (h < b[i]) {
                cur[h] = pre[h];
            } else {
                cur[h] = max(pre[h], pre[h - b[i]] + min(b[i], n));
            }
        }
        swap(pre, cur);
    }
    int ans = 1e9;
    for (int h = a_sum; h <= b_sum; ++h) {
        if (pre[h] >= n*k) {
            ans = h - a_sum;
            break;
        }
    }
    if (ans == 1e9) {
        cout << "Impossible\n";
    } else {
        cout << ans << '\n';
    }
}
