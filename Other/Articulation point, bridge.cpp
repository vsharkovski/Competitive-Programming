#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int n;
vector<vector<int>> adj;

vector<int> num, low;
int calls;

vector<int> articulation_point;
vector<pair<int, int>> articulation_bridges;

void artpb(int u, int p) {
    num[u] = low[u] = calls++;
    int children = 0;
    for (int v : adj[u]) {
        if (num[v] == -1) {
            ++children;
            artpb(v, u);
            if (low[v] >= num[u] && p != -1) {
                articulation_point[u] = 1;
            }
            if (low[v] > num[u]) {
                articulation_bridges.emplace_back(u, v);
            }
            low[u] = min(low[u], low[v]);
        } else if (v != p) {
            low[u] = min(low[u], num[v]);
        }
    }
    if (p == -1 && children > 1) {
        articulation_point[u] = 1;
    }
}

void Main() {
    cin >> n;
    adj.assign(n+1, vector<int>());
    int m;
    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    num.assign(n+1, -1);
    low.assign(n+1, 0);
    articulation_point.assign(n+1, 0);
    calls = 0;
    for (int i = 1; i <= n; ++i) {
        if (num[i] == -1) {
            artpb(i, -1);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (articulation_point[i]) {
            cout << "Articulation point: " << i << "\n";
        }
    }
    for (auto& p : articulation_bridges) {
        cout << "Articulation bridges: " << p.first << " - " << p.second << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
