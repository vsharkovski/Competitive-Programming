#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


const int maxn = 1e5 + 2;
const int maxm = 40;
const int memo_limit = 1 << 20;

int n, m;
ll good[maxm]; // good[i] is the set of all nodes not adjacent to i
int dp[memo_limit];

int dfs(ll mask) {
    if (mask < memo_limit && dp[mask] != -1) {
        return dp[mask];
    }
    int res = 0;
    if (mask > 0) {
        for (int i = m-1; i >= 0; --i) {
            if (!(mask & (1LL << i))) continue;
            // leave it
            res = max(res, dfs(mask & ~(1LL << i)));
            // take it
            // disable all neighbors
            res = max(res, 1 + dfs(mask & good[i]));
            break;
        }
    }
    if (mask < memo_limit) {
        dp[mask] = res;
    }
    return res;
}

int get_id(string& s) {
    static map<string, int> mp;
    static int curr = 0;
    if (mp.count(s) == 0) {
        mp[s] = curr++;
    }
    return mp[s];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        good[i] = (1LL << i);
    }
    ll block = 0; // current set of people between two abilities to change
    for (int idx = 0; idx <= n; ++idx) {
        int t;
        if (idx < n) {
            cin >> t;
        }
        if (idx == n || t == 1) {
            for (int i = 0; i < m; ++i) {
                if (!(block & (1LL << i))) continue;
                for (int j = i+1; j < m; ++j) {
                    if (!(block & (1LL << j))) continue;
                    good[i] |= (1LL << j);
                    good[j] |= (1LL << i);
                }
            }
            block = 0;
        } else {
            string s;
            cin >> s;
            int id = get_id(s);
            block |= (1LL << id);
        }
    }
    for (int i = 0; i < m; ++i) {
        good[i] = ~good[i] & ((1LL << m)-1);
    }
    memset(dp, -1, sizeof(dp));
    int ans = dfs((1LL << m) - 1);
    cout << ans << '\n';
}
