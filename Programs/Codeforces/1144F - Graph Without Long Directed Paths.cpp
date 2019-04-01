#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;



void Main() {
    int n, m;
    cin >> n >> m;
    vector<pi> edges;
    vector<vector<int>> G(n+1, vector<int>());
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(u, v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> outgoing(n+1, 0), color(n+1, -1);
    queue<int> q;
    color[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : G[u]) {
            if (color[v] == color[u]) {
                cout << "NO\n";
                return;
            } else if (color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < m; ++i) {
        cout << color[edges[i].first];
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifdef _DEBUG
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    #endif
    Main();
}
