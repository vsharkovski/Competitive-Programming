#include <bits/stdc++.h>
using namespace std;

struct PersTree {
    struct Node {
        Node *l, *r;
        int sum;
        Node() : l(nullptr), r(nullptr), sum(0) {}
        Node(int sum) : l(nullptr), r(nullptr), sum(sum) {}
        Node(Node *l, Node *r) : l(l), r(r), sum(0) {
            if (l) sum += l->sum;
            if (r) sum += r->sum;
        }
    };
    vector<Node*> roots;
    Node* build(int tl, int tr) {
        if (tl == tr) return new Node(0);
        int tm = (tl + tr) / 2;
        return new Node(build(tl, tm), build(tm+1, tr));
    }
    Node* update(Node *v, int tl, int tr, int pos) {
        if (tl == tr) return new Node(v->sum + 1);
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            return new Node(update(v->l, tl, tm, pos), v->r);
        } else {
            return new Node(v->l, update(v->r, tm+1, tr, pos));
        }
    }
    int query(Node *v1, Node *v2, int tl, int tr, int k) {
        if (tl == tr) return tl;
        int tm = (tl + tr) / 2;
        int lcnt = v2->l->sum - v1->l->sum;
        if (k <= lcnt) {
            return query(v1->l, v2->l, tl, tm, k);
        } else {
            return query(v1->r, v2->r, tm+1, tr, k - lcnt);
        }
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<int> arr2 = arr;
    sort(arr2.begin(), arr2.end());
    vector<int> old_id;
    unordered_map<int, int> new_id;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || arr2[i] != arr2[i-1]) {
            new_id[arr2[i]] = old_id.size();
            old_id.push_back(arr2[i]);
        }
    }
    PersTree tree;
    tree.roots.push_back(tree.build(0, n-1));
    for (int i = 1; i <= n; ++i) {
        tree.roots.push_back(tree.update(tree.roots[i-1], 0, n-1, new_id[arr[i-1]]));
    }
    for (int q = 1; q <= m; ++q) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << old_id[tree.query(tree.roots[l-1], tree.roots[r], 0, n-1, k)] << '\n';
    }
}
