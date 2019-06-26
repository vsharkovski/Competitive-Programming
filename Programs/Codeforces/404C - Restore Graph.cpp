#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;




int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pii> dist(n);
    for (int i = 0; i < n; ++i) {
        cin >> dist[i].first;
        dist[i].second = i;
    }
    sort(dist.begin(), dist.end());

    vector<pii> edges;
    vector<int> degree(n, 0);
    vector<vector<int>> nodes(n); // nodes[i] = list of all nodes at distance i

    if (dist[0].first != 0 || dist[1].first == 0) {
        cout << "-1\n";
        return 0;
    }

    nodes[0].push_back(0);
    for (int i = 1; i < n; ++i) {
        int d = dist[i].first;
        if (nodes[d-1].empty()) {
            cout << "-1\n";
            return 0;
        }
        int j = nodes[d-1].back();
        nodes[d].push_back(i);
        edges.emplace_back(j, i);
        ++degree[i];
        ++degree[j];
        if (degree[j] == k) {
            nodes[d-1].pop_back();
        }
        if (degree[i] == k) {
            nodes[d].pop_back();
        }
    }

    cout << edges.size() << '\n';
    for (auto& e : edges) {
        cout << dist[e.first].second+1 << ' ' << dist[e.second].second+1 << '\n';
    }
}
