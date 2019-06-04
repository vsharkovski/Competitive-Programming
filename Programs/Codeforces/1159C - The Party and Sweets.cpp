#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;




int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> b(n), g(m);
    int maxb = 0, ming = 1e9;
    ll sumg = 0;

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        maxb = max(maxb, b[i]);
    }
    for (int i = 0; i < m; ++i) {
        cin >> g[i];
        sumg += g[i];
        ming = min(ming, g[i]);
    }

    if (ming < maxb) {
        cout << -1 << '\n';
        return 0;
    }

    int idx[2] = {-1, -1}; // 2 rows with biggest b[i]
    for (int i = 0; i < n; ++i) {
        if (idx[0] == -1 || b[i] >= b[idx[0]]) {
            idx[1] = idx[0];
            idx[0] = i;
        } else if (idx[1] == -1 || b[i] > b[idx[1]]) {
            idx[1] = i;
        }
    }

    ll ans = 0;

    if (ming == b[idx[0]]) {
        // put all maxes (g) on this row
        for (int i = 0; i < n; ++i) {
            if (i == idx[0]) {
                ans += sumg;
            } else {
                ans += (ll)m * b[i];
            }
        }
    } else {
        // ming > b[idx[0]]
        // put all but 1 maxes (g) on this row
        // put that one on 2nd biggest row
        for (int i = 0; i < n; ++i) {
            if (i == idx[0]) {
                ans += (sumg - ming) + 1 * b[i];;
            } else if (i == idx[1]) {
                ans += ming + (ll)(m-1) * b[i];
            } else {
                ans += (ll)m * b[i];
            }
        }
    }

    cout << ans << '\n';
}
