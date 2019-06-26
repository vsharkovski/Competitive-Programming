#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int n, k;
vector<vector<int>> adj;

pii dfs(int u, int p) {
    int farthest = u, maxdist = 0;
    for (int v : adj[u]) {
        if (v != p) {
            pii res = dfs(v, u);
            if (1 + res.second > maxdist) {
                maxdist = 1 + res.second;
                farthest = res.first;
            }
        }
    }
    return pii(farthest, maxdist);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> k;

    adj.assign(n+1, vector<int>());

    for (int i = 2; i <= k+1; ++i) {
        adj[1].push_back(i);
        adj[i].push_back(1);
    }
    for (int i = k+2; i <= n; ++i) {
        adj[i-k].push_back(i);
        adj[i].push_back(i-k);
    }

    cout << dfs(dfs(1, -1).first, -1).second << '\n';

    for (int i = 1; i <= n; ++i) {
        for (int j : adj[i]) {
            if (j > i) {
                cout << i << ' ' << j << '\n';
            }
        }
    }

}
