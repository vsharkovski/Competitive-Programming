#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;







int n, m;
vector<vector<int>> g;
vector<pii> seq;

bool do_row(int i) {
    bool ok = true;
    for (int j = 0; j < m; ++j) {
        if (g[i][j] == 0) {
            ok = false;
            break;
        }
    }
    if (ok) {
        seq.emplace_back(0, i);
        for (int j = 0; j < m; ++j) {
            --g[i][j];
        }
    }
    return ok;
}

bool do_col(int j) {
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (g[i][j] == 0) {
            ok = false;
            break;
        }
    }
    if (ok) {
        seq.emplace_back(1, j);
        for (int i = 0; i < n; ++i) {
            --g[i][j];
        }
    }
    return ok;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();

    cin >> n >> m;

    g.assign(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }

    if (n <= m) {
        for (int i = 0; i < n; ++i) {
            while (do_row(i)) {}
        }
        for (int j = 0; j < m; ++j) {
            while (do_col(j)) {}
        }
    } else {
        for (int j = 0; j < m; ++j) {
            while (do_col(j)) {}
        }
        for (int i = 0; i < n; ++i) {
            while (do_row(i)) {}
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] > 0) {
                cout << "-1\n";
                return 0;
            }
        }
    }

    cout << seq.size() << '\n';
    for (auto& p : seq) {
        cout << (p.first == 0 ? "row" : "col") << ' ' << p.second+1 << '\n';
    }

}

