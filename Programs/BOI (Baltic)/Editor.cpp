#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;

struct PersTree {
    // simple persistent segment tree
    struct Node {
        Node *l, *r;
        int minval;
        Node() : l(nullptr), r(nullptr), minval(maxn) {}
        Node(int val) : l(nullptr), r(nullptr), minval(val) {}
        Node(Node *l, Node *r) : l(l), r(r), minval(maxn) {
            if (l) minval = min(minval, l->minval);
            if (r) minval = min(minval, r->minval);
        }
    };
    Node* roots[maxn];
    Node* build(int tl, int tr) {
        if (tl == tr) return new Node();
        int tm = (tl + tr) / 2;
        return new Node(build(tl, tm), build(tm+1, tr));
    }
    Node* update(Node* v, int tl, int tr, int pos, int val) {
        if (tl == tr) return new Node(val);
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            return new Node(update(v->l, tl, tm, pos, val), v->r);
        } else {
            return new Node(v->l, update(v->r, tm+1, tr, pos, val));
        }
    }
    // find max. pos with val < wanted val
    int find(Node* v, int tl, int tr, int val) {
        if (tl == tr) return tl;
        int tm = (tl + tr) / 2;
        if (v->r->minval < val) {
            return find(v->r, tm+1, tr, val);
        } else {
            return find(v->l, tl, tm, val);
        }
    }
} tree;

int n;
int ans[maxn];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    ans[0] = 0;
    tree.roots[0] = tree.build(1, n);
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        if (a > 0) {
            // state now = the state right before
            // (but also add this action)
            ans[i] = a;
            tree.roots[i] = tree.update(tree.roots[i-1], 1, n, i, 0);
        } else {
            a = -a;
            // state now = the state BEFORE the action we are undoing
            // (but also add this action)
            int j = tree.find(tree.roots[i-1], 1, n, a) - 1;
            ans[i] = ans[j];
            tree.roots[i] = tree.update(tree.roots[j], 1, n, i, a);
        }
        cout << ans[i] << '\n';
    }
}
