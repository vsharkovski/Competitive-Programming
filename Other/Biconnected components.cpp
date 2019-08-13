#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

// see code for articulation points and bridges

const int maxn = 100010;

int n, m;
vector<int> adj[maxn];

int timer;
int tin[maxn], low[maxn];
vector<pii> stk;
vector<int> stk2;

void bcc_solve(int fnd1, int fnd2) {
    // fnd1, fnd2: final edge in bcc from stack
    // keep popping from stack until that edge is popped
    // the edges you get are the edges of the bcc

    /*
    while (true) {
        // stk.back() is an edge in bcc
        if (stk.back().first == fnd1 && stk.back().second == fnd2) {
            stk.pop_back();
            break;
        } else {
            stk.pop_back();
        }
    }
    */
}

void bcc_dfs(int u, int p) {
    tin[u] = low[u] = timer++;
    int children = 0;
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        } else if (tin[v] != -1) {
            low[u] = min(low[u], tin[v]);
            if (tin[v] < tin[u]) {
                stk.emplace_back(u, v);
            }
        } else {
            ++children;
            stk.emplace_back(u, v);
            bcc_dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= tin[u] && p != -1) {
                // u is articulation point
                // all edges after (u, v), inclusive
                // are part of a biconnected component
                bcc_solve(u, v);
            }
        }
    }
    if (p == -1) {
        // all remaining edges in the stack
        // make the final biconnected component
        bcc_solve(-1, -1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    timer = 0;
    memset(tin, -1, sizeof(tin));
    bcc_dfs(1, -1);
}
