#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;





int N;

struct DSU {
    int n;
    vector<int> p, rank;
    DSU(int _n) {
        n = _n;
        rank.assign(n, 0);
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    int get(int x) {
        return p[x] == x ? x : (p[x] = get(p[x]));
    }
    int get(int r, int c) {
        return get(r*N + c);
    }
    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return false;
        if (rank[x] > rank[y]) {
            p[y] = x;
        } else {
            p[x] = y;
            if (rank[x] == rank[y]) {
                ++rank[y];
            }
        }
        return true;
    }
    bool unite(int r1, int c1, int r2, int c2) {
        return unite(r1*N + c1, r2*N + c2);
    }
};

bool in(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N;
}

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

DSU dsu(2600);
int grid[52][52];
int sr, sc, er, ec;

void dfs(int r, int c) {
    for (int d = 0; d < 4; ++d) {
        int r1 = r + dr[d], c1 = c + dc[d];
        if (in(r1, c1) && grid[r1][c1] == 0 && dsu.get(r1, c1) != dsu.get(r, c)) {
            dsu.unite(r, c, r1, c1);
            dfs(r1, c1);
        }
    }
}

void Main() {
    cin >> N >> sr >> sc >> er >> ec;
    --sr, --sc, --er, --ec;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            char ch;
            cin >> ch;
            grid[r][c] = ch == '1';
        }
    }
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (grid[r][c] == 0) {
                dfs(r, c);
            }
        }
    }
    int ans = 1e9;
    if (dsu.get(sr, sc) == dsu.get(er, ec)) {
        ans = 0;
    } else {
        vector<pair<int, int>> srcgood, endgood;
        int srcid = dsu.get(sr, sc), endid = dsu.get(er, ec);
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                int id = dsu.get(r, c);
                if (id == srcid) {
                    srcgood.emplace_back(r, c);
                } else if (id == endid) {
                    endgood.emplace_back(r, c);
                }
            }
        }
        for (int i = 0; i < srcgood.size(); ++i) {
            int r1 = srcgood[i].first, c1 = srcgood[i].second;
            for (int j = 0; j < endgood.size(); ++j) {
                int r2 = endgood[j].first, c2 = endgood[j].second;
                ans = min(ans, (r1 - r2)*(r1 - r2) + (c1 - c2)*(c1 - c2));
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
