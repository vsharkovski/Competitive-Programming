#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    map<int, set<int>> m;
    int cnt = 0;
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        m[u].insert(v);
        m[v].insert(u);
    }
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second.size() == 1) {
            ++cnt;
        }
    }
    cout << cnt;
}
