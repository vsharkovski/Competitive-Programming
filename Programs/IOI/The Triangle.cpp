#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
template<class Key, class Compare = less<Key>>
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;


// WCIPEG 

int n;
int grid[110][110];
int dp[110][110];

int dfs(int i, int j) {
    if (dp[i][j] != -1) {
        return dp[i][j];
    } else if (i > n || j > n || j > i) {
        return dp[i][j] = 0;
    } else {
        return dp[i][j] = grid[i][j] + max(dfs(i+1, j), dfs(i+1, j+1));
    }
}

void Main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> grid[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    int ans = dfs(1, 1);
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
