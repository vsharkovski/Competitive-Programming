#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;







int n, m;
vector<vector<int>> g;
vector<pii> seq;

bool do_row(int i) {
    int mini = 1e9;
    for (int j = 0; j < m; ++j) {
        mini = min(mini, g[i][j]);
    }
    if (mini == 0) return false;
    for (int c = 0; c < mini; ++c) {
        seq.emplace_back(0, i);
    }
    for (int j = 0; j < m; ++j) {
        g[i][j] -= mini;
    }
    return true;
}

bool do_col(int j) {
    int mini = 1e9;
    for (int i = 0; i < n; ++i) {
        mini = min(mini, g[i][j]);
    }
    if (mini == 0) return false;
    for (int c = 0; c < mini; ++c) {
        seq.emplace_back(1, j);
    }
    for (int i = 0; i < n; ++i) {
        g[i][j] -= mini;
    }
    return true;
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
            do_row(i);
        }
        for (int j = 0; j < m; ++j) {
            do_col(j);
        }
    } else {
        for (int j = 0; j < m; ++j) {
            do_col(j);
        }
        for (int i = 0; i < n; ++i) {
            do_row(i);
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

