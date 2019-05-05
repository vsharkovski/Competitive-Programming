#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


const int unopened = 0, opened = 1, closed = 2;
const int maxn = 300010;

int n, x;
ll a[maxn];
ll dp[3][3][maxn];

ll dfs(int state_max, int state_mul, int pos) {
    ll& res = dp[state_max][state_mul][pos];
    if (res != -1) {
        return res;
    }
    res = 0;
    if (pos < n) {
        if (state_max == unopened) {
            res = max(res, dfs(opened, state_mul, pos));
        } else if (state_max == opened) {
            res = max(res, dfs(closed, state_mul, pos));
        }
        if (state_mul == unopened) {
            res = max(res, dfs(state_max, opened, pos));
        } else if (state_mul == opened) {
            res = max(res, dfs(state_max, closed, pos));
        }
        ll current_gains = 0; // gains at this position
        if (state_max == opened) {
            current_gains = a[pos];
        }
        if (state_mul == opened) {
            current_gains *= x;
        }
        res = max(res, current_gains + dfs(state_max, state_mul, pos+1));
    }
    return res;
}

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    ll ans = dfs(unopened, unopened, 0);
    cout << ans << '\n';
}
