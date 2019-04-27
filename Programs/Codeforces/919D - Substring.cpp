#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



const int unvisited = 0, explored = 1, visited = 2;
const int maxn = 300005;

int n, m, current;
int label[maxn];
vector<int> adj[maxn];

bool found_cycle;
int status[maxn];

void dfs_cycle(int u) {
    status[u] = explored;
    for (int v : adj[u]) {
        if (status[v] == unvisited) {
            dfs_cycle(v);
        } else if (status[v] == explored) {
            found_cycle = true;
        }
        if (found_cycle) return;
    }
    status[u] = visited;
}

int dp[maxn];
int last[maxn]; // last letter for which this state was visited

int dfs_dp(int u) {
    if (last[u] == current) return dp[u];
    last[u] = current;
    dp[u] = 0;
    for (int v : adj[u]) {
        dp[u] = max(dp[u], dfs_dp(v));
    }
    if (label[u] == current) {
        ++dp[u];
    }
    return dp[u];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;
        label[i] = ch - 'a' + 1;
        last[i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
    }
    found_cycle = false;
    for (int i = 0; i < n; ++i) {
        if (status[i] == unvisited) {
            dfs_cycle(i);
            if (found_cycle) {
                cout << "-1\n";
                return 0;
            }
        }
    }
    int ans = 0;
    for (current = 1; current <= 26; ++current) {
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dfs_dp(i));
        }
    }
    cout << ans << '\n';
}
