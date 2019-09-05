#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 300010;

int n, m, q;
vector<int> pos[maxn]; // positions this owner owns
ll want[maxn]; // how much this owner wants
int ans[maxn];

int qL[maxn], qR[maxn], qVal[maxn];
int queriesDone;

struct fenwick {
    ll tree[maxn];
    void update(int pos, int val) {
        while (pos < maxn) {
            tree[pos] += val;
            pos += pos & -pos;
        }
    }
    void update(int l, int r, int val) {
        if (l <= r) {
            update(l, val);
            update(r+1, -val);
        } else {
            update(l, val);
            update(m+1, -val);
            update(1, val);
            update(r+1, -val);
        }
    }
    ll query(int pos) {
        ll res = 0;
        while (pos >= 1) {
            res += tree[pos];
            pos -= pos & -pos;
        }
        return res;
    }
} tree;

void rec(int L, int R, vector<int>& owners) {
    if (owners.empty()) return;
    int mid = (L + R) / 2;
    while (queriesDone < mid) {
        ++queriesDone;
        tree.update(qL[queriesDone], qR[queriesDone], qVal[queriesDone]);
    }
    while (queriesDone > mid) {
        tree.update(qL[queriesDone], qR[queriesDone], -qVal[queriesDone]);
        --queriesDone;
    }
    vector<int> finished, unfinished;
    for (int i : owners) {
        ll total = 0;
        for (int j : pos[i]) {
            total += tree.query(j);
            if (total >= want[i]) break;
        }
        if (total >= want[i]) {
            ans[i] = mid;
            finished.push_back(i);
        } else {
            unfinished.push_back(i);
        }
    }
    vector<int>().swap(owners);
    if (L < R) {
        rec(L, mid, finished);
        rec(mid+1, R, unfinished);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int j;
        cin >> j;
        pos[j].push_back(i);
    }
    vector<int> owners;
    for (int i = 1; i <= n; ++i) {
        cin >> want[i];
        ans[i] = -1;
        owners.push_back(i);
    }
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> qL[i] >> qR[i] >> qVal[i];
    }
    queriesDone = 0;
    rec(1, q, owners);
    for (int i = 1; i <= n; ++i) {
        if (ans[i] == -1) {
            cout << "NIE\n";
        } else {
            cout << ans[i] << '\n';
        }
    }
}
