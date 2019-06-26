#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



struct DSU {
    int n;
    vector<int> p, rank;
    DSU(int _n) {
        n = _n;
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        rank.assign(n, 0);
    }
    inline int get(int x) {
        return p[x] == x ? x : (p[x] = get(p[x]));
    }
    inline bool unite(int x, int y) {
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
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pii> ans(m);
    vector<pii> edges(m);
    vector<int> idx(m);

    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
        idx[i] = i;
    }

    sort(idx.begin(), idx.end(), [&] (int i, int j) {
        pii& x = edges[i];
        pii& y = edges[j];
        return x.first != y.first ? x.first < y.first : x.second > y.second;
    });

    int wanted = 2;
    int extra1 = 2, extra2 = 3;

    DSU dsu(n+1);
    vector<pii> edges2;

    for (int i : idx) {
        pii& e = edges[i];
        if (e.second) {
            if (wanted > n || dsu.get(1) == dsu.get(wanted)) {
                cout << "-1\n";
                return 0;
            }
            dsu.unite(1, wanted);
            ans[i] = {1, wanted};
            ++wanted;
        } else {
            if (extra1 > n || extra2 > n || dsu.get(extra1) != dsu.get(extra2)) {
                cout << "-1\n";
                return 0;
            }
            ans[i] = {extra1, extra2};
            if (extra1+1 < extra2) {
                ++extra1;
            } else {
                ++extra2;
                extra1 = 2;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }

}
