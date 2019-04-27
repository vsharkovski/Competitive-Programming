#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



const int maxn = 101;
const int maxa = 27;

int n, m;
vector<pii> adj[maxn];
int dp[2][maxa][maxn][maxn];

// dp[current_player][previous_edge_label][max_node][lucas_node]
// = whether current player can win from here by making some optimal move

int dfs(int t, int pr, int i, int j) {
    int& res = dp[t][pr][i][j];
    if (res != -1) {
        return res;
    }
    res = 0;
    if (t == 0) {
        for (auto& to : adj[i]) {
            int k = to.first, x = to.second;
            if (x >= pr) {
                res |= !dfs(1, x, k, j);
                if (res == 1) break;
            }
        }
    } else {
        for (auto& to : adj[j]) {
            int k = to.first, x = to.second;
            if (x >= pr) {
                res |= !dfs(0, x, i, k);
                if (res == 1) break;
            }
        }
    }
    return res;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        char ch;
        cin >> a >> b >> ch;
        --a, --b;
        adj[a].emplace_back(b, ch-'a'+1);
    }
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << (dfs(0, 0, i, j) ? 'A' : 'B');
        }
        cout << '\n';
    }
}
