#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    set<pii> edges;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        edges.emplace(a, b);
    }
    int nd1 = -1, nd2 = -1;
    for (int u = 1; u <= n; ++u) {
        for (int v = u+1; v <= n; ++v) {
            if (edges.count(pii(u, v)) == 0) {
                nd1 = u, nd2 = v;
                u = v = n+1;
            }
        }
    }
    if (nd1 == -1) {
        cout << "NO\n";
        return 0;
    }
    // cout << "nd1=" << nd1 << " nd2=" << nd2 << endl;
    vector<int> a(n+1, -1), b(n+1, -1);
    a[nd1] = 1;
    a[nd2] = 2;
    b[nd1] = b[nd2] = 1;
    int cnt = 2;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == -1) {
            a[i] = b[i] = ++cnt;
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << ' ';
    }
    cout << "\n";
    for (int i = 1; i <= n; ++i) {
        cout << b[i] << ' ';
    }
    cout << "\n";
}
 
