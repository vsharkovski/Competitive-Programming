#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
//template<class Key, class Compare = less<Key>>
//using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;




const ll mod = 1e9 + 7;
ll N, M, D;
ll dp[105][105];

ll dfs(ll i, ll j) {
    ll& res = dp[i][j];
    if (res != -1) {
        return res;
    }
    if (i == M) {
        if (j == N) {
            return res = 1;
        } else {
            return res = 0;
        }
    }
    res = 0;
    res += max(0LL, j - D) * dfs(i+1, j);
    res %= mod;
    if (j < N) {
        res += (N - j) * dfs(i+1, j+1);
        res %= mod;
    }
    return res;
}

void Main() {
    cin >> N >> M >> D;
    memset(dp, -1, sizeof(dp));
    ll ans = dfs(0, 0);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef _DEBUG
//        freopen("in.txt", "r", stdin);
//        freopen("out.txt", "w", stdout);
    #endif
    Main();
    return 0;
}
