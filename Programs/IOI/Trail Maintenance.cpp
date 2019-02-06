#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
template<class Key, class Compare = less<Key>>
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;





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

void Main() {
    int N, W;
    cin >> N >> W;
    multiset<pair<int, pi>> edges;
    for (int week = 0; week < W; ++week) {
        int wu, wv, wc;
        cin >> wu >> wv >> wc;
        edges.emplace(wc, pi(wu-1, wv-1));
        DSU dsu(N);
        int cost = 0;
        int numcc = N;
        for (auto& edge : edges) {
            int c = edge.first;
            int u = edge.second.first, v = edge.second.second;
            if (dsu.unite(u, v)) {
                cost += c;
                --numcc;
            }
        }
        if (numcc > 1) {
            cost = -1;
        }
        cout << cost << '\n';
    }
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
    #ifdef _DEBUG
//        freopen("in.txt", "r", stdin);
//        freopen("out.txt", "w", stdout);
    #endif
    Main();
    return 0;
}
