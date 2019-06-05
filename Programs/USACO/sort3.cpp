#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/*
LANG: C++
TASK: sort3
*/

const int opened = -1;
const int inf = 1e9;

vector<vi> Empty, m;
map<vector<vi>, int> dp;

int dfs() {
    auto it = dp.find(m);
    if (it != dp.end()) {
        if (it->second == -1) {
            return inf;
        } else {
            return it->second;
        }
    }
    dp[m] = opened;
    int res = inf;
    if (m == Empty) {
        res = 0;
    } else {
        for (int g1 = 0; g1 < 2; ++g1) {
            for (int i = 0; i < 3; ++i) {
                for (int g2 = g1+1; g2 < 3; ++g2) {
                    for (int j = 0; j < 3; ++j) {
                        if (j == i) continue;
                        int x = min(m[g1][i], m[g2][j]);
                        m[g1][i] -= x;
                        m[g2][j] -= x;
                        if (j != g1) m[g1][j] += x;
                        if (i != g2) m[g2][i] += x;
                        res = min(res, x + dfs());
                        m[g1][i] += x;
                        m[g2][j] += x;
                        if (j != g1) m[g1][j] -= x;
                        if (i != g2) m[g2][i] -= x;
                    }
                }
            }
        }
    }
    return dp[m] = res;
}

int main() {
    #ifndef _DEBUG
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);
    #endif
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;

    int a[n];
    int cnt[3] = {};
    m.assign(3, vi(3, 0));

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        ++cnt[a[i]];
    }
    for (int i = 0; i < cnt[0]; ++i) {
        ++m[0][a[i]];
    }
    for (int i = cnt[0]; i < cnt[0] + cnt[1]; ++i) {
        ++m[1][a[i]];
    }
    for (int i = cnt[0] + cnt[1]; i < n; ++i) {
        ++m[2][a[i]];
    }
    m[0][0] = 0;
    m[1][1] = 0;
    m[2][2] = 0;

    Empty = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    int ans = dfs();

    cout << ans << '\n';

}
