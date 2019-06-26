#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



const int maxn = 505;
const int maxm = maxn*(maxn-1)/2;

int n, m;
int x[maxn];
vector<pii> adj[maxn];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    double ans = 0;

    for (int u = 1; u <= n; ++u) {
        for (auto& to : adj[u]) {
            int v = to.first, c = to.second;
            double res = double(x[u] + x[v]) / double(c);
            ans = max(ans, res);
        }
    }

    cout << setprecision(15) << fixed;
    cout << ans << '\n';

}
