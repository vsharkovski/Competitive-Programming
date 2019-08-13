struct DSU {
    int n;
    vector<int> p, rank;
    DSU(int n) : n(n) {
        rank.assign(n, 0);
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    inline int get(int x) {
        return p[x] == x ? x : (p[x] = get(p[x]));
    }
    inline bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        p[y] = x;
        return true;
    }
};
