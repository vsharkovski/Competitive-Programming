#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


const int maxn = 5005;

int n;
vector<int> adj[maxn];

ll minsalary(int root) {
    vector<ll> d(n, -1);
    queue<int> q;
    ll sumd = 0;
    int numvisited = 0;
    d[root] = 0;
    q.push(root);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        sumd += d[u];
        ++numvisited;
        for (int v : adj[u]) {
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    return numvisited == n ? sumd+n : -1;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        while (k--) {
            int j;
            cin >> j;
            --j;
            adj[j].push_back(i);
        }
    }
    ll ans = 1e9;
    for (int i = 0; i < n; ++i) {
        ll res = minsalary(i);
        if (res != -1 && res < ans) {
            ans = res;
        }
    }
    if (ans == 1e9) ans = -1;
    cout << ans << '\n';
}
