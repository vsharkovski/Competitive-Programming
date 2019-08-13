struct fenwick {
    int n;
    vector<int> tree;
    fenwick(int n) : n(n) {
        tree.assign(n+1, 0);
    }
    void update(int pos, int val) {
        while (pos <= n) {
            tree[pos] += val;
            pos += pos & -pos;
        }
    }
    int query(int pos) {
        int res = 0;
        while (pos >= 1) {
            res += tree[pos];
            pos -= pos & -pos;
        }
        return res;
    }
    int query(int l, int r) {
        return query(r) - query(l-1);
    }
};
