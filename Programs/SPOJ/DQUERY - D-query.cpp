#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;


const int maxd = 1000010;
const int maxn = 30010;
const int maxq = 200010;

int n;
int arr[maxn];
int last[maxd];

int q;
vector<pii> queries[maxn];
int qans[maxq];

struct fenwick {
    int tree[maxd];
    void update(int pos, int val) {
        while (pos < maxd) {
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
} tree;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int l, r;
        cin >> l >> r;
        queries[r].emplace_back(l, i);
    }
    for (int i = 0; i < maxd; ++i) {
        last[i] = 0;
    }
    for (int r = 1; r <= n; ++r) {
        if (last[arr[r]] > 0) {
            tree.update(last[arr[r]], -1);
        }
        tree.update(r, 1);
        last[arr[r]] = r;
        for (auto &p : queries[r]) {
            int l = p.first, i = p.second;
            qans[i] = tree.query(l, r);
        }
    }
    for (int i = 1; i <= q; ++i) {
        cout << qans[i] << '\n';
    }
}
