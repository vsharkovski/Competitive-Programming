#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int maxn = 100010;

// see code for articulation points and bridges

int n, m;
vector<int> adj[maxn];

int timer;
int tin[maxn], low[maxn];
vector<pii> stk;

void bcc(int u, int p) {
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
            artpb(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= tin[u] && p != -1) {
                // u is articulation point
                // all edges after (u, v), inclusive
                // are part of a biconnected component
                cout << "BCC: ";
                while (true) {
                    cout << stk.back().first << "-" << stk.back().second << " ";
                    if (stk.back().first == u && stk.back().second == v) {
                        stk.pop_back();
                        break;
                    } else {
                        stk.pop_back();
                    }
                }
                cout << endl;
            }
        }
    }
    if (p == -1) {
        // all remaining edges in stack
        // make the final biconnected component
        cout << "BCC: ";
        while (!stk.empty()) {
            cout << stk.back().first << "-" << stk.back().second << " ";
            stk.pop_back();
        }
        cout << endl;
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
    bcc(1, -1);
}
