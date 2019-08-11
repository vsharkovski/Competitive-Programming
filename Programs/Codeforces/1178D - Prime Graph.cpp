#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<pii> edges;
    for (int i = 1; i < n; ++i) {
        edges.emplace_back(i, i+1);
    }
    edges.emplace_back(n, 1);
    int p = n;
    while (true) {
        bool ok = true;
        for (int q = 2; q*q <= p; ++q) {
            if (p % q == 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            break;
        }
        ++p;
    }
    vector<int> deg(n+1, 2);
    for (int i = 1; i <= n; ++i) {
        if (p == n) {
            break;
        }
        if (deg[i] != 2) continue;
        int j = ((i-1)+2)%n + 1;
        edges.emplace_back(i, j);
        ++deg[i], ++deg[j];
        --p;
    }
    cout << edges.size() << endl;
    for (auto& p : edges) {
        cout << p.first << ' ' << p.second << endl;
    }
}
